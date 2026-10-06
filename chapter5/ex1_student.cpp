#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    string name;
    int age;
};

int main() {
    Student s;
    cout << s.name << endl;
    cout << s.age << endl;
}
