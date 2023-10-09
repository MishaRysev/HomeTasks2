#include <iostream>
#include <fstream>
#include "Group.h"

using namespace std;

Group::Group() {
	size = 10;
	cnt = 0;
	studs = new Student * [size];
}

Group::Group(string& path) {
	ifstream in;
	Student* tmp;
	in.open(path);
	in >> cnt;
	studs = new Student * [cnt + 5];
	size = cnt + 5;
	if (in.is_open()) {
		for (int i = 0; i < cnt; i++) {
			studs[i] = new Student;
			in >> *studs[i];
		}
	}
}

Group::~Group() {
	for (int i = 0; i < cnt; i++) delete studs[i];
	delete[] studs;
}

ostream& operator << (ostream& out, const Group& group) {
	for (int i = 0; i < group.cnt; i++) cout << *group.studs[i];
	return out;
}

int* Group::search(string& param, int type, int& fc) const {
	DoB *dt = nullptr;
	int* mas = nullptr;
	if (cnt == 0) return mas;
	if (type == 4) dt = new DoB(param);
	for (int i = 0; i < cnt; i++) {
		if (type == 4) {
			if (studs[i]->date == *dt) fc += 1;
		}
		else {
				if (studs[i]->name == param && type == 1) fc += 1;
				else if (studs[i]->surname == param && type == 2) fc += 1;
				else if (studs[i]->phone == param && type == 3) fc += 1;
			}
		}
	if (fc == 0) return mas;
	mas = new int[fc];
	int j = 0;
	for (int i = 0; i < cnt; i++) {
		if (type == 4) {
			if (studs[i]->date == *dt){ 
				mas[j] = i;
				j += 1;
			}
		}
		else {
			if (studs[i]->name == param && type == 1) {
				mas[j] = i;
				j += 1;
			}
			else if (studs[i]->surname == param && type == 2) {
				mas[j] = i;
				j += 1;
			}
			else if (studs[i]->phone == param && type == 3) {
				mas[j] = i;
				j += 1;
			}
		}
	}
	return mas;
}

int Group::in_group(const Student& st) const {
	for (int i = 0; i < cnt; i++) {
		if (*studs[i] == st) return i;
	}
	return -1;
}

void Group::realloc() {
	size += step;
	Student** new_studs = new Student * [size];
	for (int i = 0; i < cnt; i++) {
		new_studs[i] = studs[i];
	}
	delete[] studs;
	studs = new_studs;
}

void Group::add(const Student& st) {
	if (cnt == size) realloc();
	if (in_group(st) != -1) cout << "Already in the group\n";
	else {
		studs[cnt] = new Student(st);
		cnt += 1;
	}
}

void Group::remove(const Student& st) {
	int ind = in_group(st);
	if (ind == -1) cout << "Already not in the group\n";
	else {
		for (int i = ind; i < cnt; i++) studs[i] = studs[i + 1];
		if (ind == cnt) delete studs[ind];
		cnt -= 1;
	}
}