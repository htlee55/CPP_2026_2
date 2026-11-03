#include <iostream>
using namespace std;
int main() {
    int n = 3;
    int* scores = new int[n]{80, 90, 100};
    for (int i = 0; i < n; ++i) cout << scores[i] << ' ';
    cout << '\n';
    delete[] scores;     // array allocation -> delete[]
    scores = nullptr;
}
