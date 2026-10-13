#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string title;
    int price;
public:
    Book(string t, int p) : title{t}, price{p} {}
    void print() const {
        cout << title << " : " << price << '\n';
    }
};

int main() {
    Book books[3] = {
        Book("어서와 C++", 25000),
        Book("자료구조", 28000),
        Book("알고리즘", 30000)
    };
    for (const Book& b : books) b.print();
}
