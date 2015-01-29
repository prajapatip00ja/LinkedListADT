#include <stdio.h>
#include "linkedList.h"
#include "expr_assert.h"
#include "stdlib.h"

void test_add_two_num(){
	assertEqual(add(1,2),3);
}

void test_createList_create_a_empty_list(){
	LinkedList list =  createList();
	assertEqual((int)(list.head),'\0');
	assertEqual((int)(list.tail),'\0');
	assertEqual((int)(list.count),0);
}

void test_createNode_create_a_node_structure(){
	int i = 6;
	node_ptr node = create_node((void*)&i);
	assertEqual(*((int*)(node->data)),6);
	assertEqual((int)node->next,'\0');
	free(node);
}

void test_add_to_list_method_add_a_new_node_in_the_list(){
	int i = 7;
	int j = 8;
	node_ptr node1 = create_node((void*)&i);
	node_ptr node2 = create_node((void*)&j);
	LinkedList list = createList();
	add_to_list(&list,node1);
	assertEqual(*(int*)(node1->data),7);
	add_to_list(&list,node2);
	assertEqual(*(int*)(node2->data),8);
}

void test_get_first_element_method_return_the_first_element_of_list(){
	int i = 7;
	int j = 8;
	void* data;
	node_ptr node1 = create_node((void*)&i);
	node_ptr node2 = create_node((void*)&j);
	LinkedList list = createList();
	add_to_list(&list,node1);
	add_to_list(&list,node2);
	data = get_first_element(list);
	assertEqual(*(int*)data,7);
}

void test_get_last_element_method_return_the_last_element_of_list(){
	int i = 7;
	int j = 8;
	void* data;
	node_ptr node1 = create_node((void*)&i);
	node_ptr node2 = create_node((void*)&j);
	LinkedList list = createList();
	add_to_list(&list,node1);
	add_to_list(&list,node2);
	data = get_last_element(list);
	assertEqual(*(int*)data,8);
}

void addOne(void* data){
	*(int*)data = *(int*)data+1;
};

void test_traverse_method_traverse_through_each_element_in_the_list(){
	int i = 7;
	int j = 8;
	int item = 1;
	void* data;
	void (*fn_ptr)(void*) = &addOne;
	node_ptr node1 = create_node((void*)&i);
	node_ptr node2 = create_node((void*)&j);
	LinkedList list = createList();
	add_to_list(&list,node1);
	add_to_list(&list,node2);
	traverse(list,fn_ptr);
	assertEqual(*(int*)(node1->data),8);
	assertEqual(*(int*)(node2->data),9);
}


