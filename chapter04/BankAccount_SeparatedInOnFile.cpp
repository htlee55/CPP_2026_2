#include <iostream>
#include <string>
using namespace std;

// 인터페이스(Interface): 클래스 선언부
class BankAccount
{
public:
    string owner;
    int balance;

    void deposit(int money);
    void withdraw(int money);
    void print();
};

// 구현부(Implementation): 클래스 맴버 함수 정의
void BankAccount::deposit(int money)
{
    balance += money;
}

void BankAccount::withdraw(int money)
{
    if (balance >= money)
    {
        balance -= money;
    }
    else
    {
        cout << "잔액이 부족합니다." << endl;
    }
}

void BankAccount::print()
{
    cout << owner << " : " << balance << "원" << endl;
}

int main()
{
    BankAccount account1;
    BankAccount account2;

    account1.owner = "홍길동";
    account1.balance = 10000;

    account2.owner = "김철수";
    account2.balance = 5000;

    account1.deposit(5000);
    account2.withdraw(2000);

    account1.print();
    account2.print();

    return 0;
}
