#include <iostream>
#include <string>

using namespace std;

int main() {
	int a, b;
	cout << "두 수를 입력하라 ";
	cin >> a >> b;
	cout << "큰 수는 = " << (a > b ? a : b) << endl;

	return 0;
}