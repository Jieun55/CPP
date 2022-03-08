#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

class Word {
	string eng;
	string kor;
public:
	Word(string eng, string kor) {
		this->eng = eng;
		this->kor = kor;
	}
	string getEng() { return eng; }
	string getKor() { return kor; }
};

void inputWord(vector<Word>& v) { // ���� ����
	cout << "���� �ܾ exit�� �Է��ϸ� �Է� ��" << endl;
	string eng, kor;

	while (true) {
		cout << "���� >>";
		cin >> eng;
		if (eng == "exit")
			break;
		cout << "�ѱ� >>";
		cin >> kor;
		v.push_back(Word(eng, kor));
	}
}

void Start(vector<Word>& v) { // ���� �׽�Ʈ
	srand((unsigned)time(0)); // ������ ������, �ٸ� �������� �߻���Ű�� ���� seed ����
	int num;
	cout << "���� ���� �׽�Ʈ�� �����մϴ�. 1~4�� �ٸ� �Է� �� ����." << endl;

	while (true) {
		int randNum = rand() % v.size();
		cout << v.at(randNum).getEng() << "?" << endl; // �������� ���� �ܾ� ����

		string option[4]; // ���� �����
		int n = rand() % 4;
		option[n] = v.at(randNum).getKor(); // ������ �ܾ �������� ���⿡ �ֱ�

		for (int i = 0; i < 4; i++) {
			if (i != n) {
				while (true) { // �ߺ����� �ʰ� ���� ����
					int k = rand() % v.size();
					if (option[0] != v.at(k).getKor() && option[1] != v.at(k).getKor() &&
						option[2] != v.at(k).getKor() && option[3] != v.at(k).getKor()) {
						option[i] = v.at(k).getKor();
						break;
					}
				}
			}
		}

		for (int i = 0; i < 4; i++) {
			cout << "(" << i + 1 << ")" << option[i] << ' ';
		}
		cout << ":>";
		cin >> num; // �����׽�Ʈ �� �Է�
		if (num > 0 && num < 5) {
			if (option[num - 1] == v.at(randNum).getKor())
				cout << "Excellent !!" << endl;
			else
				cout << "No. !!" << endl;
		}
		else
			break;
	}
}

int main() {
	int num; // �Էµ� ����
	vector<Word> v;
	v.push_back(Word("honey", "����"));
	v.push_back(Word("doll", "����"));
	v.push_back(Word("painting", "�׸�"));
	v.push_back(Word("stock", "�ֽ�"));
	v.push_back(Word("bear", "��"));
	v.push_back(Word("deal", "�ŷ�"));

	cout << "***** ���� ���� �׽�Ʈ�� �����մϴ�. *****" << endl;
	while (true) {
		cout << "���� ����: 1, ���� �׽�Ʈ: 2, ���α׷� ����: �׿� Ű >> ";
		cin >> num;
		if (num == 1) {
			inputWord(v);
			cout << endl;
		}
		else if (num == 2) {
			Start(v);
			cout << endl;
		}
		else {
			cout << "���α׷��� �����մϴ�." << endl;
			break;
		}
	}
}