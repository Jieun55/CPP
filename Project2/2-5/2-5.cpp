#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main() {
	string c;
	//char c[100];
	int count = 0;
	cout << "������ �Է��϶� (100�� �̸�)" << endl;
	getline(cin, c);
	//cin.getline(c, 100, '\n');
	int i = 0;

	while (true) {
		if (c[i] == '\n') break;
		if (c[i] == 'x') count++;
		i++;
	}
	cout << "x�� ������ = " << count << endl;
	return 0;
}