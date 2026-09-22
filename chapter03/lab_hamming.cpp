#include <iostream>
#include <string>
using namespace std;

int main() {
	string s1, s2;
	int count = 0;

	cout << "DNA1: ";
	cin >> s1;
	cout << "DNA2: ";
	cin >> s2;

	if (s1.length() != s2.length())
		cout << "오류: 길이가 다름" << endl;
	else {
		for (int i = 0; i < s1.length(); i++) {
			if (s1[i] != s2[i])
				count += 1;
		}
		cout << "해밍 거리는 " << count << endl;
	}
	return 0;
}
