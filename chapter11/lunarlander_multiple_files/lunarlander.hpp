#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class LunarLander {
private:
	float x, y;		// 현재 위치
	float velocity;	// 속도
	float fuel;		// 연료
	std::string status;		// 현재 상태
	sf::Texture t1, t2;		// 텍스처 객체
	sf::Sprite spaceship, burst;	// 스프라이트 객체
	sf::Font font;		// 폰트 객체
	sf::Text text;		// 텍스트 객체
public:
	LunarLander(float h, float v, float f);	// 생성자 함수 원형, 
	bool checkLanded();							// 착륙했는지를 검사하는 함수 원형
	bool checkCrashed();						// 충돌했는지를 검사하는 함수 원형
	void update(float rate);					// 게임 상태를 업데이트하는 함수 원형
	void draw(sf::RenderWindow& window);			// 화면에 착륙선과 불꽃, 현재 상태를 그리는 함수 원형
};


