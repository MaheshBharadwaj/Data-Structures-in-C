#include <stdio.h>
#include <stdlib.h>

//Change as required
typedef int Data;

typedef struct List{
	int capacity;
	int size;
	Data * array;
}List;

List* createList( int c){
	List * L = (List*)malloc(sizeof(List));
	if(!L){
		printf("Memory Allocation Error!");
		exit(0);
	}

	L -> size = 0;
	L -> capacity = c;

	L -> array = (Data*)malloc(sizeof(Data) * c);
	if (!L -> array){
		printf("Memory Allocation Error!");
		exit(0);
	}

	return L;
}

int isFull( List *  L){
	return L -> size == L -> capacity;
}

int isEmpty( List *  L){
	return L -> size == 0;
}

void addEnd(List *  L, Data S){
	if(isFull(L)){
		printf("List Full!");
		return;
	}

	L -> array[L -> size] = S;
	L -> size++;

}

void addStart(List *  L, Data S){
	if(isFull(L)){
		printf("List Full!");
		return;
	}

	for(int i = L -> size ; i > 0 ; i--)
		L -> array[i] = L -> array[i-1];

	L -> array[0] = S;
	L -> size++;
	
}


void putList( List *  L){
	if(isEmpty(L)){
		printf("List Empty!\n");
		return;
	}

	for(int i = 0 ; i < L -> size ; i++)
		printf("%d ",L -> array[i]);
}

int main(void){
	List * L = createList(10);
	int opt,tmp;

	while(1){
		printf("1 - Add Start\n2 - Add End\n3 - Print List\n4 - Exit\n");
		printf("Enter your choice: ");
		scanf("%d",&opt);

		switch(opt){
			case 1: {
					 printf("Enter the number to add: ");
					 scanf("%d",&tmp);
					 addStart(L,tmp);
					}
					break;
			case 2: {
					 printf("Enter the number to add: ");
					 scanf("%d",&tmp);
					 addEnd(L,tmp);
					}
					break;
			case 3: {
					 printf("\nElements in list are: \n");
					 putList(L);
					 printf("\n");
					}
					break;
			case 4: return 0; 

		}	
	}
}