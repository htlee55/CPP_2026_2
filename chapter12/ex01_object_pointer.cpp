// 객체 호출과 객체 포인터

#include <iostream>

class Spaceship {
public:
    void show() const {
        std::cout << "우주선 출력\n";
    }
};

int main() {
    Spaceship s;
    s.show();                 // 객체로 호출: .

    Spaceship* p = &s;       // 객체 s의 주소 저장
    p->show();               // 포인터로 호출: ->
    (*p).show();             // p->show()와 같은 의미
}
