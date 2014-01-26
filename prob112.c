//
//  prob112.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 11/30/13.
//  Copyright (c) 2013 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#define MAX 9999999

typedef struct tree{
	int value;
	struct tree *right, *left;
} tree;

typedef struct stack{
	tree **elements;
	int top;
}	stack;

int push(stack *s, tree *value){
	if(s->top < MAX){
		s->elements[++s->top] = value;
		return 0;
	}
	else{
		return 1;
	}
}

void init_stack(stack *s){
	s->elements = (tree**)malloc(MAX*sizeof(tree*));
}

int empty(stack *s){
	if(s->top == -1){
		return 1;
	}
	else
		return 0;
}


tree *pop(stack *s){
	if(!empty(s)){
		return s->elements[s->top--];
	}
	return NULL;
}

int clean(stack *s){
	s->top = -1;
	return 0;
}

int push_back(int *vec, int value, int *size){
	vec[++(*size)] = value;
	return 1;
}
	
int pop_back(int *vec, int *size){
	if(*size == -1)
		return -1;
	else
		return vec[--(*size)];
}

int get_sum(tree *root, int i, int sum){
	int left, right;
	sum += root->value;
	if(!root->left && !root->right){
		if(sum == i){
			return 1;
		}
		else{
			return 0;
		}
	}
	if(root->left){
		left = get_sum(root->left, i, sum);
	}
	else{
		left = 0;
	}
	if(root->right){
		right = get_sum(root->right, i, sum);
	}
	else{
		right = 0;
	}
	if(left || right){
		return 1;
	}
	else{
		return 0;
	}
}

void deleteTree(tree *root){
	if(root){
		deleteTree(root->left);
		deleteTree(root->right);
		free(root);
	}
}

void remove_stack(stack *s){
	free(s->elements);
}

int main(){
	tree *root, *fc, *sc, *head;
	tree *node;
	stack roots;
	char c;
	int *recLev, i, k, numb, lev, first, exist;
	int *balance = {0}, top, check;
	lev = -1;
	first = 1;
	clean(&roots);
	top = -1;
	init_stack(&roots);
	recLev = (int*)malloc(MAX*sizeof(int));
	balance = (int*)malloc(MAX*sizeof(int));
	scanf("%d", &i);
	while(1){
		k = scanf("%c", &c);
		//printf("%c", c);
		if(k == EOF){
			break;
		}
		if(c == '('){
			push_back(balance, 1, &top);
			//printf("%c", c);
			k = scanf("%d", &numb);
			if(!k){
				k = scanf("-%d", &numb);
				numb = -numb;
			}
			if(k){
				//printf("%d", numb);
				node = (tree *)malloc(sizeof(tree));
				node->value = numb;
				push_back(recLev, 0, &lev);
				push(&roots, node);
				if(first){
					head = node;
					first = 0;
				}
			}
			else{
				//printf("TESTE");
				push(&roots, NULL);
			}
		}
		else if(c == ')'){
			//printf("%c", c);
			check = pop_back(balance, &top);
			if(top == -1){
				//printf("i = %d\n", i);
				exist = get_sum(head, i, 0);
				if(exist && !first){
					printf("yes\n");
				}
				else{
					printf("no\n");
				}
				//printf("-----------------------\n");
				k = scanf("%d", &i);
				lev = -1;
				first = 1;
				clean(&roots);
				if(!first){
					deleteTree(head);
				}
				if(k == EOF){
					break;
				}
				
			}
			if(lev > -1){
				recLev[lev]++;
			}
			if(recLev[lev] == 2){
				//printf("B_TOP %d\n", roots.top);
				fc = pop(&roots);
				sc = pop(&roots);
				root = pop(&roots);
				root->right = fc;
				root->left = sc;
				push(&roots, root);
				pop_back(recLev, &lev);
				//printf("A_TOP %d\n", roots.top);
				//printf("LEV %d RECLEV %d\n", lev, recLev[lev]);
			}
		}
	}
	free(recLev);
	free(balance);
	remove_stack(&roots);
	return 0;
}