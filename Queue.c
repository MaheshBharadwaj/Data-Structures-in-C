#include <stdlib.h>
#include <stdio.h>

typedef int Data;

typedef struct Node{
	Data d;
	struct Node * next ;
}Node;


typedef Node * Queue;

int isEmpty(Queue front,Queue rear){
	if(front == 0 || rear == 0)
		return 1;
	return 0;
}

void enqueue(Queue *front,Queue *rear,Data d){
	
	Node * tmp = (Node*)malloc(sizeof(Node));
	tmp -> d = d;
	tmp -> next = NULL;

	if(isEmpty(*front,*rear))
		(*front) = (*rear) = tmp;
	else{
		(*rear) -> next = tmp;
		(*rear) = tmp;
	}

}

Data dequeue(Queue * front,Queue * rear){
	Node rval;
	rval.d = -1;
	Node * tmp;

	if(isEmpty(*front,*rear)){
		printf("Queue Empty!\n");
		return rval.d;
	}

	rval = *(*front);
	tmp = (*front);

	if( (*front) == (*rear) )
		(*front) = (*rear) = 0;
	else
		(*front) = (*front) -> next;
	
	
	free(tmp);
	return rval.d;
}


void displayQueue(Queue front,Queue rear){
	if(isEmpty(front,rear))
		printf("Empty Queue!\n");
	else{
		Queue tmp = front;
		while(tmp){
			printf("%d ",tmp -> d);
			tmp = tmp -> next;
		}
	}
}


int main(void){
	Queue front = NULL,rear = NULL;
	int opt,tmp;

	while(1){
		printf("1 - Enqueue\n2 - Dequeue\n3 - Print Queue\n4 - Exit\n");
		printf("Enter your choice: ");
		scanf("%d",&opt);

		switch(opt){
			case 1: {
					 printf("Enter the number to add: ");
					 scanf("%d",&tmp);
					 enqueue(&front,&rear,tmp);
					}
					break;
			case 2: {
					 printf("The number dequeued: %d\n",dequeue(&front,&rear));
					}
					break;
			case 3: {
					 printf("Elements in Queue:\n");
					 displayQueue(front,rear);
					 printf("\n");
					}
					break;
			case 4: return 0; 

		}	
	}
}