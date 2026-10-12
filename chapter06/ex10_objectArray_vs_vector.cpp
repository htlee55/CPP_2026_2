#include <iostream>
#include <vector>
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
    Circle a[2] = {Circle(100, 100, 30), Circle(200, 150, 40)};
    vector<Circle> v;
    v.push_back(Circle(100, 100, 30));
    v.push_back(Circle(200, 150, 40));

    cout << "객체 배열:\n";
    for (const Circle& c : a) c.print();

    cout << "객체 벡터:\n";
    for (const Circle& c : v) c.print();
    v.push_back(Circle(300, 200, 50));
    cout << "추가 후 vector 크기: " << v.size() << '\n';
}
