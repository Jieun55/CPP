#pragma once

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

class Container { // 통 하나를 나타내는 클래스
	int size; // 현재 저장 량, 최대 저장 가능량은 10
public:
	Container() { size = 10; }
	void fill(int n); // n 만큼 채우기
	bool consume(int n); // n 만큼 소모하기
	int getSize(); // 현재 크기 리턴
};