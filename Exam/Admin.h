#pragma once
#include "MyException.h"

class Admin {
	string username;
	string password;
public:

	Admin();

	Admin(string u, string p);

	Admin& operator=(Admin& chg);

	void setUsern(string u);
	void setPass(string p);

	string getName() const;
	string getPass() const;


	~Admin();

};