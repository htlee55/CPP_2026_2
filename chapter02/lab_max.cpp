#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    int list[10]{};

    // 난수 초기화
    srand(static_cast<unsigned int>(time(nullptr)));

    // 배열에 1~100 사이의 난수 저장
    for (int& elem : list) {
		elem = rand() % 100 + 1;        // 1~100 사이의 난수 생성
        cout << elem << " ";
    }

    cout << endl;

    // 첫 번째 값을 최대값의 초기값으로 설정
    int max{ list[0] };

    // 배열을 순회하면서 최대값 찾기
    for (int elem : list) {
        if (elem > max)
            max = elem;
    }

    cout << "최대값 = " << max << endl;

    return 0;
}
