#pragma once
#include <string>

class BankAccount
{
public:
    std::string owner;
    int balance;

    void deposit(int money);
    void withdraw(int money);
    void print();
};
