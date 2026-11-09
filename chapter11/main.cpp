#include <SFML/Graphics.hpp>

// 공통 데이터와 공통 동작을 Spaceship에 배치합니다.
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
    void move(float dx, float dy) { shape.move(dx * speed, dy * speed); }
    void draw(sf::RenderWindow& window) const { window.draw(shape); }
    sf::Vector2f position() const { return shape.getPosition(); }
};

class PlayerSpaceship : public Spaceship {
public:
    PlayerSpaceship(float x, float y) : Spaceship(x, y, 4.0f) {
        shape.setFillColor(sf::Color(60, 220, 130));
    }
    void update() {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) move(-1.f, 0.f);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) move(1.f, 0.f);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) move(0.f, -1.f);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) move(0.f, 1.f);
    }
};

class EnemySpaceship : public Spaceship {
public:
    EnemySpaceship(float x, float y) : Spaceship(x, y, 1.6f) {
        shape.setFillColor(sf::Color(240, 90, 90));
    }
    void update() {
        move(0.f, 1.f);
        if (position().y > 620.f) shape.setPosition(position().x, -20.f);
    }
};

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Week 11 - Inheritance");
    window.setFramerateLimit(60);
    PlayerSpaceship player(400.f, 520.f);
    EnemySpaceship enemy(320.f, 30.f);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
        }
        player.update();
        enemy.update();
        window.clear(sf::Color(16, 25, 42));
        player.draw(window);
        enemy.draw(window);
        window.display();
    }
}
