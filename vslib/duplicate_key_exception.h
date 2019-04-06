#ifndef DUPLICATE_KEY_EXCEPTION_H
#define DUPLICATE_KEY_EXCEPTION_H

#include<iostream>
#include<cstring>

namespace vip {
	template<class T>
	class DuplicateKeyException;
}

template<class T>
class vip::DuplicateKeyException : public exception {
private:
	T key;
	
public:
	void setKey(T key);
	const char* what();
};

template<class T>
void vip::DuplicateKeyException<T>::setKey(T key) {
	this->key = key;
}

template<class T>
const char* vip::DuplicateKeyException<T>::what() {
	return "DuplicateKeyException: Binary Search Tree cannot store duplicate keys.";
}

#endif
