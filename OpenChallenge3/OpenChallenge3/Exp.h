#ifndef EXP_H //define 되어있지 않으면 comfile 하기
#define EXP_H

class Exp {
	int exp;
	int base;
public:
	Exp() { base = 1; exp = 1; } //Exp(1, 1)로 위임생성자 사용 가능
	Exp(int b) { base = b; exp = 1; }
	Exp(int b, int e) { base = b; exp = e; }

	int getBase() { return base; }
	int getExp() { return exp; }
	int getValue(); //선언만 해줌
	bool equals(Exp b);

};

#endif