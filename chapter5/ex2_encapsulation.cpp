#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    string name;
    int age;

    Student() {
        cout << "기본 생성자 호출" << endl;
	}

	Student(string n, int a) {    // 생성자 초기화 리스트를 사용하여 멤버 변수를 초기화합니다.
		name = n;
		setAge(a);
		cout << ".생성자 호출 " << name << endl;
    }
    ~Student() {    // 소멸자
		cout << "소멸자 호출 " << name << endl;   
	}

    void setAge(int a) {
        if(a >= 0 && a <= 150) {
            age = a;
        } else {
            cout << "나이는 0에서 150 사이여야 합니다." << endl;
		}
	}

    int getAge() {
        return age;
	}

    string getName() {
        return name;
    }

    void introduce() {
        cout << name << " " << age << endl;
    }
};

int main() {
  Student s("Kim", 20);
	Student b{ "Lee", 22 }; 
	Student c{ "Park", -25 };    
  s.introduce();
	b.introduce();
	c.introduce();
}
