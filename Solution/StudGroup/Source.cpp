#include <iostream>
#include <fstream>
#include "Source.h"

using namespace std;

void read_path(string& path) {
	int flag = 1;
	ifstream in;
	cout << "Enter path: ";
	do {
		cin >> path;
		in.open(path);
		if (in.is_open()) {
			flag = 0;
			in.close();
		}
		else {
			cout << "Path not found. Enter new path:\n";
		}
	} while (flag);
}

void actions() {
	cout << "Choose action(enter number):\n";
	cout << "  1. Print group   3. Add student\n  2. Find student  4. Remove student\n";
}
void finding(Group& group) {
	int num;
	string param;
	cout << "Enter number of the type of search:\n";
	cout << "  1. By name      3. By phone\n  2. By surname   4. By date\n>> ";
	cin >> num;
	if (num == 1) cout << "Enter name: ";
	else if (num == 2) cout << "Enter surname: ";
	else if (num == 3) cout << "Enter phone: ";
	else if (num == 4) cout << "Enter date: ";
	else cout << "Not found";
	cin >> param;
	group.search(param, num);
}
void student_data(Student& tmp) {
	cout << "Enter name: "; cin >> tmp.name;
	cout << "Enter surname: "; cin >> tmp.surname;
	cout << "Enter phone: "; cin >> tmp.phone;
	cout << "Enter date: "; cin >> tmp.date;
}
void addition(Group& group) {
	Student tmp;
	student_data(tmp);
	group.add(tmp);
}
void removing(Group& group) {
	Student tmp;
	student_data(tmp);
	group.remove(tmp);
}

void proc(Group& group) {
	int key;
	actions();
	do {
		cout << ">> ";
		cin >> key;
		if (key == 1) cout << group;
		else if (key == 2) finding(group);
		else if (key == 3) addition(group);
		else if (key == 4) removing(group);
	} while (key != 0);
}