#include "Exp.h"

int Exp::getValue() { // 3,2
	int res = 1;
	for (int i = 0; i < exp; i++) {
		res = res * base;
	}
	return res;
}

//equals의 구현부
bool Exp::equals(Exp b) { // b라는 객체를 받음
	if (getValue() == b.getValue()) 
		return true;
	else 
		return false;
}