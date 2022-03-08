#include <iostream>
#include <string>
using namespace std;

//202001527 오지은
//3장 3번 문제

class Account {
	string name;
	int id; 
	int balance; //잔액
public:
	Account(string s, int i, int bal);
	void deposit(int i);
	int withdraw(int i);
	int inquiry();
	string getOwner();
	
};

Account::Account(string s, int i, int bal) {
	name = s;
	id = i;
	balance = bal;
}

void Account::deposit(int i) {
	balance += i;
}

int Account::withdraw(int i) {
	balance -= i;
	return balance;
}

int Account::inquiry() {
	return balance;
}

string Account::getOwner() {
	return name;
}

int main() {
	Account a("kitae", 1, 5000);    //id 1번, 잔액 5000원, 이름이 kitae인 계좌 생성
	a.deposit(50000);				// 50000원 지급
	cout << a.getOwner() << "의 잔액은 " << a.inquiry() << endl;
	int money = a.withdraw(20000);	// 20000원 출금, withdrqw()는 출금한 실제 금액 리턴
	cout << a.getOwner() << "의 잔액은 " << a.inquiry() << endl;
}