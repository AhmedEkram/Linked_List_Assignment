/***********************************************
 *  Module:Linked List
 *
 *  File Name:linkedlist.c
 *
 *  Description: Linked list functions
 *
 *  Created on: 11/9/2019
 *
 *  Author: AHmed Ekram
 ***********************************************/
/**************************************************************************
 * 				            Inclusions									  *
 *************************************************************************/
#include "linkedlist.h"
/*count for counting number of insertions in the linked list*/
/**************************************************************************
 * 				            Global variables								  *
 *************************************************************************/
static uint8 count=0;
/**************************************************************************
 * Function Name : createlist
 *
 * Description	 : Assigning head location
 *
 * INPUTS		 : void
 *
 * OUTPUTS 		 : void
 *
 * Return		 : Pointer to pointer to structure
 **************************************************************************/
ST_Node ** createlist(void)
{
	ST_Node ** List_node=( ST_Node**)malloc(sizeof( ST_Node*));
	*List_node=NULL;
	return List_node;
}
/**************************************************************************
 * Function Name : Insert_To_List
 *
 * Description	 : Inserting a node at any place in the linked list by passing the position i want
 *
 * INPUTS		 : u32 data uint8 pos ST_Node **head
 *
 * OUTPUTS 		 : void
 *
 * Return		 : void
 **************************************************************************/
void Insert_To_List(uint32 data,uint8 pos, ST_Node **head)
{
	/*Creating local pointer to structure (link) to create the node*/
	ST_Node * link=(ST_Node*)malloc(sizeof( ST_Node));
	/*temp_ptr start at first node and then loop to approach the needed position*/
	ST_Node *temp_ptr=*head;
	/*counter temp_pos for looping in case of insertion in middle of list*/
	uint8 temp_pos=0;
	link->data=data;
	link->next=NULL;
	/*if head pointing at null then let head point at the inserted node*/
	if(*head==NULL)
	{
		*head=link;
		count++;
		return;
	}
	/*in case the user inserted number greater than linked list size insert the node by default at the end of the list */
	else if(pos>=count)
	{
		while((temp_ptr->next)!=NULL)
		{
			temp_ptr=temp_ptr->next;
		}
		temp_ptr->next=link;
		count++;
	}
	else
	{
		/*in case i want to insert at index 0*/
		if(pos==0)
		{
			link->next=*head;
			*head=link;
			count++;
			return ;
		}
		/*in case i want to insert at the middle of the list*/
		else
		{
			while(temp_pos<pos-1)
			{
				temp_ptr=temp_ptr->next;
				temp_pos++;
			}
			link->next=temp_ptr->next;
			temp_ptr->next=link;
			count++;
		}
	}
}
/**************************************************************************
 * Function Name : print
 *
 * Description	 : printing list elements
 *
 * INPUTS		 : ST_Node **head
 *
 * OUTPUTS 		 : void
 *
 * Return		 : void
 **************************************************************************/
void print(ST_Node **head)
{
	ST_Node *temp_ptr=*head;
	printf("\n[HEAD]=>");
	while(temp_ptr!=NULL)
	{
		printf("[%ld]=>",temp_ptr->data);
		temp_ptr=temp_ptr->next;
	}
	printf("[END]\n");
}
/**************************************************************************
 * Function Name : find_size
 *
 * Description	 : finding size of the linked list
 *
 * INPUTS		 : ST_Node **head
 *
 * OUTPUTS 		 : void
 *
 * Return		 : void
 **************************************************************************/
void find_size(ST_Node **head)
{
	uint8 size;
	ST_Node *temp_ptr=*head;
	if(*head==NULL)
	{
		printf("list is empty\n");
	}
	else
	{
		while(temp_ptr!=NULL)
		{
			size++;
			temp_ptr=temp_ptr->next;
		}
		printf("size=%d\n",size);
	}
}
/**************************************************************************
 * Function Name : find_element
 *
 * Description	 : finding certatin data inside a node and display it's index in the list
 *
 * INPUTS		 : ST_Node **head,uint32 element
 *
 * OUTPUTS 		 : void
 *
 * Return		 : void
 **************************************************************************/
void find_element(ST_Node **head,uint32 element)
{
	ST_Node *temp_ptr=*head;
	/*incremeting this index to locate the position of the searched for element*/
	uint8 i=0;
	while(temp_ptr!=NULL)
	{
		if(temp_ptr->data==element)
		{
			printf("element is found at %d\n",i);
			return ;
		}
		temp_ptr=temp_ptr->next;
		i++;
	}
	printf("element is not found\n");
}
/**************************************************************************
 * Function Name : delete_from_list
 *
 * Description	 : deleting a node from a list based on it's position in the list
 *
 * INPUTS		 : ST_Node **head,uint8 pos
 *
 * OUTPUTS 		 : void
 *
 * Return		 : void
 **************************************************************************/
void delete_from_list(ST_Node **head,uint8 pos)
{
	ST_Node *prev=NULL;
	ST_Node *delete_ptr=(*head);
	uint8 temp_pos=0;
	if(*head==NULL)
	{
		printf("list is empty\n");
		return ;
	}
	/*in case i want to delete first node in the list*/
	if(pos==0)
	{
		(*head)=(*head)->next;
		free(delete_ptr);
		return;
	}
	/*in case i want to deletion of any node other than the first one*/
	else
	{
		/*looping by temp pos till reach to the place before the place of the node that we want to delete*/

		while(temp_pos<pos&&delete_ptr!=NULL)
		{
			/*using prev in order to make it stop befor the node that need to be deleted in order to link
			 * the node that prev is pointing to ,to the node after the on that supposed to be deleted*/
			prev=delete_ptr;
			/*used to point to the node that we want to delete */
			delete_ptr=delete_ptr->next;
			temp_pos++;
		}
		/*if delete_ptr ==NULL means the user inserted a wrong index */
		if(delete_ptr==NULL)
		{
			printf("wrong index");
			return;
		}
		prev->next=delete_ptr->next;
		free(delete_ptr);
	}
}
/**************************************************************************
 * Function Name : delete_list
 *
 * Description	 : deleting the whole list
 *
 * INPUTS		 : ST_Node **head
 *
 * OUTPUTS 		 : void
 *
 * Return		 : void
 **************************************************************************/
void delete_list(ST_Node **head)
{
	ST_Node *delete_ptr=*head;
	ST_Node *current=NULL;
	if(*head==NULL)
	{
		printf("list is empty");
		return ;
	}
	current=*head;
	/*looping by delete pointer but current pointer will be ahead of it by one position*/
	while(current!=NULL)
	{
		delete_ptr=(current);
		(current)=(current)->next;
		free(delete_ptr);
	}
	(*head)=NULL;
}
/**************************************************************************
 * Function Name : reverse_list
 *
 * Description	 : reversing the whole list
 *
 * INPUTS		 : ST_Node **head
 *
 * OUTPUTS 		 : void
 *
 * Return		 : void
 **************************************************************************/
void reverse_list(ST_Node **head)
{
	ST_Node *current=*head;
	ST_Node *next=NULL;
	ST_Node *prev=NULL;
	while(current!=NULL)
	{
		next=current->next;
		current->next=prev;
		prev=current;
		current=next;

	}
	(*head)=prev;
}
