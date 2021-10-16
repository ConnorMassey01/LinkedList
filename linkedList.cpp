#include <iostream>
using namespace std;

struct node{
	int data;
	struct node *next;
	struct node *prev;
};

struct linkedList{
	struct node *head = NULL;
	struct node *tail = NULL;
};

void insert(int d, struct linkedList *l){
	struct node *n = (struct node *)malloc(sizeof(struct node));
	if (n == nullptr){
		cout << "error\n";
		exit(1);
	}
	n->data = d;
	n->next = NULL;
	n->prev = NULL;
	if (l->head == nullptr){
        l->head = n;
        l->tail = n;
	}
    else{
        l->head->prev = n;
        n -> next = l->head;
        l->head = n;
    }
}

int pull(struct linkedList *l){
	if(l->head == nullptr){
		return 0;
	}
	struct node *n = l->head;
	l->head = l->head->next;
	if(l->head == nullptr){
      	l->tail = NULL;
    }
    else{
        l->head->prev = NULL;
    }

	int retval = n -> data;
    free(n);
    return retval;
}

void printList(struct linkedList *l){
	if(l->head == nullptr){
		return;
	}
	struct node *n = l->head;
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
