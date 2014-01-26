//
//  prob490.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 11/25/13.
//  Copyright (c) 2013 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>

int main(){
	char buffer[1000][1000] = {'\0'};
	char c;
	int i = 0, j = 0, row, col = -1, count, k;
	while(scanf("%c", &c) != EOF){
		if(c == '\n'){
			buffer[i][j] = '\n';
			i++;
			j = 0;
		}
		else{
			if(j > col){
				col = j;
			}
			buffer[i][j++] = c;
		}
	}
	count = 0;
	row = i - 1;
	for(j = 0; j <= col; j++){
		for(i = row; i >= 0; i--){
			if(buffer[i][j] == '\n' || buffer[i][j] == ' ' || buffer[i][j] == '\0'){
				count++;
			}
			else{
				for(k = 0; k < count; k++){
					printf(" ");
				}
				printf("%c", buffer[i][j]);
				count = 0;
			}
		}
		for(k = 0; k < count-1; k++){
			printf(" ");
		}
		printf("\n");
		count = 0;
	}
	
	/*
	for(i = 0; i < row; i++){
		for(j = 0; j <= col+1; j++){
			printf("%c ", buffer[i][j]);
		}
		printf("\n");
	}
	*/
	return 0;
}