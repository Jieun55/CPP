#include <iostream>
//#include "CoffeeMachine.h"
using namespace std;

class Container { // 통 하나를 나타내는 클래스
	int size; // 현재 저장 량, 최대 저장 가능량은 10
public:
	Container() { size = 10; }
	void fill(int n); // n 만큼 채우기
	bool consume(int n); // n 만큼 소모하기
	int getSize(); // 현재 크기 리턴
};

class CoffeeVendingMachine { // 커피 자판기를 표현하는 클래스
	Container tong[3]; // tong[0]는 커피, tong[1]은 물, tong[2]는 설탕통을 나타냄
	void fill(); // 3개의 통을 모두 10으로 채움
	void selectEspresso(); // 에스프레소를 선택한 경우, 커피 1, 물 1 소모
	void selectAmericano(); // 아메리카노를 선택한 경우,  커피 1, 물 2 소모
	void selectSugarCoffee(); // 설탕커피를 선택한 경우, 커피 1, 물 2 소모, 설탕 1 소모
	void show(); // 현재 커피, 물, 설탕의 잔량 출력
	bool checkInputError(); // 오류 처리를 위해 추가한 멤버 함수
public:
	void run(); // 커피 자판기 작동
};

int main() {
	CoffeeVendingMachine* order = new CoffeeVendingMachine;
	order->run();
}

void CoffeeVendingMachine::fill() { // 3개의 통을 모두 10으로 채움
	for (int i = 0; i < 3; i++) {
		tong[i].fill(10);
	}
	show();
}

void CoffeeVendingMachine::selectEspresso() { // 커피 1, 물 1
	tong[0].consume(1);
	tong[1].consume(1);
	cout << "에스프레소 드세요\n";
}

void CoffeeVendingMachine::selectAmericano() { // 커피 1, 물 2
	tong[0].consume(1);
	tong[1].consume(2);
	cout << "아메리카노 드세요\n";
}

void CoffeeVendingMachine::selectSugarCoffee() { // 커피 1, 물 2, 설탕 1
	tong[0].consume(1);
	tong[1].consume(2);
	tong[2].consume(1);
	cout << "설탕커피 드세요\n";
}

void CoffeeVendingMachine::show() { // 현재 커피, 물, 설탕의 잔량 출력
	cout << "커피 " << tong[0].getSize() << ", 물 " << tong[1].getSize() << ", 설탕 " << tong[2].getSize() << endl;
}

bool CoffeeVendingMachine::checkInputError() { // 오류처리
	for (int i = 0; i < 3; i++) {
		if (tong[i].getSize() == 0) {
			cout << "원료가 부족합니다.\n";
			run();
		}
	}
}

void CoffeeVendingMachine::run() { // 커피 자판기 작동
	int n; int i = 0;
	if (i == 0)
		cout << "***** 커피자판기를 작동합니다. *****" << endl;
	i++;

	while (true) {
		cout << "메뉴를 눌러주세요(1:에스프레소, 2:아메리카노, 3:설탕커피, 4:잔량보기. 5:채우기)>>" << endl;
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

void Container::fill(int n) { // n 만큼 채우기, 최대 size는 10
	if (n >= 10) size = 10;
	else
		size += n;
}

bool Container::consume(int n) { // n 만큼 소모하기
	size -= n;
}

int Container::getSize() { // 현재 크기 리턴
	return size;
}