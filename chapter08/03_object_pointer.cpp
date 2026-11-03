#include <iostream>
using namespace std;
class Spaceship {
    int x;
public:
    explicit Spaceship(int initialX) : x(initialX) {}
    void move(int dx) { x += dx; }
    int getX() const { return x; }
};
int main() {
    Spaceship ship(100);
    Spaceship* p = &ship;  // existing object: no new/delete
    ship.move(10);
    (*p).move(20);
    p->move(30);
    cout << "ship.x = " << ship.getX() << '\n'; // 160
}
