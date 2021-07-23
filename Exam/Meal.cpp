#include "Meal.h"

Meal::Meal() {
	ID = id;
	id++;
	name = "";
	describtion = "";
	price = 0;
}

Meal::Meal(string n, string d, double p, double dis) {
	setName(n);
	setPrice(p);
	setDesc(d);
	ID = id;
	id++;
}

Meal& Meal::operator=(Meal& chg) {
	setName(chg.name);
	setPrice(chg.price);
	ID = chg.ID;
	return*this;
}

void Meal::addIngredient(Product*& chg) {
	auto temp = new Product * [size_ing + 1];
	for (size_t i = 0; i < size_ing && size_ing > 0; i++)
	{
		temp[i] = new Product();
		temp[i] = ingredients[i];
	}
	temp[size_ing] = new Product();
	temp[size_ing] = chg;
	/*for (size_t i = 0; i < size_ing && size_ing > 0; i++)
	{
		delete[] ingredients[i];
	}*/
	if (size_ing > 0) delete ingredients;
	ingredients = temp;
	size_ing++;
}

void Meal::deleteIngredient(string n) {
	bool a = false;
	auto temp = new Product * [size_ing - 1];
	for (size_t i = 0, j = 0; i < size_ing && size_ing > 0; i++, j++)
	{
		if (ingredients[i]->getName() == n) {
			j--;
			a = true;
			continue;
		}
		temp[j] = new Product();
		temp[j] = ingredients[i];
	}
	/*for (size_t i = 0; i < size_ing && size_ing > 0; i++)
	{
		delete[] ingredients[i];
	}*/
	if (size_ing > 0) delete ingredients;
	ingredients = temp;
	size_ing--;
}

void Meal::setName(string n) {
	if (n.size() < 2) throw InvalidArgumentException("Name 2den kicik ola bilmez!!", __LINE__, "My Exception");
	name = n;
}
void Meal::setPrice(double p) {
	if (p < 1) throw InvalidArgumentException("Qiymen menfidir!!", __LINE__, "My Exception");
	price = p;
}
void Meal::setDesc(string desc) { describtion = desc; }
void Meal::setSize(int size) { size_ing = size; }

string Meal::getName() const { return name; }
string Meal::getDesc() const { return describtion; }
double Meal::getPrice() const { return price; }
int Meal::getID() const { return ID; }
int Meal::getSize() const { return size_ing; }

void Meal::Show() {
	cout << "Name: " << name;
	cout << "\nPrice: " << price;
	cout << "\nDescribtion: " << describtion;
	cout << "\nID: " << ID;
	cout << "\n\nIngredients: ";
	for (size_t i = 0; i < size_ing; i++)
	{
		cout << "\n" << ingredients[i]->getName() << " " << ingredients[i]->getCount();
	}
}

Meal::~Meal() {}

int Meal::id = 1000;