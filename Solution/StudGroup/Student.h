#pragma once

using namespace std;

struct DoB {
	int day;
	int month;
	int year;

	DoB();
	DoB(int _day, int _month, int _year);
	DoB(string& dt);
	const DoB& operator = (const DoB& _date);
	friend istream& operator >> (istream& in, DoB& date);
	friend ostream& operator << (ostream& out, const DoB& date);
	bool operator == (const DoB& _date) const;
};

struct Student {
	string name;
	string surname;
	string phone;
	DoB date;

	Student();
	Student(const string& _name, const string& _surname, const string& _phone, const DoB& _date);
	Student(const Student& stud);
	const Student& operator= (const Student& _stud);
	bool operator == (const Student& st) const;
	friend istream& operator >> (istream& in, Student& stud);
	friend ostream& operator << (ostream& out, const Student& stud);
};
