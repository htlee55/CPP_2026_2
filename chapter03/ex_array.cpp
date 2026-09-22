#include <iostream>
#include <string>
using namespace std;

int main()
{
	string list[] = { "철수", "영희", "길동" };

	for (auto& x : list)
		cout << (x + "야 안녕!") << endl;
	return 0;
}
