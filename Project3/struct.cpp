#include <iostream>

using namespace std;



struct Rectangle {
	int width;
	int height;

};

int main() {
	Rectangle R;
	R.width;
	R.height;


	cout << "가로길이";
	cin >> R.width;
	cout << "세로길이";
	cin >> R.height;

	cout << "사각형의 넓이는 : " << R.width * R.height;

}