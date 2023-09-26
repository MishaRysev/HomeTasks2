#pragma once
#include <cmath>

template <typename T>
class TVector {
private:
	T* arr;
	int count;
public:
	TVector();
	TVector(int _count);
	TVector(const TVector& vec);
	~TVector();

	friend std::istream& operator >> (std::istream& in, TVector& vec) {
		in >> vec.count;
		vec.arr = new T[vec.count];
		for (int i = 0; i < vec.count; i++) in >> vec.arr[i];
		return in;
	}
	friend std::ostream& operator << (std::ostream& out, TVector& vec) {
		for (int i = 0; i < vec.count; i++) out << vec.arr[i] << " ";
		return out;
	}
	friend float cos(TVector<T>& a, TVector<T>& b) {
		float res = (a * b) / (a.length() * b.length());
		return res;
	}

	float length() const;

	const TVector<T>& operator = (const TVector<T>& vec);
	TVector<T>& operator += (const TVector<T>& vec);
	TVector<T>& operator -= (const TVector<T>& vec);
	TVector<T>& operator *= (const T num);
	TVector<T> operator + (const TVector<T>& vec) const;
	TVector<T> operator - (const TVector<T>& vec) const;
	TVector<T> operator * (const T num) const;
	T operator * (const TVector<T>& vec) const;
	bool operator == (const TVector<T>& vec) const;
	bool operator != (const TVector<T>& vec) const;
};

template<typename T>
float TVector<T>::length() const {
	float res, s = 0;
	for (int i = 0; i < count; i++) s += arr[i] * arr[i];
	res = sqrtf(s);
	return res;
}

template<typename T>
TVector<T>::TVector() {
	count = 0;
	arr = nullptr;
}

template<typename T>
TVector<T>::~TVector() {
	count = 0;
	delete[] arr;
}

template<typename T>
TVector<T>::TVector(int _count) {
	count = _count;
	arr = new T[count];
	for (int i = 0; i < count; i++) arr[i] = 0;
}

template<typename T>
TVector<T>::TVector(const TVector& vec) {
	count = vec.count;
	arr = new T[count];
	for (int i = 0; i < count; i++) arr[i] = vec.arr[i];
}

template<typename T>
const TVector<T>& TVector<T>::operator = (const TVector<T>& vec) {
	count = vec.count;
	arr = new T[count];
	for (int i = 0; i < count; i++) arr[i] = vec.arr[i]; 
	return (*this);
}

template<typename T>
TVector<T>& TVector<T>::operator += (const TVector<T>& vec) {
	if (count != vec.count) throw "Different spaces";
	for (int i = 0; i < count; i++) arr[i] += vec.arr[i];
	return (*this);
}

template<typename T>
TVector<T>& TVector<T>::operator -= (const TVector<T>& vec) {
	if (count != vec.count) throw "Different spaces";
	for (int i = 0; i < count; i++) arr[i] -= vec.arr[i];
	return (*this);
}

template<typename T>
TVector<T>& TVector<T>::operator*= (T num) {
	for (int i = 0; i < count; i++) arr[i] *= num;
	return (*this);
}

template<typename T>
TVector<T> TVector<T>::operator + (const TVector<T>& vec) const {
	TVector<T> res(vec.count);
	if (count != vec.count) throw "Different spaces";
	for (int i = 0; i < count; i++) res.arr[i] = arr[i] + vec.arr[i];
	return res;
}

template<typename T>
TVector<T> TVector<T>::operator - (const TVector<T>& vec) const {
	TVector<T> res(vec.count);
	if (count != vec.count) throw "Different spaces";
	for (int i = 0; i < count; i++) res.arr[i] = arr[i] - vec.arr[i];
	return res;
}

template<typename T>
TVector<T> TVector<T>::operator * (const T num) const {
	TVector<T> res(count);
	for (int i = 0; i < count; i++) res.arr[i] = arr[i] * num;
	return res;
}

template <typename T>
T TVector<T>::operator * (const TVector<T>& vec) const {
	T res = 0;
	if (count != vec.count) throw "Different spaces";
	for (int i = 0; i < count; i++) res += arr[i] * vec.arr[i];
	return res;
}

template <typename T>
bool TVector<T>::operator == (const TVector<T>& vec) const {
	if (count != vec.count) return false;
	for (int i = 0; i < count; i++) {
		if (arr[i] != vec.arr[i]) return false;
	}
	return true;
}

template <typename T>
bool TVector<T>::operator != (const TVector<T>& vec) const {
	if (count != vec.count) return true;
	for (int i = 0; i < count; i++) {
		if (arr[i] != vec.arr[i]) return true;
	}
	return false;
}