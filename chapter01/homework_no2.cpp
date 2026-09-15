#include <iostream>
using namespace std;

int main()
{
    int age;

    cout << "현재 나이를 입력하세요: ";
    cin >> age;

    int futureAge = age + 10;

    cout << "10년 후 나이는 " << futureAge << "세입니다." << endl;

    return 0;
}
