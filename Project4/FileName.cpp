#include <iostream>

using namespace std;


class Shape {
protected:
	virtual void draw() = 0;
};

class Circle :public Shape {
public:
	void draw() {
		cout << "��" << endl;
	}
};

class Rect :public Shape {
public:
	void draw() {
		cout << "�簢" << endl;
	}
};

class Tria :public Shape {
public:
	void draw() {
		cout << "�ﰢ" << endl;
	}
};

int main(void) {
	
	cout << "Circle" << endl;
	cout << "�簢" << endl;
	cout << "�ﰢ" << endl;


}