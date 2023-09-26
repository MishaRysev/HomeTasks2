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

	void search(string& param, int type) const;
	int in_group(const Student& st) const;
	void add(const Student& st);
	void remove(const Student& st);
};