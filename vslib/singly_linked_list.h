#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include<iostream>
using namespace std;
#include<stdlib.h>

template<class T>
class SinglyLinkedList {
private:
	struct Node{
		T data;
		struct Node* next;
	};
	Node* head;
public:
	SinglyLinkedList();
	void insert(T data);
	void print();
	//struct Node* newNode();
};

template<class T>
SinglyLinkedList<T>::SinglyLinkedList() {
	head = NULL;
}

/*
template<class T>
struct Node* SinglyLinkedList<T>::newNode() {
	Node* node = (Node*)malloc(sizeof(Node));
	return node;
}
*/

template<class T>
void SinglyLinkedList<T>::insert(T data) {
	//Node* new_node = newNode();
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->data = data;
	new_node->next = NULL;
	if (head == NULL) {
		head = new_node;
	}
	else {
		Node* node = head;
		Node* temp = head;
		while (node) {
			temp = node;
			node = node->next;
		}
		temp->next = new_node;
	}
}

template<class T>
void SinglyLinkedList<T>::print() {
	Node* node = head;
	while (node) {
		if (node == head) cout << node->data;
		else cout << " -> " << node->data;
		node = node->next;
	}
}
#endif