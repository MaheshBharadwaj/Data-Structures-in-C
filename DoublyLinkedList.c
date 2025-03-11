#include <stdio.h>
#include <stdlib.h>

typedef int Data;

typedef struct Node{
	Data d;
	struct Node * next;
	struct Node * prev;
}Node;


int isEmpty(Node * head,Node * tail){
	return head -> next == tail;
}

Node*  createEmptyList(){
	Node * head = (Node*)malloc(sizeof(Node)),
		 * tail = (Node*)malloc(sizeof(Node));

	head -> prev = 0;
	head -> next = tail;
	tail -> prev = head;
	tail -> next = 0;
	return head;
}


void addFirst(Node * head,Node * tail,Data d){
	Node * temp = (Node*)malloc(sizeof(Node));
	temp -> d = d;
	temp -> next = head ->next;
	temp -> prev = head;
	head -> next -> prev = temp;
	head -> next  = temp;
}

void addLast(Node * head , Node * tail,Data d){
	Node * temp = (Node*)malloc(sizeof(Node));
	temp -> d = d;
	temp -> next = tail;
	temp -> prev = tail -> prev;
	tail -> prev -> next = temp;
	tail -> prev = temp;
}


void putList(Node * head,Node * tail){
	if(isEmpty(head,tail)){
		printf("Empty List!\n");
		return;
	}

	Node * temp = head -> next;
	while(temp -> next){
		printf("%d ",temp -> d);
		temp = temp -> next;
	}
}

int main(void){
	Node * head = createEmptyList();
	Node * tail = head -> next;

	int opt,tmp;

	while(1){
		printf("1 - Add First\n2 - Add Last\n3 - Print List\n4 - Exit\n");
		printf("Enter your choice: ");
		scanf("%d",&opt);

		switch(opt){
			case 1: {
					 printf("Enter the number to add: ");
					 scanf("%d",&tmp);
					 addFirst(head,tail,tmp);
					}
					break;
			case 2: {
					 printf("Enter the number to add: ");
					 scanf("%d",&tmp);
					 addLast(head,tail,tmp);
					}
					break;
			case 3: {
					 printf("\nElements in list are: \n");
					 putList(head,tail);
					 printf("\n");
					}
					break;
			case 4: return 0; 

		}	
	}
}