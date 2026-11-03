#include <iostream>
using namespace std;
int main() {
    int number = 10;
    int* p = &number;
    cout << "number = " << number << '\n';
    cout << "&number = " << &number << '\n';
    cout << "p = " << p << '\n';
    cout << "*p = " << *p << '\n';
    *p = 20;
    cout << "After *p = 20, number = " << number << '\n';
    p = nullptr;
    if (p == nullptr) cout << "p points to nothing.\n";
}
