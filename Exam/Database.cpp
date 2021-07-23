#include "Database.h"
#include <vector>

void Database::addGuest() {
	string usern, password;
	cout << "User Name: "; cin >> usern;
	cout << "\nPassword: "; cin >> password;

	for (size_t i = 0; i < size_guest && size_guest > 0; i++)
	{
		if (guests[i]->getName() == usern) throw DatabaseException("User Already exists", __LINE__, "My Exception");
	}
	Guest* chg = new Guest(usern, password);

	auto temp = new Guest * [size_guest + 1];
	for (size_t i = 0; i < size_guest && size_guest > 0; i++)
	{
		temp[i] = new Guest();
		temp[i] = guests[i];
	}
	temp[size_guest] = new Guest();
	temp[size_guest] = chg;

	if (size_guest > 0) delete[] guests;
	guests = temp;
	file_txt_write_guest(temp[size_guest]);
	size_guest++;
}

void Database::addAdmin() {
	string usern, password;
	cout << "User Name: "; cin >> usern;
	cout << "\nPassword: "; cin >> password;

	for (size_t i = 0; i < size_admin && size_admin > 0; i++)
	{
		if (admins[i]->getName() == usern) throw DatabaseException("User Already exists", __LINE__, "My Exception");
	}
	Admin* chg = new Admin(usern, password);

	auto temp = new Admin * [size_admin + 1];
	for (size_t i = 0; i < size_admin && size_admin > 0; i++)
	{
		temp[i] = new Admin();
		temp[i] = admins[i];
	}
	temp[size_admin] = new Admin();
	temp[size_admin] = chg;

	if (size_admin > 0) delete[] admins;
	admins = temp;
	file_txt_write_admin(temp[size_admin]);
	size_admin++;
}

void Database::addProduct() {
	string str;
	double integer;
	double integer2;
	cout << "Name of the product: "; getline(cin, str); getline(cin, str);
	cout << "\nSet amount of the product: "; cin >> integer;

	for (size_t i = 0; i < size_product && size_product > 0; i++)
	{
		if (products[i]->getName() == str) {
			products[i]->setCount(products[i]->getCount() + integer);
			file_txt_write_product(products, size_product);
			budce -= products[i]->getPrice() * integer;
			file_txt_write_budce(budce);
			return;
			//throw DatabaseException("Already got that product. Added to ist count!", __LINE__, "My Exception");
		}
	}

	Product* chg = new Product();
	chg->setName(str);
	chg->setCount(integer);
	cout << "\nSet Price: "; cin >> integer2;
	chg->setPrice(integer2);
	budce -= integer2 * integer;

	auto temp = new Product * [size_product + 1];
	for (size_t i = 0; i < size_product && size_product > 0; i++)
	{
		temp[i] = new Product();
		temp[i] = products[i];
	}
	temp[size_product] = new Product();
	temp[size_product] = chg;

	if (size_product > 0) delete[] products;
	products = temp;
	file_txt_writeapp_product(temp[size_product]);
	file_txt_write_budce(budce);
	size_product++;
}

void Database::deleteProductByID() {
	if (size_product == 0) throw DatabaseException("Empty", __LINE__, "My Exception");

	int id;
	cout << "ID of the product you want to delete (Press 0 to go back): "; cin >> id;
	if (id == 0) return;

	auto temp = new Product * [size_product - 1];
	bool test = false;
	for (size_t i = 0, j = 0; j < size_product; i++, j++)
	{
		if (products[j]->getID() == id) {
			test = true;
			i--;
			continue;
		}
		temp[i] = new Product();
		temp[i] = products[j];
	}
	if (test = false) throw DatabaseException("Such ID doesnt exist", __LINE__, "My Exception");

	if (size_product > 0) delete[] products;
	products = temp;
	size_product--;
	file_txt_write_product(products, size_product);
}

void Database::addMeal() {
	Meal* chg = new Meal();
	string n; int p;
	cout << "Name o the food: "; getline(cin, n); getline(cin, n);
	chg->setName(n);
	cout << "\nPrice: "; cin >> p;
	chg->setPrice(p);
	cout << "\nDescribtion: "; getline(cin, n); getline(cin, n);
	chg->setDesc(n);

	Product* cc = new Product();

	system("cls");
	cout << "Add ingredient name: "; getline(cin, n);
	cc->setName(n);
	cout << "\nCount: "; cin >> p;
	cc->setCount(p);
	chg->addIngredient(cc);

	file_txt_writeapp_ingredient(cc);

	auto temp = new Meal * [size_meal + 1];
	for (size_t i = 0; i < size_meal && size_meal > 0; i++)
	{
		temp[i] = new Meal();
		temp[i] = meals[i];
	}
	temp[size_meal] = new Meal();
	temp[size_meal] = chg;

	if (size_meal > 0) delete[] meals;
	meals = temp;
	file_txt_writeapp_meal(temp[size_meal]);
	size_meal++;
}

void Database::deleteMealByID() {
	if (size_meal == 0) throw DatabaseException("Empty", __LINE__, "My Exception");

	int id;
	cout << "ID of the meal you want to delete (Type 0 to go back): "; cin >> id;
	if (id == 0) return;

	auto temp = new Meal * [size_meal - 1];
	bool test = false;
	for (size_t i = 0, j = 0; j < size_meal; i++, j++)
	{
		if (meals[j]->getID() == id) {
			test = true;
			i--;
			continue;
		}
		temp[i] = new Meal();
		temp[i] = meals[j];
	}
	if (test == false) throw DatabaseException("Such ID doesnt exist", __LINE__, "My Exception");

	if (size_meal > 0) delete[] meals;
	meals = temp;
	size_meal--;
	file_txt_write_meal(meals, size_meal);

	file_txt_write_ingredient(meals, size_meal);
}

void Database::LoginAsAdmin() {
	string n, p;
	bool test = false;
	cout << "Username: "; cin >> n;
	cout << "\nPassword: "; cin >> p;
	for (size_t i = 0; i < size_admin && size_admin > 0; i++)
	{
		if (admins[i]->getName() == n) {
			if (admins[i]->getPass() == p) cout << "\n\nAccess guarantee";
			else throw DatabaseException("Wrong Pass", __LINE__, "My Exception");
			test = true;
			break;
		}
	}
	if (test == false) throw DatabaseException("Admin doesnt exist", __LINE__, "My Exception");
}

void Database::LoginAsGuest() {
	string n, p;
	bool test = false;
	cout << "Username: "; cin >> n;
	cout << "\nPassword: "; cin >> p;
	for (size_t i = 0; i < size_guest; i++)
	{
		if (guests[i]->getName() == n) {
			if (guests[i]->getPass() == p) cout << "\n\nAccess guarantee";
			else throw DatabaseException("Wrong Pass", __LINE__, "My Exception");
			test = true;
			break;
		}
	}
	if (test == false) throw DatabaseException("Guest doesnt exist", __LINE__, "My Exception");
}

void Database::addIng(Meal*& chg) {
	string n; int c;
	cout << "Name of the ingredient: "; getline(cin, n); getline(cin, n);
	for (size_t i = 0; i < chg->getSize(); i++)
	{
		if (chg->ingredients[i]->getName() == n)
			throw DatabaseException("This Ing already exist", __LINE__, "My Eception");
	}
	Product* ing = new Product();
	ing->setName(n);
	cout << "\nCount: "; cin >> c;
	ing->setCount(c);
	chg->addIngredient(ing);
	file_txt_writeapp_ingredient(ing);
}

void Database::deleteIng(Meal*& chg) {
	string n;
	cout << "Name of the ingredient: "; getline(cin, n); getline(cin, n);;
	for (size_t i = 0; i < chg->getSize(); i++)
	{
		if (chg->ingredients[i]->getName() == n)
			goto a;
	}
	throw DatabaseException("This Ing doesnt exist", __LINE__, "My Eception");
a:
	chg->deleteIngredient(n);
	file_txt_write_ingredient(meals, size_meal);
}

void Database::updateMeal(Meal*& chg) {
	string* m = new string[3]{ "Update price", "Add ingredient", "Delete ingredient" };

	string n;
	int c;

	for (size_t i = 0; true;)
	{
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		chg->Show();
		cout << "\n\n\n";
		for (size_t w = 0; w < 3; w++)
		{
			cout << m[w] << endl;
		}

		cin >> i;

		if (i == 0) {
			cout << "\n\nNew Price: "; cin >> c;
			try
			{
				chg->setPrice(c);
			}
			catch (MyException& ex)
			{
				ex.Message();
			}
		}
		else if (i == 1) {
			cout << "\n\n";
			try
			{
				addIng(chg);
			}
			catch (MyException& ex)
			{
				ex.Message();
			}
		}
		else {
			cout << "\n\n";
			try
			{
				deleteIng(chg);
			}
			catch (MyException& ex)
			{
				ex.Message();
			}
		}
		break;
	}
}

void Database::CheckProductCount() {
	cout << "\n\n";
	cout << "Products that are need to be added\n*****************************\n";
	bool test;

	for (size_t y = 0; y < size_meal; y++) {
		for (size_t i = 0; i < meals[y]->getSize(); i++)
		{
			test = false;
			for (size_t j = 0; j < size_product; j++)
			{
				if (meals[y]->ingredients[i]->getName() == products[j]->getName()) {
					test = true;
					if (products[j]->getCount() < meals[y]->ingredients[i]->getCount()) {
						cout << "\n" << meals[y]->ingredients[i]->getName() << "  " << meals[y]->ingredients[i]->getCount() - products[j]->getCount();
					}
					break;
				}
			}
			if (test == false) cout << "\n" << meals[y]->ingredients[i]->getName() << "  " << meals[y]->ingredients[i]->getCount();
		}
	}
}


int Database::getSizeAdmin() { return size_admin; }
int Database::getSizeGuest() { return size_guest; }
int Database::getSizeProduct() { return size_product; }
int Database::getSizeMeal() { return size_meal; }
int Database::getBudce() { return budce; }

void Database::setSizeAdmin(int a) { if (a < 0) size_admin = 0; else size_admin = a; }
void Database::setSizeGuest(int a) { if (a < 0) size_guest = 0; else size_guest = a; }
void Database::setSizeProduct(int a) { if (a < 0) size_product = 0; else size_product = a; }
void Database::setSizeMeal(int a) { if (a < 0) size_meal = 0; else size_meal = a; }
void Database::setBudce(int a) { if (a < 0) budce = 0; else budce = a; }