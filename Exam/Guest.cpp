#include "Guest.h"

Guest::Guest() {
	username = "";
}

Guest::Guest(string u, string p) {
	setUsern(u);
	setPass(p);
}

Guest& Guest::operator=(Guest& chg) {
	setUsern(chg.username);
	setPass(chg.password);
	return*this;
}

void Guest::setUsern(string u) {
	if (u.size() < 6) throw InvalidArgumentException("Username uzunlugu 6dan asagi ola bilmez", __LINE__, "My Exception");
	username = u;
}
void Guest::setPass(string p) {
	if (p.size() < 6) throw InvalidArgumentException("Password uzunlugu 6dan asagi ola bilmez", __LINE__, "My Exception");
	password = p;
}

string Guest::getName() const { return username; }
string Guest::getPass() const { return password; }

Guest::~Guest() {}