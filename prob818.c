//
//  prob818.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 11/18/13.
//  Copyright (c) 2013 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int main(){
	int i, a, v, x, y, j, sum_l, sum_c, l = 0, max, first;
	int **matrix;
	int *list;
	scanf("%d %d", &a, &v);
	while(a){
		l++;
		matrix = malloc((a+1)*sizeof(int*));
		for(i = 0; i < (a+1); i++){
			matrix[i] = malloc((a+1)*sizeof(int));
			for(j = 0; j < (a+1); j++){
				matrix[i][j] = 0;
			}
		}
		for(i = 0; i < v; i++){
			scanf("%d %d", &x, &y);
			matrix[x][y]++;
		}
		list = malloc((a+1)*sizeof(int));
		for(i = 1; i < (a+1); i++)
			list[i]=0;
		for(i = 1; i < (a+1); i++){
			sum_l = 0;	
			sum_c = 0;
			for(j = 1; j < (a+1); j++){
				sum_l += matrix[i][j];
				sum_c += matrix[j][i];
			}
			list[i] += sum_l; 
			list[i] += sum_c;
		}
		
		printf("Teste %d\n", l);
		max = -1;
		for(i = 1; i < (a+1); i++){
			if(list[i] > max){
				max = list[i];
			}
		}
		first = 1;
		for(i = 1; i < (a+1); i++){
			if(list[i] == max){
				if(first){
					printf("%d", i);
					first = !first;
				}
				else{
					printf(" %d", i);
				}
			}
		}
		printf("\n");
		scanf("%d %d", &a, &v);
		if(a) 
			printf("\n");
		free(list);
	}
	return 0;
}