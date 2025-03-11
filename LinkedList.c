#include <stdio.h>
#include <stdlib.h>

typedef int Data;

typedef struct Node{
	Data d;
	struct Node * next;
} Node;

int isEmpty(Node * head){
	return head -> next == 0;
}

Node* createEmptyList(){
	Node * tmp = (Node*)malloc(sizeof(Node));
	if(!tmp){
		printf("Fatal Error!\n");
		exit(0);
	}

	tmp->next = 0;
	return tmp;
}

void insert(Node * head,Data d){
	Node * tmp = (Node*)malloc(sizeof(Node)),
		 * ptr ;
	if(!tmp){
		printf("Fatal Error!\n");
		exit(0);
	}
	tmp -> d = d;
	tmp -> next = 0;
	if(isEmpty(head))
		head -> next = tmp;
	else{
		ptr = head -> next;
		while(ptr -> next)
			ptr = ptr -> next;
		ptr -> next = tmp;
	}
}

void putList(Node * head){
	if(!isEmpty(head)){
		Node * tmp = head -> next;
		while(tmp){
			printf("%d ",tmp -> d);
			tmp = tmp -> next;
		}
		printf("\n");
	}
	else
		printf("Empty List!\n");	
}


int main(void){
	Node * head = createEmptyList();
	int opt,tmp;

	while(1){
		printf("1 - Add \n2 - Print List\n3 - Exit\n");
		printf("Enter your choice: ");
		scanf("%d",&opt);

		switch(opt){
			case 1: {
					 printf("Enter the number to add: ");
					 scanf("%d",&tmp);
					 insert(head,tmp);
					}
					break;
			case 2: {
					 printf("\nElements in list are: \n");
					 putList(head);
					 printf("\n");
					}
					break;
			case 3: return 0; 

		}	
	}
}