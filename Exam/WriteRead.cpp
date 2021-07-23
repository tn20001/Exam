#include "WriteRead.h"

void file_txt_write_admin(Admin*& chg) {
	//ofstream fout("hakuna.txt"); // by default: ios_base::out
	//ofstream fout("Admin.txt", ios_base::out); // write mode
	ofstream fout("Admin.txt", ios_base::app); // append mode
	if (!fout)
		throw "File not found";
	if (fout.is_open()) {
		fout << setw(20) << chg->getName() << " " << setw(20) << chg->getPass() << endl;
	}
	else
		throw "File is closed";
	fout.close();
}

int file_txt_read_admin(Admin**& chg) {
	ifstream fin("Admin.txt", ios::in);
	int size = -1;
	string n;
	while (!fin.eof() && fin.is_open()) {
		getline(fin, n);
		size++;
	}
	if (size <= 0) return 0;
	fin.clear();
	fin.seekg(0);
	string p;
	int i = 0;

	if (fin.is_open()) {
		//fin >> value;

		//while (!fin.eof())
		chg = new Admin * [size];

		while (i < size) {
			chg[i] = new Admin();
			fin >> n;
			chg[i]->setUsern(n);
			fin >> p;
			chg[i]->setPass(p);
			i++;
		}
	}
	fin.close();
	return size;
}



void file_txt_write_guest(Guest*& chg) {
	//ofstream fout("hakuna.txt"); // by default: ios_base::out
	//ofstream fout("Admin.txt", ios_base::out); // write mode
	ofstream fout("Guest.txt", ios_base::app); // append mode
	if (!fout)
		throw "File not found";
	if (fout.is_open()) {
		fout << setw(20) << chg->getName() << " " << setw(20) << chg->getPass() << endl;
	}
	else
		throw "File is closed";
	fout.close();
}

int file_txt_read_guest(Guest**& chg) {
	ifstream fin("Guest.txt", ios::in);
	int size = -1;
	string n;
	while (!fin.eof() && fin.is_open()) {
		getline(fin, n);
		size++;
	}
	if (size <= 0) return 0;
	fin.clear();
	fin.seekg(0);
	string p;
	int i = 0;

	if (fin.is_open()) {
		//fin >> value;

		//while (!fin.eof())
		chg = new Guest * [size];

		while (i < size) {
			chg[i] = new Guest();
			fin >> n;
			chg[i]->setUsern(n);
			fin >> p;
			chg[i]->setPass(p);
			i++;
		}
	}
	fin.close();
	return size;
}



void file_txt_writeapp_product(Product*& chg) {
	//ofstream fout("hakuna.txt"); // by default: ios_base::out
	//ofstream fout("Admin.txt", ios_base::out); // write mode
	ofstream fout("Product.txt", ios_base::app); // append mode
	if (!fout)
		throw "File not found";
	if (fout.is_open()) {
		fout << chg->getName() << "\n" << chg->getPrice() << "\n" << chg->getCount() << endl;
	}
	else
		throw "File is closed";
	fout.close();
}

void file_txt_write_product(Product**& chg, int size) {
	//ofstream fout("hakuna.txt"); // by default: ios_base::out
	ofstream fout("Product.txt", ios_base::out); // write mode
	//ofstream fout("hakuna.txt", ios_base::app); // append mode
	if (!fout)
		throw "File not found";
	if (fout.is_open()) {
		for (size_t i = 0; i < size; i++)
		{
			fout << chg[i]->getName() << "\n" << chg[i]->getPrice() << "\n" << chg[i]->getCount() << endl;
		}
	}
	else
		throw "File is closed";
	fout.close();
}

int file_txt_read_product(Product**& chg) {
	ifstream fin("Product.txt", ios::in);
	int size = -1;
	string n;
	while (!fin.eof() && fin.is_open()) {
		getline(fin, n);
		size++;
	}
	if (size <= 0) return 0;
	size /= 3;
	fin.clear();
	fin.seekg(0);
	int p;
	int c;
	int i = 0;

	if (fin.is_open()) {
		//fin >> value;

		//while (!fin.eof())
		chg = new Product * [size];

		while (i < size) {
			chg[i] = new Product();
			getline(fin, n);
			if (n.size() == 0) getline(fin, n);
			chg[i]->setName(n);
			fin >> p;
			chg[i]->setPrice(p);
			fin >> c;
			chg[i]->setCount(c);
			i++;
		}
	}
	fin.close();
	return size;
}



void file_txt_write_meal(Meal**& chg, int size) {
	//ofstream fout("hakuna.txt"); // by default: ios_base::out
	ofstream fout("Meal.txt", ios_base::out); // write mode
	//ofstream fout("hakuna.txt", ios_base::app); // append mode
	if (!fout)
		throw "File not found";
	if (fout.is_open()) {
		for (size_t i = 0; i < size; i++)
		{
			fout << chg[i]->getName() << "\n" << chg[i]->getPrice() << "\n" << chg[i]->getDesc() << "\n" << chg[i]->getSize() << endl;
		}
	}
	else
		throw "File is closed";
	fout.close();
}

void file_txt_writeapp_meal(Meal*& chg) {
	//ofstream fout("hakuna.txt"); // by default: ios_base::out
	//ofstream fout("Admin.txt", ios_base::out); // write mode
	ofstream fout("Meal.txt", ios_base::app); // append mode
	if (!fout)
		throw "File not found";
	if (fout.is_open()) {
		fout << chg->getName() << "\n" << chg->getPrice() << "\n" << chg->getDesc() << "\n" << chg->getSize() << endl;
	}
	else
		throw "File is closed";
	fout.close();
}

int file_txt_read_meal(Meal**& chg) {
	ifstream fin("Meal.txt", ios::in);
	int size = -1;
	string n;
	while (!fin.eof() && fin.is_open()) {
		getline(fin, n);
		size++;
	}
	if (size <= 0) return 0;
	size /= 4;
	fin.clear();
	fin.seekg(0);
	int p;
	string d;
	int c;
	int i = 0;

	if (fin.is_open()) {
		//fin >> value;

		//while (!fin.eof())
		chg = new Meal * [size];

		while (i < size) {
			chg[i] = new Meal();
			getline(fin, n);
			if(n.size() == 0) getline(fin, n);
			chg[i]->setName(n);
			fin >> p;
			chg[i]->setPrice(p);
			getline(fin, d);
			if (d.size() == 0) getline(fin, d);
			chg[i]->setDesc(d);
			fin >> c;
			chg[i]->setSize(c);
			i++;
		}
	}
	fin.close();
	return size;
}



void file_txt_write_ingredient(Meal**& chg, int size) {
	//ofstream fout("hakuna.txt"); // by default: ios_base::out
	ofstream fout("Ingredient.txt", ios_base::out); // write mode
	//ofstream fout("hakuna.txt", ios_base::app); // append mode
	if (!fout)
		throw "File not found";
	if (fout.is_open()) {
		for (size_t i = 0; i < size; i++)
		{
			for (size_t j = 0; j < chg[i]->getSize(); j++)
			{
				fout << chg[i]->ingredients[j]->getName() << "\n" << chg[i]->ingredients[j]->getCount() << endl;
			}
		}
	}
	else
		throw "File is closed";
	fout.close();
}

void file_txt_writeapp_ingredient(Product*& chg) {
	//ofstream fout("hakuna.txt"); // by default: ios_base::out
	//ofstream fout("Admin.txt", ios_base::out); // write mode
	ofstream fout("Ingredient.txt", ios_base::app); // append mode
	if (!fout)
		throw "File not found";
	if (fout.is_open()) {
		fout << chg->getName() << "\n" << chg->getCount() << endl;
	}
	else
		throw "File is closed";
	fout.close();
}

void file_txt_read_ingredient(Meal**& chg, int size_meal) {
	ifstream fin("Ingredient.txt", ios::in);
	int size = -1;
	string n;
	while (!fin.eof() && fin.is_open()) {
		getline(fin, n);
		size++;
	}
	if (size <= 0) return;
	size /= 2;
	fin.clear();
	fin.seekg(0);
	int c;
	int i = 0;

	if (fin.is_open()) {
		//fin >> value;

		//while (!fin.eof())

		while (i < size_meal) {
			chg[i]->ingredients = new Product * [chg[i]->getSize()]{};
			for (size_t j = 0; j < chg[i]->getSize(); j++) {
				chg[i]->ingredients[j] = new Product();
				getline(fin, n);
				if (n.size() == 0) getline(fin, n);
				chg[i]->ingredients[j]->setName(n);
				fin >> c;
				chg[i]->ingredients[j]->setCount(c);
			}

			i++;
		}
	}
	fin.close();
}



void file_txt_write_budce(int budce) {
	//ofstream fout("hakuna.txt"); // by default: ios_base::out
	ofstream fout("Budce.txt", ios_base::out); // write mode
	//ofstream fout("hakuna.txt", ios_base::app); // append mode
	if (!fout)
		throw "File not found";
	if (fout.is_open()) {
		fout << budce;
	}
	else
		throw "File is closed";
	fout.close();
}

int file_txt_read_budce() {
	ifstream fin("Budce.txt", ios::in);
	int c = 10000;

	if (fin.is_open()) {
		//fin >> value;

		//while (!fin.eof())
		fin >> c;
		
	}
	fin.close();
	return c;
}