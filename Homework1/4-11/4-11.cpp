#include <iostream>
#include "CoffeeMachine.h"
using namespace std;

int main() {
	CoffeeVendingMachine* order = new CoffeeVendingMachine;
	order->run();
}

void CoffeeVendingMachine::fill() { // 3���� ���� ��� 10���� ä��
	for (int i = 0; i < 3; i++) {
		tong[i].fill(10);
	}
	show();
}

void CoffeeVendingMachine::selectEspresso() { // Ŀ�� 1, �� 1
	tong[0].consume(1);
	tong[1].consume(1);
	cout << "���������� �弼��\n";
}

void CoffeeVendingMachine::selectAmericano() { // Ŀ�� 1, �� 2
	tong[0].consume(1);
	tong[1].consume(2);
	cout << "�Ƹ޸�ī�� �弼��\n";
}

void CoffeeVendingMachine::selectSugarCoffee() { // Ŀ�� 1, �� 2, ���� 1
	tong[0].consume(1);
	tong[1].consume(2);
	tong[2].consume(1);
	cout << "����Ŀ�� �弼��\n";
}

void CoffeeVendingMachine::show() { // ���� Ŀ��, ��, ������ �ܷ� ���
	cout << "Ŀ�� " << tong[0].getSize() << ", �� " << tong[1].getSize() << ", ���� " << tong[2].getSize() << endl;
}

bool CoffeeVendingMachine::checkInputError() { // ����ó��
	for (int i = 0; i < 3; i++) {
		if (tong[i].getSize() == 0) {
			cout << "���ᰡ �����մϴ�.\n";
			run();
		}
	}
}

void CoffeeVendingMachine::run() { // Ŀ�� ���Ǳ� �۵�
	int n; int i = 0;
	if (i == 0)
		cout << "***** Ŀ�����Ǳ⸦ �۵��մϴ�. *****" << endl;
	i++;

	while (true) {
		cout << "�޴��� �����ּ���(1:����������, 2:�Ƹ޸�ī��, 3:����Ŀ��, 4:�ܷ�����. 5:ä���)>>" << endl;
		cin >> n;
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

		}
	}
}

void Container::fill(int n) { // n ��ŭ ä���, �ִ� size�� 10
	if (n >= 10) size = 10;
	else
		size += n;
}

bool Container::consume(int n) { // n ��ŭ �Ҹ��ϱ�
	size -= n;
}

int Container::getSize() { // ���� ũ�� ����
	return size;
}