//
//  prob499.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 1/15/14.
//  Copyright (c) 2014 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#define MAX 26

typedef struct node{
	int amount;
	char value;
} node;

typedef int (*compfn)(const void*, const void*);

int compare(struct node *elem1, struct node *elem2)
{
   if ( elem1->amount < elem2->amount)
      return -1;

   else if (elem1->amount > elem2->amount)
      return 1;

   else{
	if(elem1->value > elem2->value){
		return 1;
	}
	else if(elem1->value < elem2->value){
		return -1;
	}
	else{
		return 0;
	}
   }
}


int main(){
	node upper[MAX];
	node lower[MAX];
	char c;
	int i, max;
	
	for(i = 0; i < MAX; i++){
		upper[i].amount = 0;
		lower[i].amount = 0;
		upper[i].value = i + 'A';
		lower[i].value = i + 'a';
	}
	while(scanf("%c", &c) != EOF){
		if(c >= 'A' && c <= 'Z'){
			upper[c - 'A'].amount++;
		}
		else if(c >= 'a' && c <= 'z'){
			lower[c - 'a'].amount++;
		}
		else if(c == '\n'){
			qsort((void *) &upper, MAX, sizeof(struct node), (compfn)compare );
			qsort((void *) &lower, MAX, sizeof(struct node), (compfn)compare );
			if(upper[MAX - 1].amount > lower[MAX - 1].amount){
				max = upper[MAX-1].amount;
			}
			else{
				max = lower[MAX-1].amount;
			}
			for(i = 0; i < MAX; i++){
				if(upper[i].amount == max){
					printf("%c", upper[i].value);
				}
			}
			for(i = 0; i < MAX; i++){
				if(lower[i].amount == max){
					printf("%c", lower[i].value);
				}
			}
			for(i = 0; i < MAX; i++){
				upper[i].amount = 0;
				lower[i].amount = 0;
				upper[i].value = i + 'A';
				lower[i].value = i + 'a';
			}
			printf(" %d\n", max);
		}
	}
	return 0;
}