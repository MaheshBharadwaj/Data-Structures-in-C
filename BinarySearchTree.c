#include <stdio.h>
#include <stdlib.h>
//#include <string.h> for strings

typedef int Data;

typedef struct treenode{
	Data d;
	struct treenode * left;
	struct treenode * right;
}Node;

typedef Node* Tree;

Tree createEmptyTree(){
	return 0;
}

Tree insert(Tree t,Data d){
	if(t == NULL){
		Tree tmp = (Tree)malloc(sizeof(Node));
		tmp -> d = d;
		//strcpy(tmp -> d,d); for strings
		tmp -> right = tmp -> left = NULL;
		t = tmp;
	}

	//USE STRCMP FOR STRINGS
	else if(d < t -> d)
		t -> left = insert(t -> left,d);
	else if(d > t -> d)
		t -> right = insert(t -> right,d);
	else;	//element already exists
	return t;
}

Tree findMinimum(Tree t){
	if(t == 0)
		return 0;
	Tree tmp  = t;
	while(tmp -> left)
		tmp = tmp -> left;
	return tmp;
}

Tree findMaximum(Tree t){
	if(t == 0)
		return 0;
	Tree tmp = t;
	while(tmp -> right)
		tmp = tmp -> right;
	return tmp;
}

Tree delete(Tree t,Data d){
	if(t == NULL){
		printf("Not Found!");
		return 0;
	}

	//USE STRCMP FOR STRINGS
	else if(d < t -> d)
		t -> left = delete(t -> left,d);
	else if(d > t -> d) 
		t -> right = delete(t-> right,d);
	else{
		if(t -> left && t -> right){
			Tree tmp = findMinimum(t -> right);
			t -> d = tmp -> d;
			delete(t -> right,tmp -> d);
		}
		else{
			Tree tmp = t;
			if(t -> left == NULL)
				t = t -> right;
			else if(t -> right == NULL)
				t = t -> left;
			free(tmp);
		}
	}
	return t;
}

void inorder(Tree t){
	if(t == NULL)
		return;
	inorder(t -> left);
	printf("%d ",t -> d);
	inorder(t -> right);
}

int main(void){
	Tree t = createEmptyTree();
	int opt;
	Data d;	

	while(1){

		printf(" 1 - Add element to BST\n");
		printf(" 2 - Print maximum\n");
		printf(" 3 - Print Minimum\n");
		printf(" 4 - Delete element\n");
		printf(" 5 - Display BST\n");
		printf(" 6 - Exit\n");
		printf(" ---------------------------------\n");
		printf(" Enter choice: ");
		scanf("%d",&opt);

		switch(opt){
			case 1: {
					printf(" Enter the value to add: ");
					scanf("%d",&d);
					 t = insert(t,d);
					}
					break;
			case 2: {
					Tree tmp = findMaximum(t);
					if(tmp != NULL)
						printf(" The maximum element is: %d\n",tmp -> d);
					}
					break;
			case 3: {
					Tree tmp = findMinimum(t);
					if(tmp != NULL)
						printf(" The Minimum Element is: %d\n",tmp -> d);
					}
					break;
			case 4: {
					printf(" Enter the value to delete: ");
					scanf("%d",&d);
					t = delete(t,d);
					}
					break;
			case 5: {
					inorder(t);
					printf("\n");
					}break;
			case 6: return 0;
			default:printf("\nInvalid Input!\n");
		}
	}
}