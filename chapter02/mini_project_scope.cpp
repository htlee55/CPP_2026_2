#include <iostream>
using namespace std;

int main() {
    int score[5] = { 85, 70, 92, 60, 78 };

    cout << "일반 for문: ";

    for (int i = 0; i < 5; i++) {
        cout << score[i] << " ";
    }

    cout << "\n범위 기반 for문: ";

    for (int s : score) {
        cout << s << " ";
    }

    cout << endl;

    return 0;
}
