#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> scores;
    int score;
    cout << "점수를 입력하세요(종료: -1): ";
    while (cin >> score && score != -1) {
        scores.push_back(score);
    }

    int sum = 0;
    for (int x : scores) sum += x;

    if (!scores.empty()) {
        cout << "학생 수: " << scores.size() << '\n';
        cout << "평균: " << static_cast<double>(sum) / scores.size() << '\n';
    } else {
        cout << "입력한 점수가 없습니다.\n";
    }
}
