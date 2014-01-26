//
//  prob818.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 11/18/13.
//  Copyright (c) 2013 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#define INFINITE 9999999

typedef struct vector{
	int *vector;
	int size;
} vector;

typedef struct list{
	vector **list;
	int size;
} list;

int pop_front(vector *vec){
	int *temp;
	int e, i;
	if(vec->size == 0){
		return -1;
	}
	else{
		vec->size--;
		temp = malloc((vec->size)*sizeof(int));
		for(i = 0; i < vec->size; i++){
			temp[i] = vec->vector[i+1];
		}
		e = vec->vector[0];
		free(vec->vector);
		vec->vector = temp;
		return e;
	}
}

int push(vector *vec, int value){
	int i;
	int *temp;
	vec->size++;
	temp = malloc(vec->size*sizeof(int));
	for(i = 0; i < vec->size-1; i++){
		temp[i] = vec->vector[i];
	}
	temp[vec->size-1] = value;
	free(vec->vector);
	vec->vector = temp;
	return 0;
}

void clear(vector *vec){
	vec->vector = NULL;
	vec->size = 0;
}

int insert(list *l, vector vec){
	int i;
	vector **temp;
	l->size++;
	temp = malloc((l->size)*sizeof(vector*));
	for(i = 0; i < l->size; i++){
		temp[i] = l->list[i];
	}
	temp[l->size] = &vec;
	free(l->list);
	l->list = temp;
	return 0;
}

int* breadth_first_search(int **cost, int v, int source){
	int *distance;
	int i, next;
	distance = malloc(v*sizeof(int));
	vector queue;
	
	for(i = 0; i < v; i++){
		distance[i] = INFINITE;
	}
	distance[source] = 0;
		
	clear(&queue);
	for(i = 0; i < v; i++){
		if(cost[source][i]){
			push(&queue, i);
			distance[i] = cost[source][i];
		}
	}
	while(queue.size){
		next = queue.vector[queue.size-1];
		for(i = 0; i < v; i++){
			if(cost[next][i]){
				if(distance[next] + cost[next][i] <= distance[i]){
					distance[i] = distance[next] + cost[next][i];
					push(&queue, i);
				}
			}
		}
		pop_front(&queue);
	}
	return distance;
}


int main(){
	int i, j, t = 0, c, e, l, p, x, y, first;
	int **matrix = NULL;
	int *distance;
	
	scanf("%d %d %d %d", &c, &e, &l, &p);
	while(c){
		t++;
		matrix = malloc(c*sizeof(int*));
		for(i = 0; i < c; i++){
			matrix[i] = malloc(c*sizeof(int));
		}
		for(i = 0; i < e; i++){
			scanf("%d %d", &x, &y);
			matrix[x-1][y-1] = 1;
			matrix[y-1][x-1] = 1;
		}
		
		printf("Teste %d\n", t);
		
		/*
		// Print Adjacent List
		for(i = 0; i < c; i++){
			for(j = 0; j < c; j++){
				printf("%d ", matrix[i][j]);
			}
			printf("\n");
		}
		*/
		distance = breadth_first_search(matrix, c, l-1);

		first = 1;
		for(i = 0; i < c; i++){
			if((distance[i] <= p) && (distance[i] != 0)){
				if(first){
					printf("%d", i+1);
					first = 0;
				}
				else{
					printf(" %d", i+1);
				}
			}
		}
	
		printf("\n");
		scanf("%d %d %d %d", &c, &e, &l, &p);
		if(c){
			printf("\n");
		}
	}
	return 0;
}