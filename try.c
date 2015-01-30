#include <stdio.h>
#include <string.h>
void iterate(int *a);
typedef char* String;
typedef struct Node node;
typedef node* node_ptr;
struct Node {
	int data;
	int* next;
};

int main(){
	int a[] = {1,3,3};
	iterate(a);
}

ite

