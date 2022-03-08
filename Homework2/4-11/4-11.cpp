#include "CoffeeMachine.h"
#include <iostream>
using namespace std;

void Container::fill(int n) { // n 만큼 채우기, 최대 size는 10
	if (n >= 10) size = 10;
	else
		size += n;
}

bool Container::consume(int n) { // n 만큼 소모하기
	if (size < n)
		return false;
	else {
		size -= n;
		return true;
	}
}

int Container::getSize() { // 현재 크기 리턴
	return size;
}

void CoffeeVendingMachine::fill() { // 3개의 통을 모두 10으로 채움
	for (int i = 0; i < 3; i++) {
		tong[i].fill(10);
	}
	show();
}

void CoffeeVendingMachine::selectEspresso() { // 커피 1, 물 1
	for (int i = 0; i < 3; i++) {
		if (tong[i].getSize() == 0) {
			cout << "원료가 부족합니다.\n";
			run();
		}
	}
	tong[0].consume(1);
	tong[1].consume(1);
	cout << "에스프레소 드세요\n";

	//if(tong[0].getSize() > 0 && tong[1].getSize() > 0) {
	//	tong[0].consume(1); // 커피 감소
	//	tong[1].consume(1); // 물 감소
	//	cout << "에스프레소 드세요" << endl;
	//}
	//else {
	//	cout << "재료가 부족합니다" << endl;
	//}
}

void CoffeeVendingMachine::selectAmericano() { // 커피 1, 물 2
	for (int i = 0; i < 3; i++) {
		if (tong[i].getSize() == 0) {
			cout << "원료가 부족합니다.\n";
			run();
		}
	}
	tong[0].consume(1);
	tong[1].consume(2);
	cout << "아메리카노 드세요\n";
	//if(tong[0].getSize() > 0 && tong[1].getSize() > 1) {
	//	tong[0].consume(1); // 커피 감소
	//	tong[1].consume(2); // 물 감소
	//	cout << "아메리카노 드세요" << endl;
	//}
	//else {
	//	cout << "재료가 부족합니다" << endl;
	//}
}

void CoffeeVendingMachine::selectSugarCoffee() { // 커피 1, 물 2, 설탕 1
	for (int i = 0; i < 3; i++) {
		if (tong[i].getSize() == 0) {
			cout << "원료가 부족합니다.\n";
			run();
		}
	}
	tong[0].consume(1);
	tong[1].consume(2);
	tong[2].consume(1);
	cout << "설탕커피 드세요\n";
	//if(tong[0].getSize() > 0 && tong[1].getSize() > 1 && tong[2].getsize() > 0) {
	//	tong[0].consume(1); // 커피 감소
	//	tong[1].consume(2); // 물 감소
	//	tong[2].consume(1); // 설탕 감소
	//	cout << "아메리카노 드세요" << endl;
	//}
	//else {
	//	cout << "재료가 부족합니다" << endl;
	//}
}

void CoffeeVendingMachine::show() { // 현재 커피, 물, 설탕의 잔량 출력
	cout << "커피 " << tong[0].getSize() << ", 물 " << tong[1].getSize() << ", 설탕 " << tong[2].getSize() << endl;
}

void CoffeeVendingMachine::run() { // 커피 자판기 작동
	cout << "***** 커피자판기를 작동합니다. *****" << endl;

	while (true) {
		cout << "메뉴를 눌러주세요(1:에스프레소, 2:아메리카노, 3:설탕커피, 4:잔량보기. 5:채우기)>>" << endl;
		int n;
		cin >> n;
		if (checkInputError()) // 메뉴에 숫자 대신 문자를 입력한 경우를 발견하고 처리
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
			cout << "잘못 누르셨습니다." << endl;
		}
	}
}

bool CoffeeVendingMachine::checkInputError() {
	if (cin.fail()) { // 정수대신 문자열이 입력되어 오류가 발생하는 경우 대처.
		cin.clear(); // 내부상태플러그를 초기화 시켜 cin이 올바른 동작을 이어가게 함
		cin.ignore(100, '\n');
		//cin.ignore();
		cout << "입력 오류" << endl;
		return true; // 오류 있음
	}
	else
		return false; // 오류 없음
}

int main() {
	CoffeeVendingMachine cvm;
	cvm.run();
}