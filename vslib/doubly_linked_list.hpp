#ifndef DOUBLY_LINKED_LIST_HPP
#define DOUBLY_LINKED_LIST_HPP

#include<iostream>
using namespace std;
#include<stdlib.h>

namespace vip {
	template<class T>
	class DoublyLinkedList;
}

template<class T>
class vip::DoublyLinkedList{
private:
	struct Node{
		T data;
		Node* prev;
		Node* next;
	};
	Node* head;
	Node* tail;

public:
	DoublyLinkedList();
	void insert(T data);
	void print();
	Node* newNode();
	bool valueExist(T data);
	void deleteNodeByValue(T data);
};

template<class T>
vip::DoublyLinkedList<T>::DoublyLinkedList() {
	head = NULL;
	tail = NULL;
}

template<class T>
void vip::DoublyLinkedList<T>::insert(T data) {
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->data = data;
	new_node->next = NULL;
	new_node->prev = NULL;
	if (head == NULL) {
		head = new_node;
		tail = new_node;
	}
	else {
		Node* node = head;
		Node* temp = head;
		while (node) {
			temp = node;
			node = node->next;
		}
		temp->next = new_node;
		new_node->prev = temp;
		tail = new_node;
	}
}

template<class T>
void vip::DoublyLinkedList<T>::print() {
	Node* node = head;
	while (node) {
		if (node == head) cout << node->data;
		else cout << " -> " << node->data;
		node = node->next;
	}
}

template<class T>
void vip::DoublyLinkedList<T>::deleteNodeByValue(T data) {
	Node* node = head;
	Node* temp = head;
	while(node->data != data){
		temp = node;
		node = node->next;
	}
	if(node == head){
		head = head->next;
		head->prev = NULL;
		delete node;
	}else{
		temp->next = node->next;
		if(node->next) node->next->prev = temp;
		else tail = temp;
		delete node;
	}
}

template<class T>
bool vip::DoublyLinkedList<T>::valueExist(T data) {
	Node* node = head;
	while (node) {
		if (node->data == data) return true;
	}
	return false;
}
#endif
