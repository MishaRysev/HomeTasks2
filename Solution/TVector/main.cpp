#include <iostream>
#include "TVector.h"

using namespace std;

int main() {
	// создание, считывание, вывод
	TVector<int> vec1, vec2, vec3, vec4, vec5, vec6;
	cin >> vec1; 
	cout << vec1 << endl << endl;

	// +=, -=, *= (на const)
	cin >> vec2 >> vec3;
	vec2 += vec3;
	cin >> vec4 >> vec5;
	vec4 -= vec5;
	cin >> vec6;
	vec6 *= 10;
	cout << "vec2: " << vec2 << endl << "vec4: " << vec4 << endl << "vec6: " << vec6 << endl << endl;
	
	// +, -, *
	TVector <int> vec7 = vec3 + vec5;
	TVector <int> vec8 = vec3 - vec5;
	TVector <int> vec9 = vec3 * 10;
	double n = vec3 * vec5;
	cout << "vec7: " << vec7 << endl << "vec8: " << vec8 << endl << "vec9: " << vec9 << endl << "n: " << n << endl << endl;

	//норма, cos, сравнения
	TVector <int> vec10, vec11;
	cin >> vec10 >> vec11;
	cout << vec10.length() << " | " << vec11.length() << endl;
	cout << cos(vec10, vec11) << endl;
	cout << (vec10 == vec11) << " | " << (vec10 != vec11);
	return 0;
}