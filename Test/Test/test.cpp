#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	char word;

	int k = 1;
	while (k <= 5) {
		int sum = 0;
		cout << "100¥�� �λ��� ����� �ʿ��� ���� ==> ";
		cin >> str;
		for (int i = 0; i < str.length(); i++) {
			word = str[i];
			for (int j = 1; j <= 26; j++) {
				if (word == char(j + 96)) {// char 97 == �ҹ��� a
					sum += j;
					break;
				}
			}
		}
		cout << "����� �����ϴ� " << str << "�� " << sum << "�� �Դϴ�." << endl;
		k++;
	}
	return 0;
}