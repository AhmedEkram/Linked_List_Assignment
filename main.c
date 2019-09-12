/***********************************************
 *  Module:Linked List
 *
 *  File Name:main.c
 *
 *  Description: main file for resting our application
 *
 *  Created on: 11/9/2019
 *
 *  Author: AHmed Ekram
 ***********************************************/


#include "linkedlist.h"

int main(void)
{
	ST_Node **head=NULL;
	/*head allocation*/
	head=createlist();
	/*Linked List Insertions*/
	Insert_To_List(1,0,head);
	Insert_To_List(2,0,head);
	Insert_To_List(3,0,head);
	Insert_To_List(4,1,head);
	Insert_To_List(5,12,head);
	Insert_To_List(7,2,head);
	Insert_To_List(8,3,head);
	Insert_To_List(9,4,head);
	/*printing*/
	print(head);
    /*finding size of list*/
	find_size(head);
	/*finding index of node which contains the value of 2*/
	find_element(head,2);
	/*delete element at index 2*/
	delete_from_list(head,2);
	print(head);
	find_size(head);
	print(head);
    /*reversing list*/
	reverse_list(head);
	print(head);
	/*deleting the whole list*/
	delete_list(head);
}
