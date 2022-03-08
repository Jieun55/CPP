#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main() {
	int num;
	int order;
	int totalSale = 0;
	string coffee;
	cout << "에스프레소 2000원, 아메리카노 2300원, 카푸치노 2500원 입니다. " << endl;

	while (true) {
		cout << "주문 => ";
		cin >> coffee >> num;
		if (coffee == "에스프레소") {
			order = 2000 * num;
		}
		else if (coffee == "아메리카노") {
			order = 2300 * num;
		}
		else if (coffee == "카푸치노") {
			order = 2500 * num;
		}
		else {
			order = 0;
		}

		if (order > 0) {
			cout << order << "원 입니다. 맛있게 드세요" << endl;
		}
		else {
			cout << "없는 커피 입니다. ";
		}
		totalSale += order;
		if (totalSale > 20000) {
			cout << "오늘" << totalSale << "원을 판매하여 카페를 닫습니다. ";
				break;
		}
	}
	return 0;
}