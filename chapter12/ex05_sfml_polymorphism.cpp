// SFML 우주선 게임을 다형성으로 확장
// Visual Studio 2022 / C++17 / SFML 2.x
#include <SFML/Graphics.hpp>
#include <vector>

// 공통 데이터와 공통 동작을 부모 클래스에 정의
class Spaceship {
protected:
    sf::CircleShape shape;
    float speed;

public:
    Spaceship(float x, float y, float s) : speed(s) {
        shape.setRadius(19.f);
        shape.setOrigin(19.f, 19.f);
        shape.setPosition(x, y);
        shape.setFillColor(sf::Color::White);
    }

    void move(float dx, float dy) {
        shape.move(dx * speed, dy * speed);
    }

    sf::Vector2f position() const {
        return shape.getPosition();
    }

    void draw(sf::RenderWindow& window) const {
        window.draw(shape); // 공통 그리기 코드를 그대로 재사용
    }

    virtual void update() = 0; // 자식마다 다른 이동 규칙
    virtual ~Spaceship() = default;
};

class PlayerSpaceship : public Spaceship {
public:
    PlayerSpaceship(float x, float y) : Spaceship(x, y, 4.0f) {
        shape.setFillColor(sf::Color(60, 220, 130));
    }

    void update() override {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))  move(-1.f, 0.f);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) move(1.f, 0.f);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))    move(0.f, -1.f);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))  move(0.f, 1.f);
    }
};

class EnemySpaceship : public Spaceship {
public:
    EnemySpaceship(float x, float y) : Spaceship(x, y, 1.6f) {
        shape.setFillColor(sf::Color(240, 90, 90));
    }

    void update() override {
        move(0.f, 1.f);
        if (position().y > 620.f) {
            shape.setPosition(position().x, -20.f);
        }
    }
};

// 11주차과제: 새 적 우주선 한 종류 추가
class FastEnemy : public Spaceship {
public:
    FastEnemy(float x, float y) : Spaceship(x, y, 3.0f) {
        shape.setFillColor(sf::Color::Yellow);
    }

    void update() override {
        move(0.f, 1.f);
        if (position().y > 620.f) {
            shape.setPosition(position().x, -20.f);
        }
    }
};

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Week 13 - Polymorphism");
    window.setFramerateLimit(60);

    PlayerSpaceship player(400.f, 520.f);
    EnemySpaceship enemy(320.f, 30.f);
    FastEnemy fastEnemy(500.f, 30.f);

    // 서로 다른 자식 객체를 부모 포인터로 함께 관리
    // 객체는 main()에서 생성되며, ships는 객체를 소유하지 않음
    std::vector<Spaceship*> ships = { &player, &enemy, &fastEnemy };

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        for (Spaceship* p : ships) {
            p->update(); // 가상 함수: 실제 자식 객체에 맞는 update() 호출
        }

        window.clear(sf::Color(16, 25, 42));
        for (Spaceship* p : ships) {
            p->draw(window); // 비가상 함수: 부모의 공통 draw() 재사용
        }
        window.display();
    }
}
