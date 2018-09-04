#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include<iostream>
using namespace std;
#include<stdlib.h>

struct SinglyNode{
	int data;
	struct SinglyNode* next;
};


class SinglyLinkedList {
public:
	struct SinglyNode* head;

	SinglyLinkedList();
	void insert(int data);
	void print();
	struct SinglyNode* createNode();
	//SinglyLinkedList* getHead();
};
#endif