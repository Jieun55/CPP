#include <iostream>

int main() {
	int sum = 0;
	for (int i = 0; i <= 10; i++) {
		sum += i;
	}
	std::cout << "1~10까지의 합은 : ";
	std::cout << sum << "입니다." << std::endl;
	return 0;
}