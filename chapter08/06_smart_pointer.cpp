#include <iostream>
#include <memory>
using namespace std;
class Spaceship {
    int x;
public:
    Spaceship(int initialX) : x(initialX) {
        cout << "Constructor\n";
    }
    ~Spaceship() { cout << "Destructor (automatic)\n"; }
    void move(int dx) { x += dx; }
    int getX() const { return x; }
};
int main() {
    auto ship = make_unique<Spaceship>(100);
    ship->move(20);
    cout << ship->getX() << '\n';
    // no explicit delete: unique_ptr manages lifetime
}
