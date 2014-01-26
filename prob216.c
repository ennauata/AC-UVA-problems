//
//  prob216.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 12/9/13.
//  Copyright (c) 2013 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 99999

typedef struct coord{
	int x;
	int y;
	int used;
} coord;

typedef struct stack{
	int top;
	coord itens[MAX];
} stack;

int init(stack *s){
	s->top = -1;
	return 0;
}

int push(stack *s, coord node){
	s->itens[++(s->top)] = node;
	return 0;
}

float calc_distance(int x1, int y1, int x2, int y2){
	return 16+sqrt(pow((x1-x2),2)+pow(y1-y2, 2));	
}

void calc_network(coord *vector, int size, float *sum, coord *path, coord *res, int recLev, float *dist_res){
	int i;
	float dist, sum_linha;
	float dists[MAX];
	for(i = 0; i < size; i++){
		if(!vector[i].used){
			vector[i].used = 1;
			path[recLev] = vector[i];
			calc_network(vector, size, sum, path, res, recLev+1, dist_res);
			vector[i].used = 0;
		}
	}
	sum_linha = 0;
	for(i = 0; i < size-1; i++){
		dist = calc_distance(path[i].x, path[i].y, path[i+1].x, path[i+1].y);
		sum_linha += dist;
		dists[i] = dist;
	}
	//printf("%.2f\n", sum_linha);
	if(sum_linha < *sum){
		*sum = sum_linha;
		for(i = 0; i < size; i++){
			res[i] = path[i];
			dist_res[i] = dists[i];
		}
	}
}

int main(){
	int n, x, y, i, t=0;
	float sum, dist_res[MAX];
	coord vector[MAX], path[MAX], res[MAX];
	coord node;
	scanf("%d\n", &n);
	while(n){
		for(i = 0; i < n; i++){
			scanf("%d %d", &x, &y);
			node.x = x;
			node.y = y;
			node.used = 0;
			vector[i] = node;
		}
		sum = MAX;
		calc_network(vector, n, &sum, path, res, 0, dist_res);
		printf("**********************************************************\n");
		printf("Network #%d\n", ++t);
		for(i = 0; i < n - 1; i++){
			printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2f feet.\n", res[i].x, res[i].y, res[i+1].x, res[i+1].y, dist_res[i]);
		}
		printf("Number of feet of cable required is %.2f.\n", sum);
		scanf("%d", &n);
	}

}