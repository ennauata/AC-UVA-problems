//
//  prob1887.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 11/22/13.
//  Copyright (c) 2013 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct coord{
	long long int x, y;
	struct coord *next;
} coord;


coord *insert(long long int x,long long int y, coord *first){
	coord *newNode;
	coord *aux;
	newNode = malloc(sizeof(coord));
	newNode->x = x;
	newNode->y = y;
	if(!first){
		first = newNode;
		newNode->next = newNode;
	}
	else{
		aux = first->next;
		while(aux->next != first){
			aux = aux->next;
		}
		newNode->next = first;
		aux->next = newNode;
	}
	return first;
}

int push(long long int numb, long long int *stack, int size){
	stack[size++] = numb;
	return size;
}

int main(){
	int n, i, j, flag = 0, flag2 = 0, flag3 = 0, count;
	long long int x, y;	
	int size_col=0, size_row = 0;
	long long int row[200], col[200];
	coord *first = NULL, *aux, *aux_next;
	scanf("%d", &n);
	while(n){
	size_col = 0;
	size_row = 0;
	first = NULL;
	for(i = 0; i < n; i++){
		scanf("%lld %lld", &x, &y);
		first = insert(x, y, first);
	}
	aux = first;
	do {
		// Linha
		if(aux->x == aux->next->x){
			flag = 1;
		}
		// Coluna
		else{
			flag = 0;
		}
		
		if(flag){
			flag2 = 0;
			for(i = 0; i < size_col; i++){
				if(col[i] == aux->x){
					flag2 = 1;
				}
			}
			if(!flag2){
				size_col = push(aux->x, col, size_col);
			}
		}
		else{
			flag2 = 0;
			for(i = 0; i < size_row; i++){
				if(row[i] == aux->y){
					flag2 = 1;
				}
			}
			if(!flag2){
				size_row = push(aux->y, row, size_row);
			}
		}
  		aux = aux->next;
	} while (aux != first);
	count = 0;
	for(i = 0; i < size_row; i++){
		for(j = 0; j < size_col; j++){
			flag3 = 1;
			do {
				aux_next = aux->next;
				if(aux->x == aux_next->x && aux_next->x == col[j]){
					if(aux->y > aux_next->y){
						if(aux_next->y <= row[i] && row[i] <= aux->y){
							flag3 = 0;
						}
					}
					else{
						if(aux_next->y >= row[i] && row[i] >= aux->y){
							flag3 = 0;
						}
					}
				}
				else if(aux->y == aux_next->y && aux_next->y == row[i]){
					if(aux->x > aux_next->x){
						if(aux_next->x <= col[j] && col[j] <= aux->x){
							flag3 = 0;
						}
					}
					else{
						if(aux_next->x >= col[j] && col[j] >= aux->x){
							flag3 = 0;
						}
					}
				}
				aux = aux->next;
			} while (aux != first);
			if(flag3)
				count++;
		}
	}
	/*
	for(i = 0; i < size_row; i++){
		printf("%d ", row[i]);
	}
	printf("\n");
	for(i = 0; i < size_col; i++){
		printf("%d ", col[i]);
	}
	printf("\n");
	*/
	printf("%d\n", size_col + size_row - count/2);
	/*
	aux = first;
	do {
		printf("%d %d\n", aux->x, aux->y);
  		aux = aux->next;
	} while (aux != first);
	*/
	scanf("%d", &n);
		if(!n){
			printf("\n");
		}
	}
}