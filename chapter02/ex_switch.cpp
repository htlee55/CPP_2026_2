#include <iostream>
using namespace std;

int main() {
    int menu{};

    cout << "메뉴를 선택하세요.\n";
    cout << "1. 시작\n";
    cout << "2. 설정\n";
    cout << "기타. 종료\n";
    cout << "선택: ";

    cin >> menu;

    switch (menu) {
    case 1:
        cout << "시작\n";
        break;

    case 2:
        cout << "설정\n";
        break;

    default:
        cout << "종료\n";
    }

    return 0;
}
