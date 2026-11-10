#include <iostream>
#include <string>
using namespace std;

class Base {
public:
	int a = 1;
protected:
	int b = 2;
private:
	int c = 3;
};

class Derived : public Base {
public:
	void show() {
		cout << "a: " << a << endl; // 접근 가능
		cout << "b: " << b << endl; // 접근 가능
		//cout << "c: " << c << endl; // 접근 불가, private 멤버이므로 오류 발생
	}
};

int main() {
	Derived obj;
	obj.show();
	return 0;
}
