#include "Restourant.h"

void Restourant() {
	Database database;
	database.setSizeAdmin(file_txt_read_admin(database.admins));
	database.setSizeMeal(file_txt_read_meal(database.meals));
	file_txt_read_ingredient(database.meals, database.getSizeMeal());
	database.setSizeProduct(file_txt_read_product(database.products));
	database.setSizeGuest(file_txt_read_guest(database.guests));
	database.setBudce(file_txt_read_budce());

	bool a = false;

	string* main = new string[4]{ "Login as Guest", "Login as Admin", "Register as Guest", "Register as Admin" };
	string* admin_menu = new string[5]{ "Add Meal", "Delete Meal", "Update Meal", "Add Product", "Delete Product" };

	for (int i = 0; true;)
	{
		system("cls");
		for (size_t j = 0; j < 4; j++)
		{
			cout << main[j] << endl;
		}

		cin >> i;

		if (i == 0) {
			a = false;
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
			try
			{
				database.LoginAsGuest();
			}
			catch (MyException& ex)
			{
				ex.Message();
				a = true;
			}
			if (a == false) {
				cout << "Hazir deyil :(";
			}

		}

		else if (i == 1) {
			a = false;
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);

			try
			{
				database.LoginAsAdmin();
			}
			catch (MyException& ex)
			{
				ex.Message();
				a = true;
			}

			for (int i = 0; a == false;) {
				system("cls");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
				cout << "Budget: " << database.getBudce() << "\n********************\n\n";
				for (size_t j = 0; j < 5; j++)
				{
					cout << admin_menu[j] << endl;
				}
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
				database.CheckProductCount();

				cin >> i;

				if (i == 0) {
					system("cls");
					try
					{
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
						database.addMeal();
					}
					catch (MyException& ex)
					{
						ex.Message();
					}
				}

				else if (i == 1) {
					system("cls");
					for (size_t i = 0; i < database.getSizeMeal(); i++)
					{
						database.meals[i]->Show();
						cout << "\n--------------------------";
						cout << "\n\n";
					}
					try
					{
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
						database.deleteMealByID();
					}
					catch (MyException& ex)
					{
						ex.Message();
					}
				}

				else if (i == 2) {
					for (int i = 0; true;)
					{
						system("cls");
						for (size_t j = 0; j < database.getSizeMeal(); j++)
						{
							cout << database.meals[j]->getName() << endl;
						}
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
						cout << "-----------------------------";

						cin >> i;

						cout << "\n\n";
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
						database.updateMeal(database.meals[i]);
						file_txt_write_meal(database.meals, database.getSizeMeal());

					}
				}

				else if (i == 3) {
					system("cls");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
					try
					{
						database.addProduct();
					}
					catch (MyException& ex)
					{
						ex.Message();
					}
				}

				else {
					system("cls");
					for (size_t i = 0; i < database.getSizeProduct(); i++)
					{
						database.products[i]->Show();
						cout << "\n-----------------------------\n\n";
					}
					cout << "\n\n";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
					try
					{
						database.deleteProductByID();
					}
					catch (MyException& ex)
					{
						ex.Message();
					}
				}

			}
		}

		else if (i == 2) {
			system("cls");
			try
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
				database.addGuest();
			}
			catch (MyException& ex)
			{
				ex.Message();
			}
		}

		else if (i == 3) {
			system("cls");
			try
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
				database.addAdmin();
			}
			catch (MyException& ex)
			{
				ex.Message();
			}
		}

	}
}
