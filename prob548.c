//
//  prob548.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 12/3/13.
//  Copyright (c) 2013 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#define MAX 999999
#define INFINITE 999999

typedef struct treeNode{
	int value;
	struct treeNode *left, *right;
} treeNode;

int push(int *s, int value, int *top){
	s[++(*top)] = value;
	return 0;
}

treeNode* buildTree(int *inorder, int *postorder, int i_inf, int i_sup, int p_inf, int p_sup){
	int i, i_mid, shift;
	treeNode *root;
	if(i_inf <= i_sup && p_inf <= p_sup){
		root = (treeNode*)malloc(sizeof(treeNode));
		root->value = postorder[p_sup];
		for(i = i_inf; i <= i_sup; i++){
			if(inorder[i] == root->value){
				shift = i - i_inf;
				break;
			}
		}
		root->left = buildTree(inorder, postorder, i_inf, i_inf+shift-1, p_inf, p_inf+shift-1);
		root->right = buildTree(inorder, postorder, i_inf+shift+1, i_sup, p_inf+shift, p_sup-1);
		return root;
	}
	else 
		return NULL;
}

void printTree(treeNode* root){
	if(root){
		printf("%d\n", root->value);
		printTree(root->left);
		printTree(root->right);
	}
}

typedef struct node{
	int path_value;
	int value;
}node;

node getPathOfLeastValue(treeNode* root){
	node left, right, leaf;
	if(root){
		if(!root->left && !root->right){
			leaf.path_value = root->value;
			leaf.value = root->value;
			return leaf;
		}
		else{
			if(root->left){
				left = getPathOfLeastValue(root->left);
				left.path_value += root->value;
			}
			else{
				left.path_value = INFINITE;
			}
			if(root->right){
				right = getPathOfLeastValue(root->right);
				right.path_value += root->value; 
			}
			else{
				right.path_value = INFINITE;
			}
			if(left.path_value > right.path_value){
				return right;
			}
			else{
				return left;
			}
		}
	}
}

void deleteTree(treeNode *root){
	if(root){
		deleteTree(root->left);
		deleteTree(root->right);
		free(root);
	}
}
int main(){
	int numb, inorder[MAX], postorder[MAX], full, i_top, p_top, k, count, i;
	char c;
	full = 0;
	i_top = -1;
	p_top = -1;
	count = 0;
	node least_leaf;
	treeNode *root = NULL;
	numb = 0;
	while(1){
		k = scanf("%c", &c);
		if(k == EOF)
			break;
		if(c == ' ' || c == '\n'){
			//printf("%d\n", numb);
			if(!full){
				push(inorder, numb, &i_top);
			}
			else{
				push(postorder, numb, &p_top);
			}
			numb = 0;
			if(c == '\n'){
				count++;
				full = !full;
				if(count == 2){
					root = buildTree(inorder, postorder, 0, i_top, 0, p_top);
					//printTree(root);
					least_leaf = getPathOfLeastValue(root);
					printf("%d\n", least_leaf.value);
					deleteTree(root);
					i_top = -1;
					p_top = -1;
					count = 0;
					full = 0;
				}
			}
		}
		else if(c >= '0' && c <= '9'){
			numb *= 10;
			numb += c - '0';
		}
	}
	/*
	for(i = 0; i <= i_top; i++){
			printf("%d ", inorder[i]);
		}
		printf("\n");
	for(i = 0; i <= i_top; i++){
		printf("%d ", postorder[i]);
	}*/
	return 0;
}