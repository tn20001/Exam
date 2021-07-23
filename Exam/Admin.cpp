#include "Admin.h"

Admin::Admin() {
	username = "";
	password = "";
}

Admin::Admin(string u, string p) {
	setUsern(u);
	setPass(p);
}

Admin& Admin::operator=(Admin& chg) {
	setUsern(chg.username);
	setPass(chg.password);
	return*this;
}

void Admin::setUsern(string u) {
	if (u.size() < 6) throw InvalidArgumentException("Username uzunlugu 6dan asagi ola bilmez", __LINE__, "My Exception");
	username = u;
}
void Admin::setPass(string p) {
	if (p.size() < 6) throw InvalidArgumentException("Password uzunlugu 6dan asagi ola bilmez", __LINE__, "My Exception");
	password = p;
}

string Admin::getName() const { return username; }
string Admin::getPass() const { return password; }


Admin::~Admin() {}