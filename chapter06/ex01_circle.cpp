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
    Circle c1(100, 100, 30);
    Circle c2(200, 150, 40);
    Circle c3(300, 200, 50);
    c1.print();
    c2.print();
    c3.print();
}
