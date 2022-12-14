/* Quantez Merchant */

#include <stdio.h>
#include <stdlib.h>
#include "altmem.h"
#include "utypes.h"
#include "structs.h"
#include "node.h"
#include "linkedlist.h"
#include "debug.h"
#include "functions.h"

/* This functon allocates a node */
static struct Node *allocate_node () {
	Node *n = NULL;
	static int ncount = 0;
	if (n = alternative_malloc(sizeof(n))) {
		ncount++;
		if(TEXT)printf("DIAGNOSTIC: %d nodes allocated.\n", ncount);
	}else{
		if(TEXT)printf("ERROR: Unable to allocate a node.\n");
	}
	return n;

}

/* This function frees a node */
static void free_node(Node *n) {
	static int fcount = 0;
	alternative_free(n);
	n = NULL;
	fcount++;
	if(TEXT)printf("DIAGNOSTIC: %d nodes freed.\n", fcount);
}

/* This function iterates through the list, performing an action */
void iterate (void *head, ActionFunction doThis) {
	Node *n = head;
	while(n != NULL){
		doThis(n->data);
		n = n->next;
	}
}

/* This function inserts a node into the list */
int insert (void *p2head, void *data, ComparisonFunction goesInFrontOf, int text){		
	Node **p2p2change = p2head;
	Node *newnode;
	if((newnode = allocate_node()) == NULL){
		return 0;
	}
	newnode->data = data;
	while(*p2p2change != NULL && goesInFrontOf((**p2p2change).data,newnode->data)) {
		p2p2change = &((**p2p2change).next);
	}
	newnode->next = *p2p2change;
	*p2p2change = newnode;
	return 1;
}

/* This function deletes from the list */
int deleteSome (void *p2head, CriteriaFunction mustGo, void *helper, ActionFunction disposal, int text){	
	Node **listheadptr = p2head;
	Node *traverseptr = *listheadptr;
	Node *prevptr;
	if(*listheadptr == NULL){
		return 0;
	}else if(mustGo((**listheadptr).data,helper)){
		traverseptr = *listheadptr;
		*listheadptr = (**listheadptr).next;
		disposal(traverseptr->data);
		free_node(traverseptr);
		return 1;
	}else{	
		prevptr = traverseptr;
		traverseptr = traverseptr->next;
		while(traverseptr != NULL){
			if(mustGo(traverseptr->data,helper)){
				prevptr->next = traverseptr->next;
				disposal(traverseptr->data);
				free_node(traverseptr);
				return 1;
			}else{
				prevptr = traverseptr;
				traverseptr = traverseptr->next;
			}
		}
	}
	return 0;
}

