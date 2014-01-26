//
//  prob11205.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 12/19/13.
//  Copyright (c) 2013 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>
#include <math.h>

typedef struct node{
	int used;
	int value;
} node;

void check(node bits[15], int p, int n, int matrix[100][15], int *possible){
	int i, j, k, dif;
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			if(i != j){
				dif = 0;
				for(k = 0; k < p; k++){
					if(matrix[i][k] != matrix[j][k] && bits[k].used){
						dif = 1;
					}
				}
				if(!dif){
					*possible = 0;
					break;
				}
			}
		}
		if(!(*possible)){
			break;
		}
	}
}

void brute_force(int n, int matrix[100][15], int *min, node bits[15], int p, int len, int next){
	int possible;
	
	if(next < p){
		bits[next].used = 1;
		brute_force(n, matrix, min, bits, p, len+1, next + 1);
		bits[next].used = 0;
		brute_force(n, matrix, min, bits, p, len, next + 1);
	}
   	else{
	
		/*for(i = 0; i < p; i++){
			printf("%d ", bits[i].used);
		}
		printf("\n");*/
	
		if(len < *min && len >= log2(n)){
			possible = 1;
			check(bits, p, n, matrix, &possible);
			if(possible){
				*min = len;
			}
		}
	}
}

int main(){
	int n, t, i, j, k, p, min;
	int matrix[100][15];
	node bits[15];
	scanf("%d", &t);
	for(i = 0; i < t; i++){
		scanf("%d", &p);
		scanf("%d", &n);
		for(j = 0; j < n; j++){
			for(k = 0; k < p; k++){
				scanf("%d", &matrix[j][k]);
			}
		}
		for(k = 0; k < p; k++){
			bits[k].used = 0;
		}
		/*
		for(j = 0; j < n; j++){
			for(k = 0; k < p; k++){
				printf("%d ", matrix[j][k]);
			}
			printf("\n");
		}
		*/
		
		min = 15;
		brute_force(n, matrix, &min, bits, p, 0, 0);
		printf("%d\n", min);
	}
	return 0;
}