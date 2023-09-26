#include <iostream>
#include <string>
#include <fstream>
#include "Student.h"

using namespace std;

DoB::DoB() {
	day = 0;
	month = 0;
	year = 0;
}

const DoB& DoB::operator = (const DoB& _date) {
	day = _date.day;
	month = _date.month;
	year = _date.year;
	return (*this);
}

bool DoB::operator == (const DoB& _date) const {
	if (day == _date.day && month == _date.month && year == _date.year) return true;
	return false;
}

DoB::DoB(int _day, int _month, int _year) {
	day = _day;
	month = _month;
	year = _year;
}

DoB::DoB(string& dt) {
	string part;
	int i = 0, mas[3], j = 0;
	dt += ".\0";
	while (dt[i] != '\0') {
		if (dt[i] == '.') {
			mas[j] = stoi(part);
			j += 1;
			part = "";
		}
		else part += dt[i];
		i += 1;
	}
	day = mas[0];
	month = mas[1];
	year = mas[2];
}

istream& operator >> (istream& in, DoB& date) {
	string dt, part;
	int i = 0, mas[3], j = 0;
	in >> dt;
	dt += ".\0";
	while (dt[i] != '\0') {
		if (dt[i] == '.') {
			mas[j] = stoi(part);
			j += 1;
			part = "";
		}
		else part += dt[i];
		i += 1;
	}
	date.day = mas[0];
	date.month = mas[1];
	date.year = mas[2];
	return in;
}
ostream& operator << (ostream& out, const DoB& date) {
	cout << date.day << '.' << date.month << '.' << date.year << endl;
	return out;
}



Student::Student() {
	name = " ";
	surname = " ";
	phone = " ";
	date = DoB();
}

Student::Student(const string& _name, const string& _surname, const string& _phone, const DoB& _date) {
	name = _name;
	surname = _surname;
	phone = _phone;
	date = _date;
}

Student::Student(const Student& stud) {
	name = stud.name;
	surname = stud.surname;
	phone = stud.phone;
	date = stud.date;
}

const Student& Student::operator= (const Student& _stud) {
	name = _stud.name;
	surname = _stud.surname;
	phone = _stud.phone;
	date = _stud.date;
	return (*this);
}

bool Student::operator == (const Student& st) const {
	if (name == st.name && surname == st.surname && phone == st.phone && date == st.date) return true;
	return false;
}

istream& operator >> (istream& in, Student& stud) {
	in >> stud.name >> stud.surname >> stud.phone >> stud.date;
	return in;
}

ostream& operator << (ostream& out, const Student& stud) {
	out << stud.name << " " << stud.surname << " " << stud.phone << " " << stud.date;
	return out;
}