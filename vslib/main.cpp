#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;
#include "singly_linked_list.h"

int main() {
	vip::SinglyLinkedList<int> list;
	list.insert(10);
	list.insert(20);
	list.print();
	_getch();
	return 0;
}