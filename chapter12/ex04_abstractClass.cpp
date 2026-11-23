// 순수 가상함수와 자식별 update 구현
// 
#include <iostream>
#include <memory>
#include <vector>

class Spaceship {
protected:
    float x, y, speed;
    Spaceship(float startX, float startY, float moveSpeed)
        : x(startX), y(startY), speed(moveSpeed) {
    }
public:
    virtual ~Spaceship() = default;
    virtual void update(float dt) = 0;      // 순수 가상함수: 직접 생성 불가
    void draw() const { std::cout << "위치: (" << x << ", " << y << ")\n"; }
};

class EnemySpaceship : public Spaceship {
public:
    EnemySpaceship(float x, float y) : Spaceship(x, y, 80.f) {}
    void update(float dt) override { y += speed * dt; }
};

class FastEnemy : public Spaceship {
public:
    FastEnemy(float x, float y) : Spaceship(x, y, 150.f) {}
    void update(float dt) override { x += 40.f * dt; y += speed * dt; }
};

int main() {
    // Spaceship ship; // 오류: 추상 클래스 직접 생성 불가
    std::vector<std::unique_ptr<Spaceship>> ships;
    ships.push_back(std::make_unique<EnemySpaceship>(130.f, 30.f));
    ships.push_back(std::make_unique<FastEnemy>(570.f, 40.f));
    for (auto& ship : ships) { ship->update(1.f); ship->draw(); }
}
