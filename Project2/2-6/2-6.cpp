#include <iostream>
#include <string>

using namespace std;

int main() {
	//char str1[100];
	//char str2[200];
	string str1, str2;

	cout << "�� ��ȣ�� �Է��϶� ";
	cin >> str1;
	cout << "�� ��ȣ�� �ٽ� �� �� �Է��϶� ";
	cin >> str2;
	//if (strcmp(str1, str2) == 0) cout << "�����ϴ�.";
	if (str1 == str2) cout << "�����ϴ�. ";
	else cout << "���� �ʽ��ϴ�. ";

	return 0;
}