#include <stdio.h>
#include <string.h>
typedef char* String;
typedef struct Node node;
typedef node* node_ptr;
struct Node {
	int data;
	int* next;
};

int main(){
	String i = "pooja";
	String j = "pooja";
	printf("i = %d\n",strcmp(i,j));
}