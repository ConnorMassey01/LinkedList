#include <iostream>
#include "linkedList.h"
using namespace std;

int main() {
	struct linkedList list1;
	struct linkedList list2;
	for(int i = 0; i < 10; i++){
		insert(i, &list1);
		insert(9-i, &list2);
	}
	cout << "list 1: ";
	printList(&list1);
	cout << "list 2: ";
	printList(&list2);
	cout << "Removing first element in list 2\n";
	pull(&list2);
	cout << "list 2: ";
	printList(&list2);
}




