#include <iostream>
using namespace std;

class Spaceship {
public:
    void show() const { cout << "Spaceship::show\n"; }
};
class Enemy : public Spaceship {
public:
    void show() const { cout << "Enemy::show\n"; }
};
int main() {
    Enemy enemy;
    enemy.show();           // Enemy::show
    enemy.Spaceship::show(); // 기본 클래스 함수 명시 호출

    Spaceship* ptr = &enemy;
    ptr->show();            // Spaceship::show (비가상 함수)
    // 질문: 다음 주에 virtual을 사용하면 무엇이 달라질까요?
}
