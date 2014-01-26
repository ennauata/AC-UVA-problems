//
//  prob639.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 12/11/13.
//  Copyright (c) 2013 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>

int validate(char matrix[4][4], int n){
	int i, j, k, count_l, count_c, flag1, flag2, total;
	total = 0;
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			if(matrix[i][j] != 'X'){
				count_l = 0;
				count_c = 0;
				flag1 = 1;
				flag2 = 1;
				for(k = 0; k < n; k++){
					if(matrix[i][k] == 'X'){
						count_c = 0;
					}
					else if(matrix[i][k] == 'O'){
						count_c++;
					}
					if(matrix[k][j] == 'X'){
						count_l = 0;
					}
					else if(matrix[k][j] == 'O'){
						count_l++;
					}
					if(count_c == 2){
						flag1 = 0;
					}
					if(count_l == 2){
						flag2 = 0;
					}
				}
				if(flag1 && flag2){
					total++;
				}
				else{
					return -1;
				}
			}
		}
	}
	return total;
}

void brute_force(char matrix[4][4], int *max, int n, int total, char res[4][4]){
	int i, j, k, count_l, count_c, flag1, flag2;
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			if(matrix[i][j] != 'X' && matrix[i][j] != 'O'){
				matrix[i][j] = 'O';
				count_l = 0;
				count_c = 0;
				flag1 = 1;
				flag2 = 1;
				for(k = 0; k < n; k++){
					if(matrix[i][k] == 'X'){
						count_c = 0;
					}
					else if(matrix[i][k] == 'O'){
						count_c++;
					}
					if(matrix[k][j] == 'X'){
						count_l = 0;
					}
					else if(matrix[k][j] == 'O'){
						count_l++;
					}
					if(count_c == 2){
						flag1 = 0;
					}
					if(count_l == 2){
						flag2 = 0;
					}
				}
				if(flag1 && flag2){
					brute_force(matrix, max, n, total+1, res);
				}
				matrix[i][j] = '.';
			}
		}
	}
	if(total > *max){
		*max = total;
		/*
		for(i = 0; i < n; i++){
			for(j = 0; j < n; j++){
				res[i][j] = matrix[i][j];
			}
		}
		*/
	}
}

int main(){
	char c;
	char matrix[4][4], res[4][4];
	int i, j, n, max;
	
	scanf("%d\n", &n);
	while(n){
		for(i = 0; i < n; i++){
			for(j = 0; j < n; j++){
				scanf("%c", &c);
				matrix[i][j] = c;
			}
			scanf("\n");
		}
		max = -1;
		brute_force(matrix, &max, n, 0, res);
		/*for(i = 0; i < n; i++){
			for(j = 0; j < n; j++){
				printf("%c", res[i][j]);
			}
			printf("\n");
		}
		*/
		printf("%d\n", max);
		scanf("%d\n", &n);
	}
	return 0;
}