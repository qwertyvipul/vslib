#include "singly_linked_list.h"

SinglyLinkedList::SinglyLinkedList() {
	head = NULL;
}


struct SinglyNode* SinglyLinkedList::createNode() {
	struct SinglyNode* node = (struct SinglyNode*)malloc(sizeof(struct SinglyNode));
	return node;
}


void SinglyLinkedList::insert(int data) {
	struct SinglyNode* new_node = createNode();
	new_node->data = data;
	new_node->next = NULL;
	if (head == NULL) {
		head = new_node;
	}
	else {
		struct SinglyNode* node = head;
		struct SinglyNode* temp = head;
		while (node) {
			temp = node;
			node = node->next;
		}
		temp->next = new_node;
	}
}


void SinglyLinkedList::print() {
	struct SinglyNode* node = head;
	while (node) {
		if (node == head) cout << node->data;
		else cout << " -> " << node->data;
		node = node->next;
	}
}

/*
template <typename T>
SinglyLinkedList* SinglyLinkedList<T>::getHead() {
	return head;
}
*/