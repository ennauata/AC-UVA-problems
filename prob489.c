//
//  prob489.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 11/26/13.
//  Copyright (c) 2013 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 999999

int cmpfunc (const void * a, const void * b)
{
   return ( *(char*)a - *(char*)b );
}

int push(char *s, char value, int *top){
	s[++(*top)] = value;
	return 0;
}

int found(char *s, char value, int top){
	int i;
	for(i = 0; i <= top; i++){
		if(s[i] == value)
			return 1;
	}
	return 0;
}

int main(){
	int round, i, word_size, guesses_size, fail, score, j, end, begin, finish, top, flag, flag2;
	char word[1000], guesses[1000], stack[MAX];
	char prev;
	scanf("%d\n", &round);
	while(round != -1){
		scanf("%s\n", word);
		scanf("%s\n", guesses);
		
		word_size = (int)strlen(word);
		guesses_size = (int)strlen(guesses);
		
		qsort(word, word_size, sizeof(char), cmpfunc);
		
		begin = 0;
		end = 0;
		prev = '*';
		while(end < word_size){
			if(word[end] != prev){
				word[begin] = word[end];
				prev = word[end];
				end++;
				begin++;
			}
			else{
				end++;
			}
		}
		word[begin] = '\0';
		word_size = begin;
		//printf("%s\n", word);
		//printf("%s\n", guesses);
		score = 0;
		fail = 0;
		top = -1;
		flag2 = 1;
		for(i = 0; i < guesses_size; i++){
			if(!found(stack, guesses[i], top)){
				flag = 1;
				for(j = 0; j < word_size; j++){
					if(word[j] == guesses[i]){
						score++;
						flag = 0;
					}
					//printf("TOP = %d\n", top);
					//printf("SCORE = %d\n", score);
				}
				push(stack, guesses[i], &top);
				if(flag){	
					fail++;
				}
			}				
			if(score == word_size || fail == 7)
				break;
		}
		//printf("%s\n", word);
		//printf("%s\n", guesses);
		//printf("%d\n\n", fail);
		printf("Round %d\n", round);
		if(fail == 7){
			printf("You lose.\n");
		}
		else if(score == word_size){
			printf("You win.\n");
		}
		else{
			printf("You chickened out.\n");
		}
		scanf("%d\n", &round);
		
	}
	return 0;
}