#pragma once
#include "MyException.h"

class Guest {
	string username;
	string password;
public:

	Guest();

	Guest(string u, string p);

	Guest& operator=(Guest& chg);

	void setUsern(string u);
	void setPass(string p);

	string getName() const;
	string getPass() const;

	~Guest();
};