#pragma once
#include "Product.h"

class Meal {
	string name;
	double price;
	string describtion;
	int ID;
	int size_ing;
	static int id;

public:
	Product** ingredients;


	Meal();

	Meal(string n, string d, double p, double dis);

	Meal& operator=(Meal& chg);

	void addIngredient(Product*& chg);

	void deleteIngredient(string n);

	void setName(string n);
	void setPrice(double p);
	void setDesc(string desc);
	void setSize(int size);

	string getName() const;
	string getDesc() const;
	double getPrice() const;
	int getID() const;
	int getSize() const;

	void Show();

	~Meal();
};