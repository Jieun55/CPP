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

void inputWord(vector<Word>& v) { // 어휘 삽입
	cout << "영어 단어에 exit을 입력하면 입력 끝" << endl;
	string eng, kor;

	while (true) {
		cout << "영어 >>";
		cin >> eng;
		if (eng == "exit")
			break;
		cout << "한글 >>";
		cin >> kor;
		v.push_back(Word(eng, kor));
	}
}

void Start(vector<Word>& v) { // 어휘 테스트
	srand((unsigned)time(0)); // 시작할 때마다, 다른 랜덤수를 발생시키기 위한 seed 설정
	int num;
	cout << "영어 어휘 테스트를 시작합니다. 1~4외 다른 입력 시 종료." << endl;

	while (true) {
		int randNum = rand() % v.size();
		cout << v.at(randNum).getEng() << "?" << endl; // 랜덤으로 정답 단어 설정

		string option[4]; // 보기 만들기
		int n = rand() % 4;
		option[n] = v.at(randNum).getKor(); // 설정된 단어를 랜덤으로 보기에 넣기

		for (int i = 0; i < 4; i++) {
			if (i != n) {
				while (true) { // 중복되지 않게 오답 설정
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
		cin >> num; // 어휘테스트 답 입력
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
	int num; // 입력된 숫자
	vector<Word> v;
	v.push_back(Word("honey", "애인"));
	v.push_back(Word("doll", "인형"));
	v.push_back(Word("painting", "그림"));
	v.push_back(Word("stock", "주식"));
	v.push_back(Word("bear", "곰"));
	v.push_back(Word("deal", "거래"));

	cout << "***** 영어 어휘 테스트를 시작합니다. *****" << endl;
	while (true) {
		cout << "어휘 삽입: 1, 어휘 테스트: 2, 프로그램 종료: 그외 키 >> ";
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
			cout << "프로그램을 종료합니다." << endl;
			break;
		}
	}
}