#include <iostream>
#include <string>
using namespace std;

class BankAccount{
private :
	int balance; 
public:
	BankAccount(int b) {    
		if (b >= 0) balance = b;
		else balance = 0;
    }

	void deposit(int amount) {
		if (amount > 0) balance += amount;
	}

	void withdraw(int amount) {
		if (amount > 0 && amount <= balance){
            balance -= amount;
        }
        else {
            cout << "잔액이 부족합니다." << endl;
		}       
	}

	int getBalance() const {		
		return balance;
	}
 
};

int main() {
    // 초기 잔액이 10000원인 계좌 생성
    BankAccount account(10000);

    cout << "초기 잔액: " << account.getBalance() << "원" << endl;

    // 5000원 입금
    account.deposit(5000);
    cout << "5000원 입금 후: " << account.getBalance() << "원" << endl;

    // 3000원 출금
    account.withdraw(3000);
    cout << "3000원 출금 후: " << account.getBalance() << "원" << endl;

    // 잔액보다 큰 금액 출금 시도
    account.withdraw(20000);
    cout << "20000원 출금 시도 후: " << account.getBalance() << "원" << endl;
    return 0;
}
