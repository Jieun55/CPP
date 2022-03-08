#include <iostream>
#include <string>
using namespace std;

class Integer {
	int value;
public:
	Integer(int n) { value = n; }
	Integer(string s) { value = stoi(s);} // string�� stoi�Լ� ������ ��� ����
	void set(int n) { value = n; }
	int get() { return value; }
	bool isEven() { return value % 2 == 0 ? true : false; } // ����ο� ��� ������
};
int main() {
	Integer n(30);
	cout << n.get() << ' ';
	n.set(50);
	cout << n.get() << ' ';

	Integer m("300");
	cout << m.get() << ' ' << m.isEven() << endl;

}