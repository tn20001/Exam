#pragma once
#pragma once
#include <iostream>
#include <Windows.h>

using namespace std;

class MyException {
protected:
	string text, source;
	int line;
	MyException(const string& text, const int& line, const string& source);
public:
	void Message() const;
};


class DatabaseException : public MyException {
public:
	DatabaseException(const string& text, const int& line, const string& source);
};


class InvalidArgumentException : public MyException {
public:
	InvalidArgumentException(const string& text, const int& line, const string& source);
};
