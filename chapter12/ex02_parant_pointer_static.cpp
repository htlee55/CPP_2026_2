// 부모 포인터와 정적 바인딩
#include <iostream>

class Spaceship {
public:
    void show() const {  // virtual 없음
        std::cout << "부모 우주선\n";
    }
};

class Enemy : public Spaceship {
public:
    void show() const {
        std::cout << "적 우주선\n";
    }
};

int main() {
    Enemy e;

    e.show();              		// 적 우주선
    Enemy* p1 = &e;
    p1->show();            	// 적 우주선
    Spaceship* p2 = &e;  	// 부모 포인터로 자식 객체를 가리킴
    p2->show();            	// 부모 우주선: 비가상 함수는 정적 자료형 기준
}
