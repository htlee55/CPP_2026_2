#include <iostream>
#include <vector>
using namespace std;

class Circle {
private:
    int x, y, radius;
public:
    Circle(int x, int y, int r) : x{x}, y{y}, radius{r} {}
    void print() const {
        cout << "위치: (" << x << ", " << y
             << "), 반지름: " << radius << '\n';
    }
};

int main() {
    vector<Circle> circles;
    int x, y, r;

    while (true) {
        cout << "x y radius 입력 (종료: -1 0 0): ";
        if (!(cin >> x >> y >> r) || x == -1) break;
        if (r <= 0) {
            cout << "반지름은 양수여야 합니다.\n";
            continue;
        }
        circles.push_back(Circle(x, y, r));
    }

    cout << "원의 개수: " << circles.size() << '\n';
    for (const Circle& c : circles) c.print();
}
