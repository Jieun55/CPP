#include <iostream>
#include <cstdlib>
#include <ctime> 
using namespace std;

//202001527 오지은
//3장 6번 문제

class EvenRandom {
public:
	EvenRandom();
	int next();
	int nextInRange(int a, int b);
};

EvenRandom::EvenRandom() {
	srand((unsigned)time(0)); //임의의 seed를 설정하여 할 때마다 다른 랜덤 수가 나오게 한다.
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
	cout << "-- 0에서 " << RAND_MAX << "까지의 랜덤 정수 10 개--" << endl;
	for (int i = 0; i < 10; i++) {
		int n = r.next(); // 0에서 RAND_MAX(32767) 사이의 랜덤한 정수
		cout << n << ' ';
	}
	cout << endl << endl << "-- 2에서 " << "10 까지의 랜덤 정수 10 개 --" << endl;
	for (int i = 0; i < 10; i++) {
		int n = r.nextInRange(2, 10); // 2에서 10 사이의 랜덤한 정수
		cout << n << ' ';
	}
	cout << endl;
}