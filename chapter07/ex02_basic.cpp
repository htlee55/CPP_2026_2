#include <SFML/Graphics.hpp>
using namespace sf;

int main()
{
	RenderWindow window(VideoMode(600, 480), "LUNAR LANDER");
	window.setFramerateLimit(60);

	// 게임에 필요한 스프라이트를 생성한다. 
	Texture t2;
	Sprite lander;
	t2.loadFromFile("images/spaceship.png");
	lander.setTexture(t2);
	while (window.isOpen())		// 게임 루프
	{
		// 이벤트 검사 및 처리
		Event e;
		while (window.pollEvent(e)) {
			if (e.type == Event::Closed)
				window.close();
		}
		// 화면을 지운다. 
			window.clear();
		// 화면에 스프라이트를 그린다. 
		window.draw(lander);
		// 화면을 표시한다. 
		window.display();
	}
	return 0;
}

