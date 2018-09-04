#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;
#include "singly_linked_list.h"
#include "doubly_linked_list.h"

int main() {
	//vip::SinglyLinkedList<int> list;
	vip::DoublyLinkedList<int> list;
	list.insert(10);
	list.insert(20);
	list.insert(30);
	list.print();
	cout<<endl;
	list.deleteNodeByValue(20);
	list.print();
	cout << "\nPress any key to end the program: ";
	_getch();
	return 0;
}