#include <stdio.h>
typedef struct Node node;
typedef node* node_ptr;
struct Node {
	int data;
	int* next;
};

int main(){
	int i = 10;
	node_ptr n;
	n->data = i;
	printf("i = %d\n",n->data);
}