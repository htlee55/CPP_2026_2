// 부모 포인터로 삭제 시 가상 소멸자

#include <iostream>
#include <memory>
class Spaceship {
public:
    virtual ~Spaceship() { std::cout << "부모 소멸자 호출\n"; }
    virtual void update(float dt) = 0;
};

class Enemy : public Spaceship {
public:
    void update(float) override {}
    ~Enemy() override { std::cout << "자식 소멸자 호출\n"; }
};
int main() {
	std::unique_ptr<Spaceship> ship = std::make_unique<Enemy>();    // 부모 포인터로 자식 객체를 가리킴   
    // 블록 종료: 자식 소멸자 -> 부모 소멸자 순서로 호출
}
