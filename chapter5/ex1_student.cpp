#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    string name;
    int age;

    void introduce(){
        cout << name << " " <<  age << endl;
    }
};

int main() {
    Student s1;
    s1.name = "Kim";
    s1.age = 20;
    s1.introduce();

    Student s2;
    s2.name = "Lee";
    s2.age = 21;
    s2.introduce();
}
