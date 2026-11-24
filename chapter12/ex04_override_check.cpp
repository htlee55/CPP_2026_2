// override가 함수 원형의 실수를 잡아 주는 예
// 기본 상태는 컴파일됩니다. 아래 #if 0을 #if 1로 바꾸어 오류 확인.
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
#if 0
    void show() override { // 오류! 부모 show()는 const 멤버 함수
        std::cout << "적 우주선\n";
    }
#else
    void show() const override { // 정상: 부모와 함수 원형 일치
        std::cout << "적 우주선\n";
    }
#endif
};

int main() {
    Enemy e;
    Spaceship* p = &e;
    p->show();
}
