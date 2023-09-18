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
		cout << "�����Դϴ�~" << endl;
	}
};

int Snack::count = 0;

class Candy : public Snack {
	string flavor;
public:
	Candy(string flavor) {
		this->price = 200;
		this->name = "����";
		this->maker = "���";
		this->flavor = flavor;
	}
	void show_info() {
		cout << flavor << "�� ����" << endl;
	}
};

class Chocolate : public Snack {
	string shape;
public:
	Chocolate(string shape) {
		this->price = 1000;
		this->name = "���ݸ�";
		this->maker = "�Ե�";
		this->shape = shape;
	}

	void show_info() {
		cout << shape << "��� ���ݸ�" << endl;
	}
};

int main() {
	vector<Snack*> snackBasket;

	while (1) {
		int number;
		cout << "���� �ٱ��Ͽ� �߰��� ������ ���ÿ�(1: ����, 2: ���ݸ�, 0: ����): ";
		cin >> number;
		if (number == 1) {
			string flavor;
			cout << "���� �Է��ϼ���: ";
			cin >> flavor;
			snackBasket.push_back(new Candy(flavor)); //��ü�� �ּҰ��� ������ ��
		}
		else if (number == 2) {
			string shape;
			cout << "����� �Է��ϼ���: ";
			cin >> shape;
			snackBasket.push_back(new Chocolate(shape));
		}
		else if (number == 0) {
			break;
		}
		else {
			cout << "0 ~ 2 ������ ���ڸ� �Է��ϼ���!!" << endl;
		}
	}

	cout << "���� �ٱ��Ͽ� ��� ������ ������ " << Snack::get_count() << "�� �Դϴ�." << endl;
	cout << endl;



	cout << "---------------���� ���� ���� ���� ����--------------- \n";

	for (Snack* snack : snackBasket) { // for-each��, (�迭�� ����, ���ϴ� �����̸� : �迭)
		snack->showInfo();
		delete snack;
	}
	snackBasket.clear();
}
	
