#include <iostream>
using namespace std;

int main()
{
    float enemy1_x = 10;
    float enemy1_y = 20;
    float enemy1_speed = 2;

    float enemy2_x = 30;
    float enemy2_y = 40;
    float enemy2_speed = 3;

    // 적 이동
    enemy1_x += enemy1_speed;
    enemy2_x += enemy2_speed;

    cout << "Enemy1: " << enemy1_x << ", " << enemy1_y << endl;
    cout << "Enemy2: " << enemy2_x << ", " << enemy2_y << endl;
}
