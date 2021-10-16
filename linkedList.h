struct node{
	int data;
	struct node *next;
	struct node *prev;
};

struct linkedList{
	struct node *head = NULL;
	struct node *tail = NULL;
};

void insert(int d, struct linkedList *l);
int pull(struct linkedList *l);
void printList(struct linkedList *l);

