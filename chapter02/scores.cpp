#include <iostream>
using namespace std;

int main() {
    constexpr int N{5};
    int scores[N]{};

    // 성적 입력
    for (int i{0}; i < N; ++i) {
        cout << i + 1 << "번 성적: ";
        cin >> scores[i];
    }

    // 합계 계산
    int sum{0};

    for (int i{0}; i < N; ++i) {
        sum += scores[i];
    }

    // 평균 계산
    double avg{
        static_cast<double>(sum) / N
    };

    cout << "합계: " << sum << '\n';
    cout << "평균: " << avg << '\n';

    return 0;
}
