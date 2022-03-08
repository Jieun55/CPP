#include <iostream>
#include <cstdlib>
#include <ctime> 
using namespace std;

//202001527 ������
//3�� 7�� ����

class SelectableRandom {
public:
	SelectableRandom();
	int next();
	int nextInRange(int a, int b);
};

SelectableRandom::SelectableRandom() {
	srand((unsigned)time(0)); //������ seed�� �����Ͽ� �� ������ �ٸ� ���� ���� ������ �Ѵ�.
}

int SelectableRandom::next() {
	int num = rand();
	if (num % 2 == 0)
		return num;
	else
		return num + 1;
}

int SelectableRandom::nextInRange(int a, int b) {
	int num = a + (rand() % (b - a + 1));
	if (num % 2 == 1)
		return num;
	else
		return num + 1;
}


int main() {
	SelectableRandom r;
	cout << "-- 0���� " << RAND_MAX << "������ ���� ���� 10 ��--" << endl;
	for (int i = 0; i < 10; i++) {
		int n = r.next(); // 0���� RAND_MAX(32767) ������ ������ ����
		cout << n << ' ';
	}
	cout << endl << endl << "-- 2���� " << "9 ������ ���� ���� 10 �� --" << endl;
	for (int i = 0; i < 10; i++) {
		int n = r.nextInRange(2, 9); // 2���� 9 ������ ������ ����
		cout << n << ' ';
	}
	cout << endl;
}