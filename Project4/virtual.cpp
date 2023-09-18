#include <iostream>
#include <vector>

using namespace std;

class Snack {
protected:
	string price;
	string name;
	string maker;
	static int count;
public:
	Snack() { count++; }
	virtual ~Snack() { count--; }
	static int get_count() {
		return count;
	}
	string get_name() {
		return name;
	}
	virtual void show_info() {
		cout << "과자입니다~" << endl;
	}
};

int Snack::count = 0;

class Candy : public Snack {
	string flavor;
public:
	Candy(string flavor) {
		this->price = 200;
		this->name = "사탕";
		this->maker = "농심";
		this->flavor = flavor;
	}
	void show_info() {
		cout << flavor << "맛 사탕" << endl;
	}
};

class Chocolate : public Snack {
	string shape;
public:
	Chocolate(string shape) {
		this->price = 1000;
		this->name = "초콜릿";
		this->maker = "롯데";
		this->shape = shape;
	}

	void show_info() {
		cout << shape << "모양 초콜릿" << endl;
	}
};

int main() {
	vector<Snack*> snackBasket;

	while (1) {
		int number;
		cout << "과자 바구니에 추가할 간식을 고르시오(1: 사탕, 2: 초콜릿, 0: 종료): ";
		cin >> number;
		if (number == 1) {
			string flavor;
			cout << "맛을 입력하세요: ";
			cin >> flavor;
			snackBasket.push_back(new Candy(flavor)); //객체의 주소값을 담아줘야 함
		}
		else if (number == 2) {
			string shape;
			cout << "모양을 입력하세요: ";
			cin >> shape;
			snackBasket.push_back(new Chocolate(shape));
		}
		else if (number == 0) {
			break;
		}
		else {
			cout << "0 ~ 2 사이의 숫자를 입력하세요!!" << endl;
		}
	}

	cout << "과자 바구니에 담긴 간식의 개수는 " << Snack::get_count() << "개 입니다." << endl;
	cout << endl;



	cout << "---------------내가 가진 과자 정보 보기--------------- \n";

	for (Snack* snack : snackBasket) { // for-each문, (배열의 원소, 원하는 변수이름 : 배열)
		snack->showInfo();
		delete snack;
	}
	snackBasket.clear();
}
	
