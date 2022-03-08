#include <iostream>
#include <string>
using namespace std;

class Integer {
	int value;
public:
	Integer(int n) { value = n; }
	Integer(string s) { value = stoi(s);} // string에 stoi함수 내용이 담겨 있음
	void set(int n) { value = n; }
	int get() { return value; }
	bool isEven() { return value % 2 == 0 ? true : false; } // 선언부에 모두 정의함
};
int main() {
	Integer n(30);
	cout << n.get() << ' ';
	n.set(50);
	cout << n.get() << ' ';

	Integer m("300");
	cout << m.get() << ' ' << m.isEven() << endl;

}