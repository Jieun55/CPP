//202001527 ������

#include <iostream>
#include <string>
using namespace std;

class Circle {
    int radius; // ���� ������ ��
    string name; // ���� �̸�
public:
    void setCircle(string name, int radius); //�̸��� ������ ����
    double getArea();
    string getName();
};

class CircleManger {
    Circle* p;
    int size;
public:
    CircleManger(int size); //size ũ���� �迭�� ���� ����. ����ڷκ��� �Է� �Ϸ�
    ~CircleManger();
    void searchByName(); // ����ڷκ��� ���� �̸��� �Է¹޾� ���� ���
    void searchByArea(); // ����ڷκ��� ������ �Է¹޾� �������� ū ���� �̸� ���
};

void Circle::setCircle(string name, int radius) {
    this->name = name;
    this->radius = radius;
}

double Circle::getArea() { //�������ϱ�
    return radius * radius * 3.14;
}

string Circle::getName() {
    return name;
}

CircleManger::CircleManger(int size) { //size ũ���� �迭�� ���� ����.
    this->size = size;
    this->p = new Circle[size];//��ü �迭�� ���� ����
    string name;
    int radius;
    for (int i = 0; i < size; ++i) {
        cout << "�� " << i + 1 << "�� �̸��� ������ >> ";
        cin >> name >> radius;
        p[i].setCircle(name, radius);
    }
}

CircleManger::~CircleManger() {
    delete[] p;
}

void CircleManger::searchByName() { // ����ڷκ��� ���� �̸��� �Է¹޾� ���� ���
    cout << "�˻��ϰ��� �ϴ� ���� �̸� >> ";
    string name;
    cin >> name;
    for (int i = 0; i < this->size; ++i) {
        if (name.compare(p[i].getName()) == 0) {
            cout << name << "�� ������" << p[i].getArea() << endl;
            break;
        }
    }
}

void CircleManger::searchByArea() { // ����ڷκ��� ������ �Է¹޾� �������� ū ���� �̸� ���
    cout << "�ּ� ������ ������ �Է��ϼ��� >> ";
    int area;
    cin >> area;
    for (int i = 0; i < this->size; ++i) {
        if (area < p[i].getArea()) {
            cout << p[i].getName() << "�� ������," << p[i].getArea();
        }
    }
}

int main() {
    int num;
    cout << "���� ���� >> ";
    cin >> num;
    CircleManger circle(num);
    circle.searchByName();
    circle.searchByArea();
}