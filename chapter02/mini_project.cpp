#include <iostream>
using namespace std;

int main() {
    const int SIZE = 5;
    int score[SIZE];

    int sum = 0;
    int maxScore;
    int minScore;

    // 점수 입력
    for (int i = 0; i < SIZE; i++) {
        cout << i + 1 << "번째 학생의 점수: ";
        cin >> score[i];
    }

    // 최고점, 최저점의 초기값
    maxScore = score[0];
    minScore = score[0];

    // 합계, 최고점, 최저점 계산
    for (int i = 0; i < SIZE; i++) {
        sum += score[i];

        if (score[i] > maxScore) {
            maxScore = score[i];
        }

        if (score[i] < minScore) {
            minScore = score[i];
        }
    }

    // 평균 계산
    double average = static_cast<double>(sum) / SIZE;

    // 결과 출력
    cout << "\n전체 점수 합계: " << sum << endl;
    cout << "평균: " << average << endl;
    cout << "최고 점수: " << maxScore << endl;
    cout << "최저 점수: " << minScore << endl;

    // 합격자 수 계산
    int passCount = 0;

    for (int i = 0; i < SIZE; i++) {
        if (score[i] >= 60) {
            passCount++;
        }
    }

    cout << "합격자 수: " << passCount << "명" << endl;

    return 0;
}
