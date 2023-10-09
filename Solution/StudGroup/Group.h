#pragma once
#include "Student.h"

class Group {
private:
	unsigned int size;
	unsigned int cnt;
	unsigned int step = 10;
	Student** studs;
	void realloc();
public:
	Group();
	Group(string& path);
	~Group();
	
	friend ostream& operator << (ostream& out, const Group& group);

	Student* get_stud(int num) const { return studs[num]; }
	int* search(string& param, int type, int& fc) const;
	int in_group(const Student& st) const;
	void add(const Student& st);
	void remove(const Student& st);
};