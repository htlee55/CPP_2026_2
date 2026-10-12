#include <iostream>
using namespace std;

class Circle {
private:
    int x, y, radius;
public:
    Circle(int x, int y, int r) : x{x}, y{y}, radius{r} {}
    void print() const {
        cout << "(" << x << ", " << y << "), r=" << radius << '\n';
    }
};

int main() {
    Circle circles[3] = {
        Circle(100, 100, 30),
        Circle(200, 150, 40),
        Circle(300, 200, 50)
    };

    cout << "인덱스 반복문:\n";
    for (int i = 0; i < 3; ++i) circles[i].print();

    cout << "범위 기반 for문:\n";
    for (const Circle& c : circles) c.print();
}
