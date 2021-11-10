#include <stdio.h>
#include <stdlib.h>

struct node {
	int data; // data is integers 
	struct node *next; // link to the next element in list 
};

void destroy(struct node *theList) {
	/*
	 * argument: head of linked list
	 *
	 * destroys the instance of the linked list
	 * by freeing associated memory
	 */
	struct node *p, *q=NULL; // two node pointers; current and next
	for (p = theList; p != NULL; p=q){ // iterate through updating p to q
		q = p->next; // remember p is gonna be destroyed so move p first
		free(p); // free p (we saved the next value of p in q)
	}
}

void print(struct node *theList) {
	/*
	 * argument: head of linked list
	 *
	 * prints the data from each node in a 
	 * linked list
	 */
	struct node *p;

	for (p=theList; p!=NULL; p=p->next) { // while p is not null
		printf("%d\n", p->data); // print p's data
	}
}

void reverse(struct node **head_pointer){
	/*
	 * argument: a pointer to the header of a linked list
	 *
	 * reverses a linked list by changing the links between
	 * nodes
	 */
	struct node *prev = NULL; // previous is null as no memory here yet
	struct node *p = *head_pointer; // this will be our current pointer
	struct node *q;  // this will be for our pointer after p (next)

	while (p != NULL) { // break when null
		q = p->next; // q is the next value
		p->next = prev; // change p to point at previous instead of next
		prev = p; // make previous be p (current pointer)
		p = q; // update p to be q (the next pointer)
	}
	*head_pointer = prev; // update the head pointer to be prev (p is null)
}

int main() {
	struct node *prev, *head, *p; // pointers to nodes we will use
	int n, i; // size and counter, respectively

	printf("Enter The Desired List Size: ");
	scanf("%d", &n); // read in size of list

	head=NULL; // head pointer is null as no memory address stored yet
	for (i=0;i<n; i++){
		p=malloc(sizeof(struct node)); // put the node on the heap!!
		scanf("%d", &p->data); // read an integer from stdin
		p->next=NULL; // make next Null as this is the tail
		if(head==NULL) // if true, list is empty
			head=p; // since list is empty, p becomes head of list
		else  // list is NOT empty
			prev->next=p; // make previous point to p
		prev=p; // make prev point to p for next iteration
	}
	printf("\n");
	printf("The list: \n");
	print(head); // print elements in list
	reverse(&head); // reverse the list
	printf("The reversed list: \n");
	print(head); // print the reversed list
	if (head != NULL)
		destroy(head); // destroy the list
	return 1;

}
