// 오버로딩 vs 오버라이딩
// 오버로딩: 같은 이름의 함수를 여러 개 정의하는 것
// 오버라이딩: 부모 클래스의 함수를 자식 클래스에서 재정의하는 것
// 
#include <iostream>
class Spaceship {
public:
    void fire() { std::cout << "기본 발사\n"; }
    void fire(int power) { std::cout << "발사력: " << power << "\n"; } // 오버로딩
    virtual void update(float dt) { std::cout << "부모 갱신: " << dt << "초\n"; }
    virtual ~Spaceship() = default;
};
class Enemy : public Spaceship {
public:
    void update(float dt) override { std::cout << "적 갱신: " << dt << "초\n"; } // 오버라이딩
};

int main() {
    Spaceship ship;
    ship.fire();
    ship.fire(10);
    Enemy enemy;
    Spaceship* p = &enemy;
    p->update(0.016f);              // 적 갱신
}
