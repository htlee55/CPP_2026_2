// virtual이 없는 경우 - 부모 포인터로 호출

#include <iostream>
class Spaceship {
public:
    void show() { std::cout << "Spaceship::show() - 부모 동작\n"; }
};
class Enemy : public Spaceship {
public:
    void show() { std::cout << "Enemy::show() - 적 동작\n"; }
};
int main() {
    Enemy enemy;
    Spaceship* p = &enemy;
    p->show();       // Spaceship::show() 호출: 정적 바인딩
    enemy.show();    // Enemy::show() 호출
}
