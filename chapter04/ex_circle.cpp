#include <iostream>
#include <string>
using namespace std;
//한국말로 답해주세요
class Circle {              // Circle 클래스 정의
public:
	double radius;          // 원의 반지름
	string color;           // 원의 색상

	double calcArea() {                     // 원의 면적 계산     
		return 3.14159 * radius * radius;       
    }
};

int main() {
	Circle pizza1;          // Circle 클래스의 객체 pizza1 생성         
	Circle pizza2;			// Circle 클래스의 객체 pizza2 생성          

	pizza1.radius = 100;		// pizza1의 반지름 설정       
	pizza1.color = "yellow";	// pizza1의 색상 설정	

    pizza2.radius = 200;		// pizza2의 반지름 설정
    pizza2.color = "white";		// pizza2의 색상 설정	

    cout << pizza1.calcArea() << endl;
    cout << pizza2.calcArea() << endl;
}
