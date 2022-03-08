#include <iostream>
#include <cstdlib>
#include <ctime> 
using namespace std;

//202001527 ������
//3�� 6�� ����

class EvenRandom {
public:
	EvenRandom();
	int next();
	int nextInRange(int a, int b);
};

EvenRandom::EvenRandom() {
	srand((unsigned)time(0)); //������ seed�� �����Ͽ� �� ������ �ٸ� ���� ���� ������ �Ѵ�.
}

int EvenRandom::next() {
	int num = rand();
	if (num % 2 == 0)
		return num;
	else
		return num + 1;
}

int EvenRandom::nextInRange(int a, int b) {
	int num = a + (rand() % (b - a + 1));
	if (num % 2 == 0)
		return num;
	else
		return num + 1;
}


int main() {
	EvenRandom r;
	cout << "-- 0���� " << RAND_MAX << "������ ���� ���� 10 ��--" << endl;
	for (int i = 0; i < 10; i++) {
		int n = r.next(); // 0���� RAND_MAX(32767) ������ ������ ����
		cout << n << ' ';
	}
	cout << endl << endl << "-- 2���� " << "10 ������ ���� ���� 10 �� --" << endl;
	for (int i = 0; i < 10; i++) {
		int n = r.nextInRange(2, 10); // 2���� 10 ������ ������ ����
		cout << n << ' ';
	}
	cout << endl;
}