/* Quantez Merchant */

#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "linkedlist.h"

int always_remove (void *data, void *helper){
	return 1;
}

void move_to_new_list (void *data){
	printf("This data was moved\n");
}

int deleteSome (void *p2head, ComparisonFunction mustGo, void *helper, ActionFunction disposal, int text){
	Node **listheadptr = p2head;
	Node *traverseptr = *listheadptr;
	Node *prevptr;
	if(*listheadptr == NULL){
		return 0;
	}else if(mustGo((**listheadptr).data,helper)){
		traverseptr = *listheadptr;
		*listheadptr = (**listheadptr).next;
		disposal(traverseptr->data);
		free(traverseptr);	
		return 1;				
	}else{		
		prevptr = traverseptr;				
		traverseptr = traverseptr->next;	
		while(traverseptr != NULL){	   
			if(mustGo(traverseptr->data,helper)){	
				prevptr->next = traverseptr->next;
				disposal(traverseptr->data);	
				free(traverseptr);		
				return 1;
			}else{
				prevptr = traverseptr;
				traverseptr = traverseptr->next;
			}
		}
	}
	return 0;
}

int main () {
	Node *head = NULL;
	Node *newlist = NULL;
	head = malloc(sizeof(head));
	if (head == NULL) {
		printf("ERROR");
	}else {
		head->data = (int *)1;
		head->next = malloc(sizeof(head));
		if (head->next == NULL){
			printf("ERROR");
		}else{
			head->next->data = (int *)3;
			head->next->next = malloc(sizeof(head));
			if (head->next->next == NULL) {
				printf("ERROR");
			}else{
				head->next->next->data = (int *)4;
				head->next->next->next = NULL;
				newlist = malloc(sizeof(newlist));
				if (newlist == NULL) {
					printf("ERROR");
				}else{
					
					printf("%d\n",head->data);
					printf("%d\n",head->next->data);
					printf("%d\n",head->next->next->data);
					printf("-------------------------------\n");
					deleteSome(&head,always_remove,NULL,move_to_new_list,1);
					printf("%d\n",head->data);
					printf("%d\n",head->next->data);
				}
			}
		}
	}
	return 0;
}
