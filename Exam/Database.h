#pragma once
#include <conio.h>
#include <string>
#include "WriteRead.h"

class Database {
	int size_admin = 0;
	int size_product = 0;
	int size_meal = 0;
	int size_guest = 0;
	int budce = 10000;

public:

	Admin** admins;
	Product** products;
	Meal** meals;
	Guest** guests;

	void addGuest();

	void addAdmin();

	void addProduct();

	void deleteProductByID();

	void addMeal();

	void deleteMealByID();

	void LoginAsAdmin();

	void LoginAsGuest();

	void addIng(Meal*& chg);

	void deleteIng(Meal*& chg);

	void updateMeal(Meal*& chg);


	void CheckProductCount();



	int getSizeAdmin();
	int getSizeGuest();
	int getSizeProduct();
	int getSizeMeal();
	int getBudce();

	void setSizeAdmin(int a);
	void setSizeGuest(int a);
	void setSizeProduct(int a);
	void setSizeMeal(int a);
	void setBudce(int a);
};