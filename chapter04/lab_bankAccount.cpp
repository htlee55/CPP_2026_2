#include <iostream>
#include <string>
using namespace std;

class BankAccount
{
public:
    string owner;
    int balance;

    void deposit(int money)
    {
        balance += money;
    }

    void withdraw(int money)
    {
        balance -= money;
    }

    void print()
    {
        cout << owner << " : " << balance << "원" << endl;
    }
};

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
