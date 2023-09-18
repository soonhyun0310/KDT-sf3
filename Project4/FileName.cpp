#include <iostream>

using namespace std;


class Shape {
protected:
	virtual void draw() = 0;
};

class Circle :public Shape {
public:
	void draw() {
		cout << "¿ø" << endl;
	}
};

class Rect :public Shape {
public:
	void draw() {
		cout << "»ç°¢" << endl;
	}
};

class Tria :public Shape {
public:
	void draw() {
		cout << "»ï°¢" << endl;
	}
};

int main(void) {
	
	cout << "Circle" << endl;
	cout << "»ç°¢" << endl;
	cout << "»ï°¢" << endl;


}