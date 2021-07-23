#pragma once
#include "MyException.h"

class Product {
	string name;
	double price;
	int ID;
	static int id;
	double count = 0;

public:

	Product();

	Product(string n, double p, double dis);

	Product& operator=(Product& chg);

	void setName(string n);
	void setPrice(double p);
	void setCount(double c);

	string getName() const;
	double getPrice() const;
	double getCount() const;
	int getID() const;

	void Show();

};