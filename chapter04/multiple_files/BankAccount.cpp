#include <iostream>
#include "BankAccount.h"

void BankAccount::deposit(int money)
{
    balance += money;
}

void BankAccount::withdraw(int money)
{
    balance -= money;
}

void BankAccount::print()
{
    std::cout << owner << " : "
              << balance << "원" << std::endl;
}
