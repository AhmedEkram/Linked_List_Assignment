/***********************************************
 *  Module:Linked List
 *
 *  File Name:linkedlist.h
 *
 *  Description: Linked list typedefs and prototypes
 *
 *  Created on: 11/9/2019
 *
 *  Author: AHmed Ekram
 ***********************************************/

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_
/**************************************************************************
 * 				            Inclusions									  *
 *************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "standard_types.h"
/**************************************************************************
 * 				               Typedefs						     		  *
 *************************************************************************/
typedef struct  s{
uint32 data;
struct s *next;
}ST_Node;
/**************************************************************************
 * 				        Function Prototypes								  *
 *************************************************************************/

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
ST_Node ** createlist(void);
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
void Insert_To_List(uint32 data,uint8 pos,ST_Node **head);
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
void print(ST_Node **head);
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
void find_size(ST_Node **head);
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
void find_element(ST_Node **head,uint32 element);
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
void delete_from_list(ST_Node **head,uint8 pos);
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
void delete_list(ST_Node **head);
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
void reverse_list(ST_Node **head);
#endif /* LINKEDLIST_H_ */
