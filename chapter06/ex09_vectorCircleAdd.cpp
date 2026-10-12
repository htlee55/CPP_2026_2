#include <iostream>
#include <vector>
using namespace std;

class Circle {
private:
    int x, y, radius;
public:
    Circle(int x, int y, int r) : x{x}, y{y}, radius{r} {}
    void print() const {
        cout << "위치: (" << x << ", " << y << "), 반지름: " << radius << '\n';
    }
};

int main() {
    vector<Circle> circles;
    circles.push_back(Circle(100, 100, 30));
    circles.push_back(Circle(200, 150, 40));
    circles.push_back(Circle(300, 200, 50));

    cout << "원의 개수: " << circles.size() << '\n';
    for (const Circle& c : circles) c.print();
}
