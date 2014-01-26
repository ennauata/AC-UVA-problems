//
//  prob818.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 11/18/13.
//  Copyright (c) 2013 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#define INFINITE 2500

typedef struct edge{ 
	int to;
	int from;
	int weigth;
} edge;

typedef struct vector{
	edge *vector;
	int size;
} vector;

int* bellmann_ford(vector edges, int l, int v){
	int i, j;
	int *distance;
	
	// Initialization
	distance = malloc(v*sizeof(int));
	for(i = 0; i < v; i++){
		distance[i] = INFINITE;
	}
	distance[l-1] = 0;
	
	for(i = 0; i < 2; i++){
		for(j = 0; j < edges.size; j++){
			if(distance[edges.vector[j].from] + edges.vector[j].weigth < distance[edges.vector[j].to]){
				distance[edges.vector[j].to] = distance[edges.vector[j].from] + edges.vector[j].weigth;
			}
		}
	}
	return distance;
}

int push(vector *vec, edge value){
	int i;
	edge *temp;
	vec->size++;
	temp = malloc((vec->size)*sizeof(edge));
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
int main(){
	int i, t = 0, c, e, l, p, x, y, first;
	edge edge;
	vector edges;
	int *distance;
	
	scanf("%d %d %d %d", &c, &e, &l, &p);
	while(c){
		t++;
		clear(&edges);
		for(i = 0; i < e; i++){
			scanf("%d %d", &x, &y);
			edge.to = y-1;
			edge.from = x-1;
			edge.weigth = 1;
			push(&edges, edge);
			edge.to = x-1;
			edge.weigth = 1;
			edge.from = y-1;
			push(&edges, edge);
		}
		
		distance = bellmann_ford(edges, l, c);
		
		printf("Teste %d\n", t);
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
		free(distance);
		scanf("%d %d %d %d", &c, &e, &l, &p);
		if(c){
			printf("\n");
		}
	}
	return 0;
}