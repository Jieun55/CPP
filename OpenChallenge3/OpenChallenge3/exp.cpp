#include "Exp.h"

int Exp::getValue() { // 3,2
	int res = 1;
	for (int i = 0; i < exp; i++) {
		res = res * base;
	}
	return res;
}

//equals�� ������
bool Exp::equals(Exp b) { // b��� ��ü�� ����
	if (getValue() == b.getValue()) 
		return true;
	else 
		return false;
}