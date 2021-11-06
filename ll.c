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
	struct node *p, *q=NULL;
	for (p = theList; p != NULL; p=q){
		q = p->next;
		free(p);
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

	for (p=theList; p!=NULL; p=p->next) {
		printf("%d\n", p->data);
	}
}

void reverse(struct node **head_pointer){
	/*
	 * argument: a pointer to the header of a linked list
	 *
	 * reverses a linked list by changing the links between
	 * nodes
	 */
	struct node *prev = NULL;
	struct node *current = *head_pointer;
	struct node *next;

	while (current != NULL) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*head_pointer = prev;
}

int main() {
	struct node *prev, *head, *p;
	int n, i;
	printf("Enter The Desired List Size: ");
	scanf("%d", &n); // read in size of list
	head=NULL;
	for (i=0;i<n; i++){
		p=malloc(sizeof(struct node));
		scanf("%d", &p->data);
		p->next=NULL;
		if(head==NULL) // if true, list is empty
			head=p; // since list is empty, p becomes head of list
		else  // list is NOT empty
			prev->next=p; // make previous point to p
		prev=p; // make prev point to p for next iteration
	}
	printf("\n");
	printf("The list: \n");
	print(head);
	reverse(&head);
	printf("The reversed list: \n");
	print(head);
	if (head != NULL)
		destroy(head);
	return 1;

}
