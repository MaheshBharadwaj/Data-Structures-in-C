#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char Data[30];

typedef struct avlnode{
	Data d;
	struct avlnode * left , * right;
	short int height;
}AVLTreeNode;

typedef AVLTreeNode * AVLTree;

static int height(AVLTree t){
	if(t == NULL)
		return -1;

	return t -> height;
}

int max(int a,int b){
	return ((a > b)? a : b);
}

static AVLTree singlerotatewithleft(AVLTree k2){
	AVLTree k1;
	k1 = k2 -> left;
	k2 -> left = k1 -> right;
	k1 -> right = k2;

	k2 -> height = max(height(k2 -> left),height(k2 -> right)) + 1;
	k1 -> height = max(height(k1 -> left),k2 -> height) + 1;

	return k1;
}

static AVLTree singlerotatewithright(AVLTree k2){
	AVLTree k1;
	k1 = k2 -> right;
	k2 -> right = k1 -> left;
	k1 -> left = k2;
	
	k2 -> height = max(height(k2 -> left),height(k2 -> right)) + 1;
	k1 -> height = max(height(k1 -> left),k2 -> height) + 1;

	return k1;
}

static AVLTree doublerotatewithleft(AVLTree k3){
	k3 -> left = singlerotatewithright(k3 -> left);

	return singlerotatewithleft(k3);
}

static AVLTree doublerotatewithright(AVLTree k3){
	k3 -> right = singlerotatewithleft(k3 -> right);

	return singlerotatewithright(k3);
}


AVLTree insert(Data d,AVLTree t){
	if(t == NULL){
		t = (AVLTree)malloc(sizeof(AVLTreeNode));
		strcpy(t -> d, d);
		t -> left = t -> right = NULL;
	}
	else if(strcmp(d,t -> d) < 0){
		t -> left = insert(d,t -> left);
		if(height(t -> left) - height(t -> right) == 2)
			if(strcmp(d,t -> left -> d) < 0){
				printf("\nSingle rotate with left performed!\n");
				t = singlerotatewithleft(t);
			}
			else{
				printf("\nDouble rotate with left performed!\n");
				t = doublerotatewithleft(t);			
			}
	}

	else if(strcmp(d,t -> d) > 0){
		t -> right = insert(d,t -> right);
		if(height(t -> right) - height(t -> left) == 2)
			if(strcmp(d,t -> right -> d) > 0){
				printf("\nSingle rotate with right performed!\n");
				t = singlerotatewithright(t);
			}
			else{
				printf("\nDouble rotate with right performed!\n");
				t = doublerotatewithright(t);
			}
	}

	t -> height = max(height(t -> left),height(t -> right)) + 1;
	return t;
}

AVLTree search(AVLTree t,Data d){
	if(t == NULL){
		printf("Not found!\n");
		return 0;
	}

	if(strcmp(d,t -> d) < 0)
		return search(t -> left,d);
	else if(strcmp(d,t -> d) > 0)
		return search(t -> right,d);
	else
		return t;
}


AVLTree findMinimum(AVLTree t){
	if(t == 0)
		return 0;
	AVLTree tmp  = t;
	while(tmp -> left)
		tmp = tmp -> left;
	return tmp;
}

AVLTree findMaximum(AVLTree t){
	if(t == 0)
		return 0;
	AVLTree tmp = t;
	while(tmp -> right)
		tmp = tmp -> right;
	return tmp;
}



void inorder(AVLTree t){
	if(t == NULL)
		return;
	inorder(t -> left);
	printf("%s\t",t -> d);
	inorder(t -> right);
}


int main(void){
	AVLTree t = 0;
	int opt;
	Data d;	

	while(1){

		printf(" 1 - Add element to AVL Tree\n");
		printf(" 2 - Print maximum\n");
		printf(" 3 - Print Minimum\n");
		printf(" 4 - Search for element\n");
		printf(" 5 - Display BST\n");
		printf(" 6 - Exit\n");
		printf(" ---------------------------------\n");
		printf(" Enter choice: ");
		scanf("%d",&opt);

		switch(opt){
			case 1: {
					printf(" Enter the value to add: ");
					scanf("%s",d);
					 t = insert(d,t);
					}
					break;
			case 2: {
					AVLTree tmp = findMaximum(t);
					if(tmp != NULL)
						printf(" The maximum element is: %s\n",tmp -> d);
					}
					break;
			case 3: {
					AVLTree tmp = findMinimum(t);
					if(tmp != NULL)
						printf(" The Minimum Element is: %s\n",tmp -> d);
					}
					break;
			case 4: {
					printf(" Enter the value to search: ");
					scanf("%s",d);
					AVLTree tmp = search(t,d);
					if(tmp != NULL)
						printf(" Value found!\n");
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
