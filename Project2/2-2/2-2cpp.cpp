#include <iostream>
#include <cstring>
#include <string>
#include <iomanip>

using namespace std;

int main() {
	for (int i = 2; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			cout << i << 'x' << j << '=' << right << setw(2) << i * j << '\t';
		}
		cout << endl;
	}
	return 0;
}