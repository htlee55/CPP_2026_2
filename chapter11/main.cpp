#include <iostream>
using namespace std;

// 1단계: 기본 클래스의 기능을 파생 클래스가 재사용합니다.
class Spaceship {
protected:
    int x;
public:
    explicit Spaceship(int startX) : x(startX) {}
    void move(int dx) { x += dx; }
    void show() const { cout << "Position: " << x << '\n'; }
};

class Enemy : public Spaceship {
public:
    explicit Enemy(int startX) : Spaceship(startX) {}
    void attack() const { cout << "Enemy attacks!\n"; }
};

int main() {
    Enemy enemy(100);
    enemy.move(20);  // 기본 클래스의 함수
    enemy.show();    // 기본 클래스의 함수
    enemy.attack();  // 파생 클래스의 함수
}
