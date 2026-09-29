#include <iostream>
using namespace std;

class Rectangle {
	public:
		int width;
		int height;

		int calcArea() {
			return width * height;
		}
};

int main() {
	Rectangle rect;
	rect.width = 5;
	rect.height = 10;
	cout << "Area of rectangle: " << rect.calcArea() << endl;
	return 0;
}
