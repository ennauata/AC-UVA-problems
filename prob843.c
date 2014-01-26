//
//  prob843.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 11/22/13.
//  Copyright (c) 2013 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 99999999

int min(int *vec, int size){
	int min, i;
	min = vec[0];
	for(i = 0; i < size; i++){
		if(vec[i] < min){
			min = vec[i];
		}
	}
	return min;
}

int max(int *vec, int size){
	int max, i;
	max = vec[0];
	for(i = 0; i < size; i++){
		if(vec[i] > max){
			max = vec[i];
		}
	}
	return max;
}

int min_distance(int *vec, int size,int inf, int sup){
	int i, j, min, sum, i_min;
	min = MAX;
	for(i = inf; i <= sup; i++){
		sum = 0;
		for(j = 0; j < size; j++){
			sum += abs(i - vec[j]);
		}
		if(sum < min){
			min = sum;
			i_min = i;
		}
	}
	return i_min;
}


int main(){
	int n, x, y, i, t = 1, inf, sup;
	int *x_coord, *y_coord, dist_x, dist_y;

	scanf("%d", &n);
	while(n){
		x_coord = malloc(n*sizeof(int));
		y_coord = malloc(n*sizeof(int));
		for(i = 0; i < n; i++){
			scanf("%d %d", &x, &y);
			x_coord[i] = x;
			y_coord[i] = y;
		}
		inf = min(x_coord, n);
		sup = max(x_coord, n);
		dist_x = min_distance(x_coord, n, inf, sup);
		inf = min(y_coord, n);
		sup = max(y_coord, n);
		dist_y = min_distance(y_coord, n, inf, sup);
		free(x_coord);
		free(y_coord);
		printf("Teste %d\n", t++);
		printf("%d %d\n", dist_x, dist_y);
		scanf("%d", &n);
		printf("\n");
	}
}