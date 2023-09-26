#include <iostream>
#include "Source.h"
#include "Group.h"

using namespace std;

int main() {
	system("chcp 1251");

	string path;
	read_path(path);
	Group group(path);
	proc(group);

	return 0;
}