/* Quantez Merchant */

#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

struct Node{
	void *data;
	struct Node *next;
};

struct Node *head2 = NULL;

int first_letter (void *data1, void *data2){
	char *d1 = data1;
	char *d2 = data2;
	if(d1[0] < d2[0]){
	return 1;
	}
	return 0;
}

void print_string (void *data){
printf ("%s ", data);
}

void deleted (void *data){
	int rval;
	rval = insert(&head2,data,first_letter,1);
}

int c (void *data, void *helper) {
	if (data == helper){
		return 1;
	}
	return 0;
}
int main (){
	struct Node *head1 = NULL;
	int rval;
	rval = insert(&head1, "Go Bucks!", first_letter, 0);
	rval = insert(&head1, "Bo Gucks!", first_letter, 0);
	rval = insert(&head2, "Ao Bucks!", first_letter, 0);
	rval = insert(&head2, "ho Bucks!", first_letter, 0);
	rval = insert(&head1, "A", first_letter, 1);
	iterate(head1, print_string);
	printf ("\n");
	iterate(head2, print_string);
	printf ("\n");
	rval = deleteSome(&head1, c, "A", deleted, 1);
	iterate(head1,print_string);
	printf ("\n");
	iterate(head2,print_string);
	return 0;
}

