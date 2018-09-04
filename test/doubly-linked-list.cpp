#include<iostream>
#include "../vslib/doubly_linked_list.h"
using namespace std;
using namespace vip;

int main(){
	DoublyLinkedList<int> list;
	list.insert(10);
	list.insert(11);
	list.insert(12);
	list.print();
	cout<<endl;
	list.deleteNodeByValue(11);
	list.print();
	cout<<endl;
	cout.setf(ios::boolalpha);
	cout<<"Q. 10 Exists?: "<<list.valueExist(10)<<endl;
	cout<<"Q. 11 Exists?: "<<list.valueExist(11)<<endl;
	return 0;
}
