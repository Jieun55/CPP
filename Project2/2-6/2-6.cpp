#include <iostream>
#include <string>

using namespace std;

int main() {
	//char str1[100];
	//char str2[200];
	string str1, str2;

	cout << "새 암호를 입력하라 ";
	cin >> str1;
	cout << "새 암호를 다시 한 번 입력하라 ";
	cin >> str2;
	//if (strcmp(str1, str2) == 0) cout << "같습니다.";
	if (str1 == str2) cout << "같습니다. ";
	else cout << "같지 않습니다. ";

	return 0;
}