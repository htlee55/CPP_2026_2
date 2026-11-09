#include <SFML/Graphics.hpp>
#include <windows.h>
#include <string>
#include <vector>
#include <iostream>
#include "lunarlander.hpp"
using namespace sf;
using namespace std;

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

