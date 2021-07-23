#include "MyException.h"

MyException::MyException(const string& text, const int& line, const string& source) : text(text), source(source), line(line) {}
void MyException::Message() const {
	for (int i = 0; i < 3; i++)
	{
		system("cls");
		if (i % 2) system("color 4");
		else system("color 9");
		cout << "*******Exception Info*******\n";
		cout << "Text: " << text << endl;
		cout << "Line: " << line << endl;
		cout << "Source: " << source << endl;
		Sleep(500);
	}
}

DatabaseException::DatabaseException(const string& text, const int& line, const string& source) : MyException(text, line, source) {}

InvalidArgumentException::InvalidArgumentException(const string& text, const int& line, const string& source) : MyException(text, line, source) {}