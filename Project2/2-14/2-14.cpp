#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main() {
	int num;
	int order;
	int totalSale = 0;
	string coffee;
	cout << "���������� 2000��, �Ƹ޸�ī�� 2300��, īǪġ�� 2500�� �Դϴ�. " << endl;

	while (true) {
		cout << "�ֹ� => ";
		cin >> coffee >> num;
		if (coffee == "����������") {
			order = 2000 * num;
		}
		else if (coffee == "�Ƹ޸�ī��") {
			order = 2300 * num;
		}
		else if (coffee == "īǪġ��") {
			order = 2500 * num;
		}
		else {
			order = 0;
		}

		if (order > 0) {
			cout << order << "�� �Դϴ�. ���ְ� �弼��" << endl;
		}
		else {
			cout << "���� Ŀ�� �Դϴ�. ";
		}
		totalSale += order;
		if (totalSale > 20000) {
			cout << "����" << totalSale << "���� �Ǹ��Ͽ� ī�並 �ݽ��ϴ�. ";
				break;
		}
	}
	return 0;
}