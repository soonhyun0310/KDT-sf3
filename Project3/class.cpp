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


	cout << "�غ�����";
	cin >> w;
	cout << "���̱���";
	cin >> h;

	Rectangle rect(w, h);
	Rectangle rect1(rect);
	Rectangle rect3 = rect;

	cout << "�簢���� ����:" << rect.area() << endl;
	cout << "��������� rec 1�� ��:" << rect1.area() << endl;
	cout << "��������� rec 3�� ��2:" << rect3.area() << endl;

	return 0;
}
