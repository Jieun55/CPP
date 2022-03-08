#ifndef EXP_H //define �Ǿ����� ������ comfile �ϱ�
#define EXP_H

class Exp {
	int exp;
	int base;
public:
	Exp() { base = 1; exp = 1; } //Exp(1, 1)�� ���ӻ����� ��� ����
	Exp(int b) { base = b; exp = 1; }
	Exp(int b, int e) { base = b; exp = e; }

	int getBase() { return base; }
	int getExp() { return exp; }
	int getValue(); //���� ����
	bool equals(Exp b);

};

#endif