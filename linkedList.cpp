#include <iostream>
#include "linkedList.h"
using namespace std;

void insert(int d, struct linkedList *l){
	//allocate memory to create pointer to node struct
	struct node* n = (struct node *)malloc(sizeof(struct node));
	//exit if node was not created
	if (n == nullptr){
		cout << "error\n";
		exit(1);
	}
	//fit the node to the front of the linked list
	n->data = d;
	n->next = NULL;
	n->prev = NULL;
	if (l->head == nullptr){
        l->head = n;
        l->tail = n;
	}
    else{
        l->head->prev = n;
        n->next = l->head;
        l->head = n;
    }
}

int pull(struct linkedList *l){
	//return 0 if there is nothing in the list to pull
	if(l->head == nullptr){
		return 0;
	}
	//take the node from the start of the list
	struct node* n = l->head;
	//assign the head to point to the next node and properly repair the linked list
	l->head = l->head->next;
	if(l->head == nullptr){
      	l->tail = NULL;
    }
    else{
        l->head->prev = NULL;
    }
	//take the data from the node pointing to what was the head of the list and then free the memory
	int retval = n->data;
    free(n);
    return retval;
}

void printList(struct linkedList *l){
	//return if there is no list to print
	if(l->head == nullptr){
		return;
	}
	//start at the head of the list and print each node's data until the end of the list
	struct node* n = l->head;
	while(n != nullptr){
		if(n->next == nullptr){
			cout << n->data << "\n";
		}
		else{
			cout << n->data << " -> ";
		}
		n = n->next;
	}
}
