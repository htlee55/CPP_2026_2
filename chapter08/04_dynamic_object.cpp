#include <iostream>
using namespace std;
class Spaceship {
    int x;
public:
    explicit Spaceship(int initialX) : x(initialX) {
        cout << "Constructor: x=" << x << '\n';
    }
    ~Spaceship() { cout << "Destructor\n"; }
    void move(int dx) { x += dx; }
    int getX() const { return x; }
};
int main() {
    Spaceship* p = new Spaceship(100);
    p->move(50);
    cout << "Current x=" << p->getX() << '\n';
    delete p;            // must match new
    p = nullptr;         // prevent accidental reuse
}
