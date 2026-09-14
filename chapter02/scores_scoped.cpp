#include <iostream>
using namespace std;

int main() {
    constexpr int N{5};
    int scores[N]{};

    // 성적 입력
    int number{1};

    for (int& score : scores) {
        cout << number << "번 성적: ";
        cin >> score;
        ++number;
    }

    // 합계 계산
    int sum{0};

    for (int score : scores) {
        sum += score;
    }

    // 평균 계산
    double avg{
        static_cast<double>(sum) / N
    };

    cout << "합계: " << sum << '\n';
    cout << "평균: " << avg << '\n';

    return 0;
}
