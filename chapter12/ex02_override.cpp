// virtual + override - 실제 객체의 함수 호출

#include <iostream>
class Spaceship {
public:
    virtual void show() { std::cout << "Spaceship::show() - 부모 동작\n"; }
    virtual ~Spaceship() = default;
};
class Enemy : public Spaceship {
public:
    void show() override { std::cout << "Enemy::show() - 적 동작\n"; }
};
int main() {
    Enemy enemy;
    Spaceship* p = &enemy;
    p->show();       // Enemy::show() 호출: 동적 바인딩
}
