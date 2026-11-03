#include <iostream>
using namespace std;
void addTen(int* p) {
    *p += 10;
}
int main() {
    int score = 50;
    addTen(&score);
    cout << "score = " << score << '\n';
}
