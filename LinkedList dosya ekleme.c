#include <stdio.h>
#include <stdlib.h>

//Linked List
struct node{
	int data;
	struct node *next;
};

//Head & Tail
struct node *head = NULL;
struct node *tail = NULL;

//Add Node
int addNode(int data){
	//Linked List is empty
	if(head == NULL){
		struct node *new = (struct node*) malloc(sizeof(struct node));
		new->data = data;
		new->next = NULL;
		
		head = tail = new;
	}
	//Linked List is NOT empty
	else{
		struct node *new = (struct node*) malloc(sizeof(struct node));
		new->data = data;
		new->next = NULL;
		
		tail->next = new;
		
		tail = new;
		
	}
}

//Add Node to Head
int addNodeHead(){
	//Linked List is empty
	if(head == NULL){
		struct node *new = (struct node*) malloc(sizeof(struct node));
		new->data = data;
		new->next = NULL;
		head = tail = new;
	}
	//Linked List is NOT empty
	else{
		struct node *new = (struct node*) malloc (sizeof(struct node));
		new->data = data;
		new->next = head;
		head = new;
	}
}

//Print
int print(){
	printf("Linked List:");
	struct node *index = head;
	while(index != NULL){
		printf("%d -",index->data);
		index = index->next;
	}
	
}

int main(){
	addNode(3);
	addNode(10);
	addNode(99);
	
	addNodeHead(1);
	addNodeHead(-3);
	
	printf();
	
	return 1;
}
