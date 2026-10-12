#include <iostream>
#include <vector>
using namespace std;

void show(const vector<int>& v) {
    cout << "size=" << v.size() << ", 내용:";
    for (int x : v) cout << ' ' << x;
    cout << '\n';
}

int main() {
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    show(v);

    if (!v.empty()) v.pop_back();
    show(v);

    cout << "비어 있는가? " << boolalpha << v.empty() << '\n';
    v.clear();
    show(v);
    cout << "비어 있는가? " << boolalpha << v.empty() << '\n';

    // 빈 벡터에서 pop_back()은 호출하지 않습니다.
}
