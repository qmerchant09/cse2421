/* Quantez Merchant */

#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#include "node.h"


void print (void *data) {
	Node *l = data;
	printf("%d\n",l->data);
}

void iterate (void *head, ActionFunction doThis) {
	Node *l = head;
	while(l != NULL){
		doThis(l);
		l = l->next;
	}
}

int main () {
	Node *head = NULL;
	head = malloc(sizeof(head));
	if (head == NULL) {
		printf("ERROR");
	}else {
		head->data = (int *)1;
		head->next = malloc(sizeof(head));
		if (head->next == NULL){
			printf("ERROR");
		}else{
			head->next->data = (int *)2;
			head->next->next = NULL;
		}
	}
	iterate(head,print);
	return 0;
}
