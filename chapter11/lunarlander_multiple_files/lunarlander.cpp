#include "lunarlander.hpp"
#include <iostream>

// 생성자 함수
LunarLander::LunarLander(float h, float v, float f) {
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
		std::cout << "폰트 파일을 오픈할 수 없음!" << std::endl;
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
void LunarLander::update(float amount) {
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
	status = "Press up key!\nheight: " + std::to_string(y) + "\nspeed: " + std::to_string(velocity) + "\nfuel: " + std::	to_string(fuel);
}

// 화면에 착륙선과 불꽃, 현재 상태를 그린다. 
void LunarLander::draw(sf::	RenderWindow& window) {
	window.draw(spaceship);
	window.draw(burst);
	text.setString(status);
	text.setCharacterSize(20);
	text.setPosition(10, 100);
	window.draw(text);
}
