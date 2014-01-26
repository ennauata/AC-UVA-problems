//
//  File.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 1/2/14.
//  Copyright (c) 2014 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int max(int a, int b){
	if(a > b){
		return a;
	}
	else{
		return b;
	}
}
int main(){
	int **matrix, t, i, j, m, sum, k, res;
	int values[105];
	 
	matrix = (int **)malloc(105*sizeof(int*));
	for(i = 0; i < 105; i++){
		matrix[i] = (int *)malloc(25010*sizeof(int));
	}
	scanf("%d", &t);
	for(k = 0; k < t; k++){
		scanf("%d", &m);
		sum = 0;
		for(i = 1; i <= m; i++){
			scanf("%d", &values[i]);
			sum += values[i];
		}
		/*
		for(i = 1; i <= m; i++ ){
			printf("%d ", values[i]);
		}
		printf("\n");
		*/
		for(i = 0; i <= m; i++){
			for(j = 0; j <= sum/2; j++){
				matrix[i][j] = 0;
			}
		}
		for(i = 0; i <= m; i++){
			matrix[i][0] = 0;
		}
		for(i = 0; i <= sum/2; i++){
			matrix[0][i] = 0;
		}
		/*
		for(i = 1; i <= m; i++){
			for(j = 1; j <= sum/2; j++){
				printf("%d ", matrix[i][j]);
			}
			printf("\n");
		}
		printf("\n");
		*/
		for(i = 1; i <= m; i++){
			for(j = 1; j <= sum/2; j++){
				if(values[i] > j){
					matrix[i][j] = matrix[i-1][j];
				}
				else{
					matrix[i][j] = max(matrix[i-1][j], values[i] + matrix[i-1][j-values[i]]);
				}
			}
		}
		/*
		for(i = 1; i <= m; i++){
			for(j = 1; j <= sum/2; j++){
				printf("%d ", matrix[i][j]);
			}
			printf("\n");
		}
		*/
		res = abs(matrix[m][sum/2] - (sum-matrix[m][sum/2]));
		printf("%d\n", res);
		//printf("SUM = %d\n", sum);
	}
	for(i = 0; i < 105; i++){
		free(matrix[i]);
	}
	free(matrix);
	return 0;
}