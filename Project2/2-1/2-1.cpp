#include <iostream>
#include <cstring>
#include <string>
#include <iomanip>

using namespace std;

int main() {
	//�⺻ ���
	/*int num = 0;
	for (int i = 1; i <= 10; i++) {
		for (int j = 1; j <= 10; j++) {
			num++;
			cout << num << '\t';
		}
		cout << endl;
	}*/

	//���2
	for (int i = 1; i <= 100; i++) {
		cout << right << setw(5) << i;
		if (i % 10 == 0) //10�� ����̸�
			cout << endl;
	}
}