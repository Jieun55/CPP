#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	char word;

	int k = 1;
	while (k <= 5) {
		int sum = 0;
		cout << "100짜리 인생을 살려면 필요한 것은 ==> ";
		cin >> str;
		for (int i = 0; i < str.length(); i++) {
			word = str[i];
			for (int j = 1; j <= 26; j++) {
				if (word == char(j + 96)) {// char 97 == 소문자 a
					sum += j;
					break;
				}
			}
		}
		cout << "당신이 생각하는 " << str << "은 " << sum << "점 입니다." << endl;
		k++;
	}
	return 0;
}