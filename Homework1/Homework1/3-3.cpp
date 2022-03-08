#include <iostream>
#include <string>
using namespace std;

//202001527 ������
//3�� 3�� ����

class Account {
	string name;
	int id; 
	int balance; //�ܾ�
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
	Account a("kitae", 1, 5000);    //id 1��, �ܾ� 5000��, �̸��� kitae�� ���� ����
	a.deposit(50000);				// 50000�� ����
	cout << a.getOwner() << "�� �ܾ��� " << a.inquiry() << endl;
	int money = a.withdraw(20000);	// 20000�� ���, withdrqw()�� ����� ���� �ݾ� ����
	cout << a.getOwner() << "�� �ܾ��� " << a.inquiry() << endl;
}