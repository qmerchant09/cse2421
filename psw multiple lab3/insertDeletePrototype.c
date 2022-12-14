/* Quantez Merchant */

#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

struct Node {
	void *data;
	struct Node *next;
};

int first_letter (void *data1, void *data2){
	char *d1 = data1;
	char *d2 = data2;
	if(d1[0] < d2[0]){
	return 1;
	}
	return 0;
}

void print_string (void *data){
printf ("%s\n", data);
}

void deleted (void *data){
	data = NULL;
}

int c (void *data, void *helper) {
	if (data == helper){
		return 1;
	}
	return 0;
}
int main (){
	struct Node *head = NULL;
	int rval;
	rval = insert(&head, "Go Bucks!", first_letter, 0);
	rval = insert(&head, "Bo Gucks!", first_letter, 0);
	rval = insert(&head, "Ao Bucks!", first_letter, 0);
	rval = insert(&head, "ho Bucks!", first_letter, 0);
	rval = insert(&head, "A", first_letter, 1);
	iterate(head, print_string);
	rval = deleteSome(&head, c, "Go Bucks!", deleted, 1);
	iterate(head,print_string);

	return 0;
}
