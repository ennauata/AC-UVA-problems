//
//  prog10405.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 1/17/14.
//  Copyright (c) 2014 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#define MAX 1200

int max(int a, int b){
	if(a > b){
		return a;
	}
	else{
		return b;
	}
}

int main(){
	int i, j, map[MAX][MAX];
	char string1[MAX], string2[MAX];
	while(gets(string1)){
		gets(string2);
		for(i = 0; i <= strlen(string1); i++){
			map[i][0] = 0;
		}
		for(j = 0; j <= strlen(string2); j++){
			map[0][j] = 0;
		}
		for(i = 1; i <= strlen(string1); i++){
			for(j = 1; j <= strlen(string2); j++){
				if(string1[i-1] == string2[j-1]){
					map[i][j] = map[i-1][j-1] + 1;
				}
				else{
					map[i][j] = max(map[i-1][j], map[i][j-1]);
				}
			}
		}/*
		for(i = 0; i <= strlen(string1); i++){
			for(j = 0; j <= strlen(string2); j++){
				printf("%d ", map[i][j]);
			}
			printf("\n");
		}
		*/
		printf("%d\n", map[strlen(string1)][strlen(string2)]);
		//printf("%s\n%s\n", string1, string2);
	}
	return 0;
}