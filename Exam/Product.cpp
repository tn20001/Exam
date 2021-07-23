#include "Product.h"

Product::Product() {
	ID = id;
	id++;
	name = "";
	price = 0;
}

Product::Product(string n, double p, double dis) {
	setName(n);
	setPrice(p);
	ID = id;
	id++;
}

Product& Product::operator=(Product& chg) {
	setName(chg.name);
	setPrice(chg.price);
	ID = chg.ID;
	return*this;
}

void Product::setName(string n) {
	if (n.size() < 2) throw InvalidArgumentException("Name 3den kicik ola bilmez!!", __LINE__, "My Exception");
	name = n;
}
void Product::setPrice(double p) {
	if (p < 1) throw InvalidArgumentException("Qiymen menfidir ve ya sifirdir!!", __LINE__, "My Exception");
	price = p;
}
void Product::setCount(double c) {
	if (c < 0) throw InvalidArgumentException("Say Menfidir!!", __LINE__, "My Exception");
	count = c;
}

string Product::getName() const { return name; }
double Product::getPrice() const { return price; }
double Product::getCount() const { return count; }
int Product::getID() const { return ID; }

void Product::Show() {
	cout << "Name: " << name;
	cout << "\nPrice: " << price;
	cout << "\nCount: " << count;
	cout << "\nID: " << ID;
}

int Product::id = 1000;