struct node{
	int data;
	struct node *next;
	struct node *prev;
};

struct linkedList{
	struct node *head = NULL;
	struct node *tail = NULL;
};

//insert an element to the front of the linked list
void insert(int d, struct linkedList *l);
//pull an element from the front of the linked list
int pull(struct linkedList *l);
//print the list from the head to the tail
void printList(struct linkedList *l);

