#include <stdio.h>
#include "linkedList.h"
#include "expr_assert.h"
#include "stdlib.h"
#include <String.h>

void test_add_two_num(){
	assertEqual(add(1,2),3);
}

void test_createList_create_a_empty_list(){
	LinkedList list =  createList();
	assertEqual((int)(list.head),'\0');
	assertEqual((int)(list.tail),'\0');
	assertEqual((int)(list.count),0);
}

void test_createList_create_a_empty_list_for_char(){
	LinkedList list =  createList();
	assertEqual((char)(list.head),'\0');
	assertEqual((char)(list.tail),'\0');
	assertEqual((int)(list.count),0);
}

void test_createList_create_a_empty_list_for_float(){
	LinkedList list =  createList();
	assertEqual((char)(list.head),'\0');
	assertEqual((char)(list.tail),'\0');
	assertEqual((int)(list.count),0);
}

void test_createList_create_a_empty_list_for_double(){
	LinkedList list =  createList();
	assertEqual((char)(list.head),'\0');
	assertEqual((char)(list.tail),'\0');
	assertEqual((int)(list.count),0);
}



void test_createNode_create_a_node_structure(){
	int i = 6;
	node_ptr node = create_node((void*)&i);
	assertEqual(*((int*)(node->data)),6);
	assertEqual((int)node->next,'\0');
	free(node);
}

void test_createNode_create_a_node_structure_for_char(){
	char i = 'a';
	node_ptr node = create_node((void*)&i);
	assertEqual(*((char*)(node->data)),'a');
	assertEqual((char)node->next,'\0');
	free(node);
}

void test_createNode_create_a_node_structure_for_double(){
	double i = 0;
	node_ptr node = create_node((void*)&i);
	assertEqual(*((double*)(node->data)),0);
	assertEqual((int)node->next,'\0');
	free(node);
}

void test_createNode_create_a_node_structure_for_float(){
	float i = 0.0000;
	node_ptr node = create_node((void*)&i);
	assertEqual(*((float*)(node->data)),0.0000);
	assertEqual((int)node->next,'\0');
	free(node);
}

void test_createNode_create_a_node_structure_for_String(){
	String i = "pooja";
	node_ptr node = create_node((void**)&i);
	assertEqual(strcmp(*((String*)node->data),i),0);
	assertEqual((int)node->next,'\0');
	free(node);
}

void test_createNode_create_a_node_structure_for_structure(){
	Student s1 = {1,'c'};
	node_ptr node = create_node((void*)&s1);
	assertEqual(((Student*)(node->data))->id,1);
	assertEqual(((Student*)(node->data))->symbol,'c');
	assertEqual((int)node->next,'\0');
	free(node);
}



void test_createNode_create_a_node_structure_for_int_star(){
	int *i = 5;
	node_ptr node = create_node((void**)&i);
	assertEqual(*((int*)node->data),5);
	assertEqual((int)node->next,'\0');
	free(node);
}



void test_add_to_list_method_add_a_new_node_in_the_list_of_int(){
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

void test_add_to_list_method_add_a_new_node_in_the_list_of_char(){
	char i = 'a';
	char j = 'b';
	node_ptr node1 = create_node((void*)&i);
	node_ptr node2 = create_node((void*)&j);
	LinkedList list = createList();
	add_to_list(&list,node1);
	assertEqual(*(char*)(node1->data),'a');
	add_to_list(&list,node2);
	assertEqual(*(char*)(node2->data),'b');
}

void test_add_to_list_method_add_a_new_node_in_the_list_of_float(){
	float i = 0;
	float j = 0;
	node_ptr node1 = create_node((void*)&i);
	node_ptr node2 = create_node((void*)&j);
	LinkedList list = createList();
	add_to_list(&list,node1);
	assertEqual(*(float*)(node1->data),0);
	add_to_list(&list,node2);
	assertEqual(*(float*)(node2->data),0);
}

void test_add_to_list_method_add_a_new_node_in_the_list_of_double(){
	double i = 0;
	double j = 0;
	node_ptr node1 = create_node((void*)&i);
	node_ptr node2 = create_node((void*)&j);
	LinkedList list = createList();
	add_to_list(&list,node1);
	assertEqual(*(double*)(node1->data),0);
	add_to_list(&list,node2);
	assertEqual(*(double*)(node2->data),0);
}

void test_add_to_list_method_add_a_new_node_in_the_list_of_String(){
	String i = "pooja";
	String j = "prajapati";
	node_ptr node1 = create_node((void**)&i);
	node_ptr node2 = create_node((void**)&j);
	LinkedList list = createList();
	add_to_list(&list,node1);
	assertEqual(strcmp((*(String*)(node1->data)),i),0);
	add_to_list(&list,node2);
	assertEqual(strcmp((*(String*)(node2->data)),j),0);
}

void test_get_first_element_method_return_the_first_element_of_list_of_int(){
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

void test_get_first_element_method_return_the_first_element_of_list_of_char(){
	char i = 'a';
	char j = 'b';
	void* data;
	node_ptr node1 = create_node((void*)&i);
	node_ptr node2 = create_node((void*)&j);
	LinkedList list = createList();
	add_to_list(&list,node1);
	add_to_list(&list,node2);
	data = get_first_element(list);
	assertEqual(*(char*)data,'a');
}

void test_get_first_element_method_return_the_first_element_of_list_of_float(){
	float i = 0;
	float j = 1.11111;
	void* data;
	node_ptr node1 = create_node((void*)&i);
	node_ptr node2 = create_node((void*)&j);
	LinkedList list = createList();
	add_to_list(&list,node1);
	add_to_list(&list,node2);
	data = get_first_element(list);
	assertEqual(*(float*)data,0);
}

void test_get_first_element_method_return_the_first_element_of_list_of_double(){
	double i = 0;
	double j = 1.111;
	void* data;
	node_ptr node1 = create_node((void*)&i);
	node_ptr node2 = create_node((void*)&j);
	LinkedList list = createList();
	add_to_list(&list,node1);
	add_to_list(&list,node2);
	data = get_first_element(list);
	assertEqual(*(double*)data,0);
}


void test_get_last_element_method_return_the_last_element_of_list_of_int(){
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
	free(node1);
	free(node2);
}

void test_get_last_element_method_return_the_last_element_of_list_of_char(){
	char i = 'a';
	char j = 'b';
	void* data;
	node_ptr node1 = create_node((void*)&i);
	node_ptr node2 = create_node((void*)&j);
	LinkedList list = createList();
	add_to_list(&list,node1);
	add_to_list(&list,node2);
	data = get_last_element(list);
	assertEqual(*(char*)data,'b');
	free(node1);
	free(node2);
}

void test_get_last_element_method_return_the_last_element_of_list_of_float(){
	float i = 7.5;
	float j = 9.5;
	void* data;
	node_ptr node1 = create_node((void*)&i);
	node_ptr node2 = create_node((void*)&j);
	LinkedList list = createList();
	add_to_list(&list,node1);
	add_to_list(&list,node2);
	data = get_last_element(list);
	assertEqual((*(float*)data==9.5),1);
	free(node1);
	free(node2);
 }

void test_get_last_element_method_return_the_last_element_of_list_of_double(){
	double i = 7.7777777;
	double j = 8.888888;
	void* data;
	node_ptr node1 = create_node((void*)&i);
	node_ptr node2 = create_node((void*)&j);
	LinkedList list = createList();
	add_to_list(&list,node1);
	add_to_list(&list,node2);
	data = get_last_element(list);
	assertEqual((*(double*)data==8.888888),1);
	free(node1);
	free(node2);
}

void addOne(void* data){
	*(int*)data = *(int*)data+1;
};



void test_traverse_method_traverse_through_each_element_in_the_list(){
	int i = 7;
	int j = 8;
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
	free(node1);
	free(node2);
}



void test_getElemntAt_method_should_return_the_sepcefied_element_of_type_int(){
	int i = 7;
	int j = 8;
	int index = 1;
	void* data;
	node_ptr node1 = create_node((void*)&i);
	node_ptr node2 = create_node((void*)&j);
	LinkedList list = createList();
	add_to_list(&list,node1);
	add_to_list(&list,node2);
	data = getElementAt(list,index);
	assertEqual(*(int*)data,8);
	free(node1);
	free(node2);
}

void test_getElemntAt_method_should_return_the_sepcefied_element_of_type_char(){
	char i = 'a';
	char j = 'b';
	int index = 1;
	void* data;
	node_ptr node1 = create_node((void*)&i);
	node_ptr node2 = create_node((void*)&j);
	LinkedList list = createList();
	add_to_list(&list,node1);
	add_to_list(&list,node2);
	data = getElementAt(list,index);
	assertEqual(*(char*)data,'b');
	free(node1);
	free(node2);
}

void test_getElemntAt_method_should_return_the_sepcefied_element_of_type_float(){
	float i = 7.00000;
	float j = 8.00000;
	int index = 1;
	void* data;
	node_ptr node1 = create_node((void*)&i);
	node_ptr node2 = create_node((void*)&j);
	LinkedList list = createList();
	add_to_list(&list,node1);
	add_to_list(&list,node2);
	data = getElementAt(list,index);
	assertEqual((*(float*)data==8.00000),1);
	free(node1);
	free(node2);
}

void test_getElemntAt_method_should_return_the_sepcefied_element_of_type_double(){
	double i = 7.00000;
	double j = 8.00000;
	int index = 1;
	void* data;
	node_ptr node1 = create_node((void*)&i);
	node_ptr node2 = create_node((void*)&j);
	LinkedList list = createList();
	add_to_list(&list,node1);
	add_to_list(&list,node2);
	data = getElementAt(list,index);
	assertEqual((*(double*)data==8.00000),1);
	free(node1);
	free(node2);
}

void test_indexof_method_should_return_the_index_of_sepcefied_element_of_typeInt(){
	int i = 7;
	int j = 8;
	int index;
	node_ptr node1 = create_node((void*)&i);
	node_ptr node2 = create_node((void*)&j);
	LinkedList list = createList();
	add_to_list(&list,node1);
	add_to_list(&list,node2);
	index = indexOf(list,node1->data);
	assertEqual(index,0);
	free(node1);
	free(node2);
}

void test_indexof_method_should_return_the_index_of_sepcefied_element_of_typeChar(){
	char i = 'a';
	char j = 'b';
	int index;
	node_ptr node1 = create_node((void*)&i);
	node_ptr node2 = create_node((void*)&j);
	LinkedList list = createList();
	add_to_list(&list,node1);
	add_to_list(&list,node2);
	index = indexOf(list,node1->data);
	assertEqual(index,0);
	free(node1);
	free(node2);
}

void test_indexof_method_should_return_the_index_of_sepcefied_element_of_typeFloat(){
	float i = 7.111;
	float j = 8.111;
	int index;
	node_ptr node1 = create_node((void*)&i);
	node_ptr node2 = create_node((void*)&j);
	LinkedList list = createList();
	add_to_list(&list,node1);
	add_to_list(&list,node2);
	index = indexOf(list,node1->data);
	assertEqual(index,0);
	free(node1);
	free(node2);
}

void test_indexof_method_should_return_the_index_of_sepcefied_element_of_typeDouble(){
	double i = 7.111111;
	double j = 8.111111;
	int index;
	node_ptr node1 = create_node((void*)&i);
	node_ptr node2 = create_node((void*)&j);
	LinkedList list = createList();
	add_to_list(&list,node1);
	add_to_list(&list,node2);
	index = indexOf(list,node1->data);
	assertEqual(index,0);
	free(node1);
	free(node2);
}

void test_indexof_method_should_return_the_minus_one_if_no_element_is_match(){
	int i = 7;
	int j = 8;
	int item = 7;
	int index;
	node_ptr node1 = create_node((void*)&i);
	node_ptr node2 = create_node((void*)&j);
	LinkedList list = createList();
	add_to_list(&list,node1);
	add_to_list(&list,node2);
	index = indexOf(list,(void*)&item);
	assertEqual(index,-1);
	free(node1);
	free(node2);
}


void test_deleteElementAt_method_should_delete_element(){
	int i = 7;
	int j = 8;
	int index = 1;
	void* data;
	node_ptr node1 = create_node((void*)&i);
	node_ptr node2 = create_node((void*)&j);
	LinkedList list = createList();
	add_to_list(&list,node1);
	add_to_list(&list,node2);
	data =  deleteElementAt(&list,index);
	assertEqual(*(int*)data,8);
	free(node1);
	free(node2);
}

void test_deleteElementAt_method_should_delete_the_first_element(){
	int i = 7;
	int j = 8;
	int index = 0;
	void* data;
	node_ptr node1 = create_node((void*)&i);
	node_ptr node2 = create_node((void*)&j);
	LinkedList list = createList();
	add_to_list(&list,node1);
	add_to_list(&list,node2);
	data =  deleteElementAt(&list,index);
	assertEqual(*(int*)data,7);
	free(node1);
	free(node2);
}

void test_deleteElementAt_method_should_delete_the_middile_element(){
	int i = 7;
	int j = 8;
	int k = 9;
	int index = 1;
	void* data;
	node_ptr node1 = create_node((void*)&i);
	node_ptr node2 = create_node((void*)&j);
	node_ptr node3 = create_node((void*)&k);
	LinkedList list = createList();
	add_to_list(&list,node1);
	add_to_list(&list,node2);
	add_to_list(&list,node3);
	data =  deleteElementAt(&list,index);
	assertEqual(*(int*)data,8);
	free(node1);
	free(node2);
}

void test_deleteElementAt_method_should_delete_the_char_element(){
	char i = 'a';
	char j = 'b';
	int index = 0;
	void* data;
	node_ptr node1 = create_node((void*)&i);
	node_ptr node2 = create_node((void*)&j);
	LinkedList list = createList();
	add_to_list(&list,node1);
	add_to_list(&list,node2);
	data =  deleteElementAt(&list,index);
	assertEqual(*(char*)data,'a');
	free(node1);
	free(node2);
}

void test_deleteElementAt_method_should_delete_the_float_element(){
	float i = 1.0;
	float j = 2.0;
	int index = 1;
	void* data;
	node_ptr node1 = create_node((void*)&i);
	node_ptr node2 = create_node((void*)&j);
	LinkedList list = createList();
	add_to_list(&list,node1);
	add_to_list(&list,node2);
	data =  deleteElementAt(&list,index);
	assertEqual((*(float*)data==j),1);
	free(node1);
	free(node2);
}

void test_deleteElementAt_method_should_delete_the_double_element(){
	double i = 1.000;
	double j = 2.000;
	int index = 1;
	void* data;
	node_ptr node1 = create_node((void*)&i);
	node_ptr node2 = create_node((void*)&j);
	LinkedList list = createList();
	add_to_list(&list,node1);
	add_to_list(&list,node2);
	data =  deleteElementAt(&list,index);
	assertEqual((*(double*)data==j),1);
	free(node1);
	free(node2);
}

void test_deleteElementAt_method_should_delete_the_String_element(){
	String i = "pooja";
	String j = "prajapati";
	int index = 0;
	void* data;
	node_ptr node1 = create_node((void*)&i);
	node_ptr node2 = create_node((void*)&j);
	LinkedList list = createList();
	add_to_list(&list,node1);
	add_to_list(&list,node2);
	data =  deleteElementAt(&list,index);
	assertEqual((*(String*)data==i),1);
	free(node1);
	free(node2);
}

void test_deleteElementAt_method_should_delete_the_Structure_element(){
	Student s1 = {1,'p'};
	Student s2 = {2,'o'};
	int index = 0;
	void* data;
	node_ptr node1 = create_node((void*)&s1);
	node_ptr node2 = create_node((void*)&s2);
	LinkedList list = createList();
	add_to_list(&list,node1);
	add_to_list(&list,node2);
	data =  deleteElementAt(&list,index);
	assertEqual(((Student*)(data))->id,1);
	assertEqual(((Student*)(data))->symbol,'p');
	free(node1);
	free(node2);
}


