#include <iostream>
using namespace std;

class Oval {
	int width;
	int height;
public:
	Oval();
	Oval(int w, int h);
	~Oval();
	int getWidth() { return width; }
	int getHeight() { return height; }
	void set(int w, int h);
	void show();
};

Oval::Oval() {
	width = 1; height = 1; // √ ±‚»≠
}

Oval::Oval(int w, int h) {
	width = w; height = h;
}

Oval::~Oval() {
	cout << "Oval º“∏Í : ";
	show();
}

void Oval::set(int w, int h) {
	width = w; height = h;
}

void Oval::show() {
	cout << "width = " << width << ", height = " << height << endl;
}

int main() {
	Oval a, b(3, 4);
	a.set(10, 20);
	a.show();
	cout << b.getWidth() << ", " << b.getHeight() << endl;
}