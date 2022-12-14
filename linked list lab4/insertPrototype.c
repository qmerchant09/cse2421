/* Quantez Merchant */

#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "linkedlist.h"

int lowestFirst (void *data, void *helper){
	Node *l = data, *l2 = helper;
	return (l->data < l2->data);
}

int insert (void *p2head, void *data, ComparisonFunction goesInFrontOf, int text){
	Node **l = p2head, *l2 = data;
	while (*l != NULL && lowestFirst(*l,l2)){
		l = &((**l).next);
	}
	l2->next = *l;
	*l = l2;
	return 1;
}

int main () {
	Node *head = NULL;
	Node *newnode = NULL;
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
				newnode = malloc(sizeof(newnode));
				if (newnode == NULL) {
					printf("ERROR");
				}else{
					newnode->data = (int *)2;

					printf("%d\n",head->data);
					printf("%d\n",head->next->data);
					printf("%d\n",head->next->next->data);
					printf("---------------------\n");
					
					
					insert(&head,newnode,lowestFirst,1);
					printf("%d\n",head->data);
					printf("%d\n",head->next->data);
					printf("%d\n",head->next->next->data);
					printf("%d\n",head->next->next->next->data);
				}
			}
		}
	}
	return 0;
}
