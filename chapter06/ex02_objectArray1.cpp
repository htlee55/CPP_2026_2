#include <iostream>
using namespace std;

class Circle {
private:
    int x, y, radius;
public:
    Circle() : x{0}, y{0}, radius{0} {
        cout << "기본 생성자 호출\n";
    }
    Circle(int x, int y, int r) : x{x}, y{y}, radius{r} {
        cout << "매개변수 생성자 호출\n";
    }
};

int main() {
    Circle circles[3];  // 기본 생성자가 각 원마다 한 번씩 호출됨

    // 연습: Circle() 생성자를 주석 처리한 후 빌드하면 어떤 오류가 발생할까요?
    // 확인 후 주석을 복원하면 이 예제는 다시 정상 실행됩니다.
}
