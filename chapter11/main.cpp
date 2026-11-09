#include <iostream>
using namespace std;

class Spaceship {
    int x;
public:
    explicit Spaceship(int startX) : x(startX) {
        cout << "Spaceship constructor: " << x << '\n';
    }
    ~Spaceship() { cout << "Spaceship destructor\n"; }
};

class Enemy : public Spaceship {
public:
    explicit Enemy(int startX) : Spaceship(startX) {
        cout << "Enemy constructor\n";
    }
    ~Enemy() { cout << "Enemy destructor\n"; }
};

int main() {
    cout << "-- create --\n";
    Enemy enemy(100);
    cout << "-- end of scope --\n";
}
