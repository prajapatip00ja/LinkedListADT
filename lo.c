#include <stdio.h>
typedef struct linkedlist LINKEDLIST;
struct linkedlist
{
	void* a;
	int count;
};

int main(){
	LINKEDLIST* list;
	list->a = NULL;
	printf("%d\n",list->a ); 
}
