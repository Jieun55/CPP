#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main() {
	string c;
	//char c[100];
	int count = 0;
	cout << "문장을 입력하라 (100개 미만)" << endl;
	getline(cin, c);
	//cin.getline(c, 100, '\n');
	int i = 0;

	while (true) {
		if (c[i] == '\n') break;
		if (c[i] == 'x') count++;
		i++;
	}
	cout << "x의 개수는 = " << count << endl;
	return 0;
}