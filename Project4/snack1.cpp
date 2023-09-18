#include <iostream>
#include <vector>

using namespace std;

class Snack {
protected:
	int price;
	string name;
	string maker;
public:
	Snack() { }
	string getName() {
		return name;
	}
	virtual void showInfo() {
		cout << name << " °úÀÚÀÔ´Ï´Ù~" << endl;
	}
};

class Candy : public Snack {
public:
	string flavor;
public:
	Candy(string flavor, string name) {
		this->price = 200;
		this->name = name;
		this->maker = "³ó½É";
		this->flavor = flavor;
	}
	void showInfo() {
		cout << name << " »çÅÁ" << endl;
	}
};

class Chocolate : public Snack {
public:
	string shape;
public:
	Chocolate(string shape, string name) {
		this->price = 1000;
		this->name = name;
		this->maker = "·Ôµ¥";
		this->shape = shape;
	}

	void showInfo() {
		cout << name << " ÃÊÄÝ¸´" << endl;
	}
};

class Chocolate2 : public Snack {
public:
	int shape;
public:
	Chocolate2(string shape, string name) {
		this->price = 1000;
		this->name = name;
		this->maker = "·Ôµ¥";
		this->shape = 100;
	}

	void showInfo() {
		cout << name << " ÃÊÄÝ¸´" << endl;
	}
};

int main() {
	std::vector<Snack*> snackBasket;

	//Candy *pc1 = new Candy("ÀÚµÎ", "½ÅÈ£µî")
	Candy c1("ÀÚµÎ", "½ÅÈ£µî");
	Candy* pc1 = &c1;
	Candy c2("»ç°ú", "ÃòÆÄ");

	Chocolate ch1("»ç°¢", "°¡³ª");
	Chocolate ch2("»ï°¢", "Å¶Ä¹");

	snackBasket.push_back(&c1); // Snack * = Candy *
	snackBasket.push_back(&c2);
	snackBasket.push_back(&ch1); // Snack * = Chocolate *
	snackBasket.push_back(&ch2);

	for (Snack* snack : snackBasket) {
		cout << snack->getName() << endl;
		snack->showInfo();
	}

	//((Candy*)snackBasket[0])->showInfo(); // Candy * = Snack *
	cout << ((Candy*)snackBasket[0])->flavor << endl;
	((Candy*)snackBasket[0])->flavor;

	//((Chocolate*)snackBasket[0])->showInfo(); // Chocolate * = Snack *
	cout << ((Chocolate*)snackBasket[0])->shape << endl;
	((Chocolate*)snackBasket[0])->shape;

	Chocolate* derivedPtr = dynamic_cast<Chocolate*>(snackBasket[0]);
	cout << derivedPtr << endl;

	Candy* derivedPtr2 = dynamic_cast<Candy*>(snackBasket[0]);
	cout << derivedPtr2 << endl;
	if (derivedPtr2) {
		cout << derivedPtr2->flavor << endl;
	}

	return 0;
}