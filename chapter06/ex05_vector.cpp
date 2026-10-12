#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    vector<int> scores;
    vector<double> values;
    vector<string> names;

    scores.push_back(90);
    scores.push_back(80);
    scores.push_back(70);
    values.push_back(3.14);
    names.push_back("Kim");

    cout << "scores: ";
    for (int score : scores) cout << score << ' ';
    cout << "\nvalues[0]: " << values[0];
    cout << "\nnames[0]: " << names[0] << '\n';
}
