//
//  prob10340.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 1/12/14.
//  Copyright (c) 2014 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#define MAX 2000000

char word1[MAX], word2[MAX];
int main(){
	int stop, pos, j, i;
	while(scanf("%s %s", word1, word2) != EOF){
		//printf("%s\n %s\n", word1, word2);
		pos = 0;
		for(i = 0; i < strlen(word1); i++){
			stop = 1;
			for(j = pos; j < strlen(word2); j++){
				if(word1[i] == word2[j]){
					pos = j+1;
					stop = 0;
					break;
				}
			}
			if(stop){
				break;
			}
		}
		if(stop){
			printf("No\n");
		}
		else{
			printf("Yes\n");
		}
	}
	return 0;
}