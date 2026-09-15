#include <iostream>
using namespace std;

int main()
{
    int quizScore;
    int midtermScore;
    int finalScore;

    cout << "퀴즈 점수를 입력하세요: ";
    cin >> quizScore;

    cout << "중간고사 점수를 입력하세요: ";
    cin >> midtermScore;

    cout << "기말고사 점수를 입력하세요: ";
    cin >> finalScore;

    int totalScore = quizScore + midtermScore + finalScore;

    cout << "전체 점수의 합계: " << totalScore << endl;

    return 0;
}
