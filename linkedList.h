typedef struct Node node;
typedef struct linkedlist linkedList;
typedef node* node_ptr;
typedef linkedList* linkedList_ptr;

struct Node {
	int* data;
	int* next;
};

struct linkedlist
{
	node* head;
	node* tail;
	int count;
};

linkedList createList(void);
