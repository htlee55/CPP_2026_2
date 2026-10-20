#include <SFML/Graphics.hpp>
#include <windows.h>
#include <string>
#include <vector>
#include <iostream>
using namespace sf;
using namespace std;

class LunarLander {
private:
	double x, y;		// 현재 위치
	double velocity;	// 속도
	double fuel;		// 연료
	string status;		// 현재 상태
	Texture t1, t2;		// 텍스처 객체
	Sprite spaceship, burst;	// 스프라이트 객체
	Font font;		// 폰트 객체
	Text text;		// 텍스트 객체
public:
	LunarLander(double h, double v, double f);	// 생성자
	bool checkLanded();
	void update(double rate);
	void draw(RenderWindow& window);
};
// 생성자 함수
LunarLander::LunarLander(double h, double v, double f) {
	x = 300;
	y = h;
	velocity = v;
	fuel = f;
	t1.loadFromFile("images/spaceship.png");
	t2.loadFromFile("images/burst.png");
	spaceship.setTexture(t1);
	burst.setTexture(t2);
	spaceship.setPosition(x, y);
	burst.setPosition(x + 20, y + 50);
	if (!font.loadFromFile("OpenSans-Bold.ttf")) {
		cout << "폰트 파일을 오픈할 수 없음!" << endl;
	}
	text.setFont(font);
}
// 착륙했는지를 검사하는 함수. 만약 높이가 0보다 작으면 착륙한 것이다. 
bool LunarLander::checkLanded() {
	if (y <= 0)
		return true;
	return false;
}

// 게임 상태를 업데이트한다. 
void LunarLander::update(double amount) {
	if (fuel <= 0) {
		fuel = 0;
		amount = 0;
	}
	fuel = fuel - amount;
	velocity = velocity - amount + 0.8;
	y = y + velocity;
	if (y > 450) y = 450;
	spaceship.setPosition(x, y);
	burst.setPosition(x + 20, y + 50);
	status = "Press up key!\nheight: " + to_string(y) + "\nspeed: " + to_string(velocity) + "\nfuel: " + to_string(fuel);
}

// 화면에 착륙선과 불꽃, 현재 상태를 그린다. 
void LunarLander::draw(RenderWindow& window) {
	window.draw(spaceship);
	window.draw(burst);
	text.setString(status);
	text.setCharacterSize(20);
	text.setPosition(10, 100);
	window.draw(text);
}

int main()
{
	RenderWindow window(VideoMode(600, 480), "LUNAR LANDER");
	window.setFramerateLimit(60);

	Texture t;
	Sprite background;
	t.loadFromFile("images/background.png");
	background.setTexture(t);

	LunarLander lander(300.0, 1.0, 100.0);	// 착륙선 객체 생성
	while (window.isOpen()) {
		Event e;
		while (window.pollEvent(e)) {
			if (e.type == Event::Closed)
				window.close();
		}

		if (Keyboard::isKeyPressed(Keyboard::Up))
			lander.update(3.0);
		else
			lander.update(0.0);

		window.clear();
		window.draw(background);
		lander.draw(window);

		window.display();
		Sleep(100);		// 0.1초 동안 잠재운다. 
	}
	return 0;
}

