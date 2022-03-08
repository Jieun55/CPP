#include "CoffeeMachine.h"
#include <iostream>
using namespace std;

void Container::fill(int n) { // n ��ŭ ä���, �ִ� size�� 10
	if (n >= 10) size = 10;
	else
		size += n;
}

bool Container::consume(int n) { // n ��ŭ �Ҹ��ϱ�
	if (size < n)
		return false;
	else {
		size -= n;
		return true;
	}
}

int Container::getSize() { // ���� ũ�� ����
	return size;
}

void CoffeeVendingMachine::fill() { // 3���� ���� ��� 10���� ä��
	for (int i = 0; i < 3; i++) {
		tong[i].fill(10);
	}
	show();
}

void CoffeeVendingMachine::selectEspresso() { // Ŀ�� 1, �� 1
	for (int i = 0; i < 3; i++) {
		if (tong[i].getSize() == 0) {
			cout << "���ᰡ �����մϴ�.\n";
			run();
		}
	}
	tong[0].consume(1);
	tong[1].consume(1);
	cout << "���������� �弼��\n";

	//if(tong[0].getSize() > 0 && tong[1].getSize() > 0) {
	//	tong[0].consume(1); // Ŀ�� ����
	//	tong[1].consume(1); // �� ����
	//	cout << "���������� �弼��" << endl;
	//}
	//else {
	//	cout << "��ᰡ �����մϴ�" << endl;
	//}
}

void CoffeeVendingMachine::selectAmericano() { // Ŀ�� 1, �� 2
	for (int i = 0; i < 3; i++) {
		if (tong[i].getSize() == 0) {
			cout << "���ᰡ �����մϴ�.\n";
			run();
		}
	}
	tong[0].consume(1);
	tong[1].consume(2);
	cout << "�Ƹ޸�ī�� �弼��\n";
	//if(tong[0].getSize() > 0 && tong[1].getSize() > 1) {
	//	tong[0].consume(1); // Ŀ�� ����
	//	tong[1].consume(2); // �� ����
	//	cout << "�Ƹ޸�ī�� �弼��" << endl;
	//}
	//else {
	//	cout << "��ᰡ �����մϴ�" << endl;
	//}
}

void CoffeeVendingMachine::selectSugarCoffee() { // Ŀ�� 1, �� 2, ���� 1
	for (int i = 0; i < 3; i++) {
		if (tong[i].getSize() == 0) {
			cout << "���ᰡ �����մϴ�.\n";
			run();
		}
	}
	tong[0].consume(1);
	tong[1].consume(2);
	tong[2].consume(1);
	cout << "����Ŀ�� �弼��\n";
	//if(tong[0].getSize() > 0 && tong[1].getSize() > 1 && tong[2].getsize() > 0) {
	//	tong[0].consume(1); // Ŀ�� ����
	//	tong[1].consume(2); // �� ����
	//	tong[2].consume(1); // ���� ����
	//	cout << "�Ƹ޸�ī�� �弼��" << endl;
	//}
	//else {
	//	cout << "��ᰡ �����մϴ�" << endl;
	//}
}

void CoffeeVendingMachine::show() { // ���� Ŀ��, ��, ������ �ܷ� ���
	cout << "Ŀ�� " << tong[0].getSize() << ", �� " << tong[1].getSize() << ", ���� " << tong[2].getSize() << endl;
}

void CoffeeVendingMachine::run() { // Ŀ�� ���Ǳ� �۵�
	cout << "***** Ŀ�����Ǳ⸦ �۵��մϴ�. *****" << endl;

	while (true) {
		cout << "�޴��� �����ּ���(1:����������, 2:�Ƹ޸�ī��, 3:����Ŀ��, 4:�ܷ�����. 5:ä���)>>" << endl;
		int n;
		cin >> n;
		if (checkInputError()) // �޴��� ���� ��� ���ڸ� �Է��� ��츦 �߰��ϰ� ó��
			continue;
		switch (n) {
		case 1:
			selectEspresso();
			break;
		case 2:
			selectAmericano();
			break;
		case 3:
			selectSugarCoffee();
			break;
		case 4:
			show();
			break;
		case 5:
			fill();
			break;
		default:
			cout << "�߸� �����̽��ϴ�." << endl;
		}
	}
}

bool CoffeeVendingMachine::checkInputError() {
	if (cin.fail()) { // ������� ���ڿ��� �ԷµǾ� ������ �߻��ϴ� ��� ��ó.
		cin.clear(); // ���λ����÷��׸� �ʱ�ȭ ���� cin�� �ùٸ� ������ �̾�� ��
		cin.ignore(100, '\n');
		//cin.ignore();
		cout << "�Է� ����" << endl;
		return true; // ���� ����
	}
	else
		return false; // ���� ����
}

int main() {
	CoffeeVendingMachine cvm;
	cvm.run();
}