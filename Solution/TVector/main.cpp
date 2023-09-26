#include <iostream>
#include "TVector.h"

using namespace std;

int main() {
	TVector<int> vec1, vec2, vec3;
	cin >> vec1; 

	TVector<int> vec4(vec1);
	vec4 *= 10;
	cout << vec4;
	return 0;
}