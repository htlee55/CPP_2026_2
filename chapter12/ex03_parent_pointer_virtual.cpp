// virtual과 동적 바인딩

#include <iostream>

class Spaceship {
public:
    virtual void show() const {
        std::cout << "부모 우주선\n";
    }
    virtual ~Spaceship() = default;
};

class Enemy : public Spaceship {
public:
    void show() const override {
        std::cout << "적 우주선\n";
    }
};

int main() {
    Enemy e;

    e.show();              // 적 우주선
    Enemy* p1 = &e;
    p1->show();            // 적 우주선
    Spaceship* p2 = &e;
    p2->show();            // 적 우주선: 실제 객체의 함수 호출
}

