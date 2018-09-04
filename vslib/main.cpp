#include<iostream>
#include<conio.h>
using namespace std;
#include "vslib.h"

int main() {
	SinglyLinkedList list;
	list.insert(10);
	list.insert(20);
	list.print();
	_getch();
	return 0;
}