#include <iostream>
using namespace std;

class Enemy
{
public:
    float x;
    float y;
    float speed;

    void move()
    {
        x += speed;
    }

    void show()
    {
        cout << x << ", " << y << endl;
    }
};

int main()
{
    Enemy enemy1;
    Enemy enemy2;

    enemy1.x = 10;
    enemy1.y = 20;
    enemy1.speed = 2;

    enemy2.x = 30;
    enemy2.y = 40;
    enemy2.speed = 3;

    enemy1.move();
    enemy2.move();

    enemy1.show();
    enemy2.show();

    return 0;
}
