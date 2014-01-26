//
//  prob657.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 12/26/13.
//  Copyright (c) 2013 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#define MAX 99999

typedef struct node{
	int i;
	int j;
} node;

void push(node s[MAX], int *top, int i, int j){
	node n;
	n.i = i;
	n.j = j;
	s[++(*top)] = n;
}

node pop(node s[MAX], int *top){
	return s[(*top)--];
}

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

void other_dfs(char pic[100][100], int x_mark[100][100], int curr_i, int curr_j, int cols, int rows){
	node stack[MAX];
	node next;
	int top;
	top = -1;
	push(stack, &top, curr_i, curr_j);
	while(top != -1){
		//left
		if(curr_j+1 < cols && pic[curr_i][curr_j+1] == 'X' && !x_mark[curr_i][curr_j+1]){
			push(stack, &top, curr_i, curr_j+1);			
		}
		//right
		if(curr_j-1 >= 0 && pic[curr_i][curr_j-1] == 'X' && !x_mark[curr_i][curr_j-1]){
			push(stack, &top, curr_i, curr_j-1);
		}
		//up
		if(curr_i+1 < rows && pic[curr_i+1][curr_j] == 'X' && !x_mark[curr_i+1][curr_j]){
			push(stack, &top, curr_i+1, curr_j);
		}
		//down
		if(curr_i-1 >= 0 && pic[curr_i-1][curr_j] == 'X' && !x_mark[curr_i-1][curr_j]){
			push(stack, &top, curr_i-1, curr_j);
		}
		next = pop(stack, &top);
		curr_i = next.i;
		curr_j = next.j;
		x_mark[curr_i][curr_j] = 1;
	}
}

void dfs(int mark[100][100], int x_mark[100][100], char pic[100][100], int curr_i, int curr_j, int cols, int rows, int *count){
	node stack[MAX];
	node next;
	int top;
	top = -1;
	push(stack, &top, curr_i, curr_j);
	while(top != -1){
		//left
		if(curr_j+1 < cols && pic[curr_i][curr_j+1] != '.' && !mark[curr_i][curr_j+1]){
			push(stack, &top, curr_i, curr_j+1);
		}
		//right
		if(curr_j-1 >= 0 && pic[curr_i][curr_j-1] != '.' && !mark[curr_i][curr_j-1]){
			push(stack, &top, curr_i, curr_j-1);
		}
		//up
		if(curr_i+1 < rows && pic[curr_i+1][curr_j] != '.' && !mark[curr_i+1][curr_j]){
			push(stack, &top, curr_i+1, curr_j);
		}
		//down
		if(curr_i-1 >= 0 && pic[curr_i-1][curr_j] != '.' && !mark[curr_i-1][curr_j]){
			push(stack, &top, curr_i-1, curr_j);
		}
		next = pop(stack, &top);
		curr_i = next.i;
		curr_j = next.j;
		if(pic[curr_i][curr_j] == 'X' && !x_mark[curr_i][curr_j]){
			other_dfs(pic, x_mark, curr_i, curr_j, cols, rows);
			(*count)++;
		}
		mark[curr_i][curr_j] = 1;
	}
}

int main(){
	int rows, cols, i, j, count, k, t;
	char pic[100][100];
	int mark[100][100], res[100], x_mark[100][100];
	t = 1;
	scanf("%d %d\n", &cols, &rows);
	while(cols && rows){
		for(i = 0; i < rows; i++){
			scanf("%s", pic[i]);
		}
		/*
		for(i = 0; i < rows; i++){
			printf("%s\n", pic[i]);
		}
		*/
		for(i = 0; i < rows; i++){
			for(j = 0; j < cols; j++){
				mark[i][j] = 0;
				x_mark[i][j] = 0;
			}
		}
		
		k = 0;
		for(i = 0; i < rows; i++){
			for(j = 0; j < cols; j++){
				if(!mark[i][j] && !x_mark[i][j] && pic[i][j] != '.'){
					count = 0;
					dfs(mark, x_mark, pic, i, j, cols, rows, &count);
					res[k] = count;
					k++;
				}
			}
		}
		printf("Throw %d\n", t++);
		qsort(res, k, sizeof(int), compare);
		for(i = 0; i < k; i++){
			printf("%d", res[i]);
			if(i != k-1){
				printf(" ");
			}
		}
		printf("\n\n");
		scanf("%d %d\n", &cols, &rows);
	}
	return 0;
}