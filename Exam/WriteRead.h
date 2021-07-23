#pragma once
#include "Guest.h"
#include "Admin.h"
#include "Meal.h"
#include <sstream>
#include <fstream>
#include <istream>
#include <iomanip>

void file_txt_write_admin(Admin*& chg);

int file_txt_read_admin(Admin**& chg);



void file_txt_write_guest(Guest*& chg);

int file_txt_read_guest(Guest**& chg);



void file_txt_writeapp_product(Product*& chg);

void file_txt_write_product(Product**& chg, int size);

int file_txt_read_product(Product**& chg);



void file_txt_write_meal(Meal**& chg, int size);

void file_txt_writeapp_meal(Meal*& chg);

int file_txt_read_meal(Meal**& chg);



void file_txt_write_ingredient(Meal**& chg, int size);

void file_txt_writeapp_ingredient(Product*& chg);

void file_txt_read_ingredient(Meal**& chg, int size_meal);



void file_txt_write_budce(int budce);

int file_txt_read_budce();