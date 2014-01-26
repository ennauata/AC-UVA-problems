//
//  prob10010.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 12/21/13.
//  Copyright (c) 2013 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>
#include <string.h>

void search(char word[100], char matrix[50][50], int row, int col, int m, int n, int *res1, int *res2, int *found, int *stop){
	int i, j, diff;
	diff = 0;

	// East
	i = 0;
	while((col + i < n) && (word[i] == matrix[row][col+i]))
		i++;
	if(i == strlen(word))
		*found = 1;
		
	// West
	i = 0;
	while((col - i >= 0) && (word[i] == matrix[row][col-i]))
		i++;
	if(i == strlen(word))
		*found = 1;
		
	// North
	i = 0;
	while((row + i < m) && (word[i] == matrix[row + i][col]))
		i++;
	if(i == strlen(word))
		*found = 1;
		
	// South
	i = 0;
	while((row - i >= 0) && (word[i] == matrix[row - i][col]))
		i++;
	if(i == strlen(word))
		*found = 1;
		
	// North-East
	i = 0;
	j = 0;
	while((row - i >= 0) && (col + j < n) && (word[i] == matrix[row - i][col + j])){
		i++;
		j++;
	}
	if(i == strlen(word))
		*found = 1;
		
	// North-West
	i = 0;
	j = 0;
	while((row - i >= 0) && (col - j >= 0) && (word[i] == matrix[row - i][col - j])){
		i++;
		j++;
	}
	if(i == strlen(word))
		*found = 1;
		
	// South-East
	i = 0;
	j = 0;
	while((row + i < m) && (col + j < n) && (word[i] == matrix[row + i][col + j])){
		i++;
		j++;
	}
	if(i == strlen(word))
		*found = 1;

	// South-West
	i = 0;
	j = 0;
	while((row + i < m) && (col - j >= 0) && (word[i] == matrix[row + i][col - j])){
		i++;
		j++;
	}
	if(i == strlen(word))
		*found = 1;
	
	if(!(*stop)){
		if(*found){
			*res1 = row;
			*res2 = col;
			*stop = 1;
			//printf("ROW = %d COL = %d\n", row, col);
		}
		else{
			if(col + 1 < n){
				search(word, matrix, row, col + 1, m, n, res1, res2, found, stop);
			}
			else if(row + 1 < m){
				search(word, matrix, row + 1, 0, m, n, res1, res2, found, stop);
			}
		}
	}
}

int main(){
	int t, m, n, i, l, j, k, res1, res2, found, stop;
	char matrix[50][50], word[100], c;
	scanf("%d\n", &t);
	for(i = 0; i < t; i++){
		scanf("%d %d\n", &m, &n);
		for(j = 0; j < m; j++){
			for(l = 0; l < n; l++){
				scanf("%c", &c);
				if(c <= 'Z'){
					c += 32;
				}
				matrix[j][l] = c;
			}
			scanf("\n");
		}
		/*for(j = 0; j < m; j++){
			for(l = 0; l < n; l++){
				printf("%c ", matrix[j][l]);
			}
			printf("\n");
		}*/
		scanf("%d", &k);
		for(j = 0; j < k; j++){
			scanf("%s", word);
			for(l = 0; l < strlen(word); l++){
				if(word[l] <= 'Z'){
					word[l] += 32;
				}
			}
			/*
			for(l = 0; l < strlen(word); l++){
				printf("%c ", word[l]);
			}
			printf("\n");
			*/
			found = 0;
			stop = 0;
			search(word, matrix, 0, 0, m, n, &res1, &res2, &found, &stop);
			printf("%d %d\n", res1 + 1, res2 + 1);
		}
		if(i != t - 1){
			printf("\n");
		}
	}
	return 0;
}