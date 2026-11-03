#include <iostream>
using namespace std;
void addTen(int* p) {
    if (p != nullptr) *p += 10;
}
int main() {
    int score = 50;
    addTen(&score);
    cout << "score = " << score << '\n';
}
