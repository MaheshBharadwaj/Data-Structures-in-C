#include <stdio.h>
#include <stdlib.h>

typedef int Data;

typedef struct Node{
	Data d;
	struct Node * next;
}Node;

typedef Node* Stack;

Stack createEmptyStack(){
	return 0;
}

int isEmpty(Stack top){
	return top == 0;
}

void push(Stack * top,Data d){
	Node * tmp = (Node*)malloc(sizeof(Node));
	tmp -> d = d;
	tmp -> next = 0;
	if(!isEmpty(*top))
		tmp -> next = (*top);
	(*top) = tmp;
}

Data pop(Stack * top){
	if(isEmpty(*top))
		return -1;

	Data rval = (*top) -> d;
	Node * tmp = *top;
	*top = (*top) -> next;
	free(tmp);
	return rval;
}

Data peek(Stack top){
	return top -> d; 
}


void displayStack(Stack top){
	Node * tmp = top;
	if(isEmpty(top)){
		printf("Empty Stack!");
		return;
	}
	while(tmp){
		printf("%d ",tmp -> d);
		tmp = tmp -> next;
	}
	printf("\n");
}


int main(void){
	Stack s = createEmptyStack();
	int opt,tmp;

	while(1){
		printf("1 - Push\n2 - Pop\n3 - Peek\n4 - Exit\n");
		printf("Enter your choice: ");
		scanf("%d",&opt);

		switch(opt){
			case 1: {
					 printf("Enter the number to add: ");
					 scanf("%d",&tmp);
					 push(&s,tmp);
					}
					break;
			case 2: {
					 printf("The number popped: %d\n",pop(&s));
					}
					break;
			case 3: {
					 printf("Top of stack: %d\n",peek(s));
					}
					break;
			case 4: return 0; 

		}	
	}
}