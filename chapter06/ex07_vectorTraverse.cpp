#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> scores{90, 80, 70};

    cout << "인덱스 순회: ";
    for (size_t i = 0; i < scores.size(); ++i) cout << scores[i] << ' ';
    cout << '\n';

    cout << "범위 기반 순회: ";
    for (int score : scores) cout << score << ' ';
    cout << '\n';
}
