#ifndef BINARY_SEARCH_TREE_HPP
#define BINARY_SEARCH_TREE_HPP

#include "duplicate_key_exception.h"
#include<iostream>
using namespace std;

namespace vip {
	template<class T>
	class BinarySearchTree;
	enum NEXT_FLAG{LEFT, RIGHT};
}

template <class T>
class vip::BinarySearchTree {
private:
	struct Node {
		T data;
		Node* left;
		Node* right;
	};
	Node* head;
	bool defaultFunction(T data1, T data2);
	bool (*compare)(T data1, T data2);

public:
	BinarySearchTree();
	/*
	Need for a constructor to set the custom compare function
	*/
	void insert(T data);
	//void deleteNodeByValue();
	void printPreOrder();
	void printPreOrder(Node* node);
	//void printInOrder();
	//void printPostOrder();
};

template<class T>
vip::BinarySearchTree<T>::BinarySearchTree() {
	head = NULL;
	//(*this.*compare) = defaultFunction;
}

template<class T>
bool vip::BinarySearchTree<T>::defaultFunction(T data1, T data2){
	/*
	return true if data1<data2;
	false if data1>data2;
	throw duplicate key exception if data1 = data2
	*/
	if (data1 == data2) {
		DuplicateKeyException<T> duplicateKeyException;
		duplicateKeyException.setKey(data1);
		throw duplicateKeyException;
	}
    return data1<data2;
}

template<class T>
void vip::BinarySearchTree<T>::insert(T data) {
	Node* new_node = new Node;
	new_node->data = data;
	new_node->left = NULL;
	new_node->right = NULL;
	Node* node = head;
	Node* temp = head;
	int flag;
	
	while (node) {
		temp = node;
		//if (compare(data, node->data)) {
		if (defaultFunction(data, node->data)) {
			node = node->left;
			flag = LEFT;
		}
		else {
			node = node->right;
			flag = RIGHT;
		}
	}
	if (node == head) {
		head = new_node;
	}
	else {
		if (flag == RIGHT) {
			temp->right = new_node;
		}
		else {
			temp->left = new_node;
		}
	}
}

template<class T>
void vip::BinarySearchTree<T>::printPreOrder() {
	Node* node = head;
	if (!node) return;
	cout << node->data;
	printPreOrder(node->left);
	printPreOrder(node->right);
}

template<class T>
void vip::BinarySearchTree<T>::printPreOrder(Node* node) {
	if (!node) return;
	cout << ", "<< node->data;
	printPreOrder(node->left);
	printPreOrder(node->right);
}

#endif
