#include <stdio.h>
#include "linkedList.h"
#include "stdlib.h"

int add(int a,int b){
	return a+b;
}

LinkedList createList(void){
	LinkedList list;
	list.head = NULL;
	list.tail = NULL;
	list.count = 0;
	return list;
}

node_ptr create_node(void *i){
	node_ptr n = (Node*)calloc(sizeof(Node),1);
	n->data  = i;
	n->next = NULL;
	return n;
}

int add_to_list(LinkedList *list,Node *n){
	if(list->head==NULL){
		list->head = n;
		list->tail = n;
		list->count++;
	}
	else{
		node_ptr walker = list->head;
		while(walker->next!=NULL){
			walker = walker->next;
		}
		walker->next = n;
		list->tail = n;
		list->count++;
	}	
	return 0;
}

void *get_first_element(LinkedList list){
	node_ptr n = list.head;
	return n->data;
}

void *get_last_element(LinkedList list){
	node_ptr n = list.tail;
	return n->data;
};


void traverse(LinkedList list,void (*addOne)(void* data)){
	node_ptr walker = list.head;
	while(walker!=NULL){
			addOne(walker->data);
			walker = walker->next; 
	} 
}

void* getElementAt(LinkedList list, int i){
	int count = 0;
	node_ptr walker = list.head;
	if(i>0){
		while(count!=i-1){
			walker = walker->next;
			count++;
		}
		return walker->data;
	}
	else
	return NULL;	
}

int indexOf(LinkedList list, void* data){
	node_ptr walker = list.head;
	int count = 0;
	while(walker!=NULL){
		if(walker->data == data){
			return count;
		}
		else{
			count++;
			walker = walker->next;
		}	
	}
	return -1;
}
void* deleteElementAt(LinkedList list, int i){
	int count = 0;
	node_ptr temp;
	node_ptr walker = list.head;
	if(i==0){
		list.head = walker->next;
		return walker->data;
		list.count--;
	}
		while(count!=i-1){
			walker = walker->next;
			count++;
		}
		temp = walker->next;
		walker->next = walker->next->next;
		list.count--;
	return temp->data;
}