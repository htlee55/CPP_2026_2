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
	LunarLander(double h, double v, double f);	// 생성자 함수 원형, 
	bool checkLanded();							// 착륙했는지를 검사하는 함수 원형
	bool checkCrashed();						// 충돌했는지를 검사하는 함수 원형
	void update(double rate);					// 게임 상태를 업데이트하는 함수 원형
	void draw(RenderWindow& window);			// 화면에 착륙선과 불꽃, 현재 상태를 그리는 함수 원형
};
// 생성자 함수
LunarLander::LunarLander(double h, double v, double f) {
	x = 300;
	y = h;
	velocity = v;
	fuel = f;
	t1.loadFromFile("images/spaceship.png");
	t2.loadFromFile("images/burst.png");
	spaceship.setTexture(t1);		// 착륙선 스프라이트에 텍스처를 설정한다.
	burst.setTexture(t2);			// 불꽃 스프라이트에 텍스처를 설정한다.
	spaceship.setPosition(x, y);	// 착륙선 스프라이트의 위치를 설정한다.
	burst.setPosition(x + 20, y + 50);	// 불꽃 스프라이트의 위치를 설정한다.
	if (!font.loadFromFile("OpenSans-Bold.ttf")) {		// 폰트 파일을 오픈한다.
		cout << "폰트 파일을 오픈할 수 없음!" << endl;
	}
	text.setFont(font);				// 텍스트 객체에 폰트를 설정한다.
}
// 착륙했는지를 검사하는 함수. 만약 높이가 0보다 작으면 착륙한 것이다. 
bool LunarLander::checkLanded() {
	if (y >= 450)
		return true;
	return false;
}
bool LunarLander::checkCrashed() {
	if (y >= 450 && velocity > 5.0)
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
	RenderWindow window(VideoMode(600, 480), "LUNAR LANDER");		// SFML 윈도우 객체 생성
	window.setFramerateLimit(60);			// 초당 프레임 수를 60으로 제한한다.

	Texture t;								// 텍스처 객체 생성
	Sprite background;						// 스프라이트 객체 생성
	t.loadFromFile("images/background.png");	// 텍스처에 배경 이미지를 로드한다.
	background.setTexture(t);					// 스프라이트에 텍스처를 설정한다.

	LunarLander lander(300.0, 1.0, 100.0);	// 착륙선 객체 생성		
	while (window.isOpen()) {				// 윈도우가 열려 있는 동안 반복
		Event e;
		while (window.pollEvent(e)) {		// 이벤트가 발생했는지 검사
			if (e.type == Event::Closed)
				window.close();
		}

		if (Keyboard::isKeyPressed(Keyboard::Up))	// 만약 위쪽 화살표 키가 눌렸다면
			lander.update(3.0);				// 연료를 3만큼 소모하며 게임 상태를 업데이트한다.
		else
			lander.update(0.0);				// 연료를 소모하지 않고 게임 상태를 업데이트한다.
		// 착륙 여부 확인	
		if(lander.checkLanded()) {
			if(lander.checkCrashed())
					cout << "충돌!" << endl;
			else
				cout << "착륙 완료!" << endl;
				window.close();					// 윈도우를 닫는다.
		}

		window.clear();
		window.draw(background);
		lander.draw(window);

		window.display();
		Sleep(100);		// 0.1초 동안 잠재운다. 
	}
	return 0;
}

