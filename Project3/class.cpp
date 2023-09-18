#include <iostream>

using namespace std;



class Rectangle {
private:
	double width, height;
public:
	Rectangle(double w, double h) : width(w), height(h) {}
	Rectangle(const Rectangle& other) {
		width = other.width;
		height = other.height;
	}

	

	


	double area() {
		return width * height;

	}



};

int main() {
	double w, h;


	cout << "밑변길이";
	cin >> w;
	cout << "높이길이";
	cin >> h;

	Rectangle rect(w, h);
	Rectangle rect1(rect);
	Rectangle rect3 = rect;

	cout << "사각형의 넓이:" << rect.area() << endl;
	cout << "복사생성자 rec 1의 값:" << rect1.area() << endl;
	cout << "복사생성자 rec 3의 값2:" << rect3.area() << endl;

	return 0;
}
