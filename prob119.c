//
//  prob119.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 2/16/14.
//  Copyright (c) 2014 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>
#include <string.h>

typedef struct node{
	int value;
	char name[20];
} node;

char buffer[15];

void readName(){
	char c;
	int size;
	size = 0;
	while(scanf("%c", &c) != EOF){
		if(c >= 'a' && c <= 'z'){
			buffer[size++] = c;
		}
		else{
			break;
		}
	}
	buffer[size] = '\0';
}

int main(){
	int i, j, n, k, val, l, f;
	node people[15];
	f = scanf("%d\n", &n);
	while(f != EOF){
		for(i = 0; i < n; i++){
			readName();
			strcpy(people[i].name, buffer);
			people[i].value = 0;
		}
		for(l = 0; l  < n; l++){
			scanf("%s %d %d ", buffer, &val, &k);
			for(i = 0; i < n; i++){
				if(!strcmp(buffer, people[i].name) && k){
					people[i].value -= val - val%k;
					break;
				}
			}
			for(i = 0; i < k; i++){
				readName();
				for(j = 0; j < n; j++){
					if(!strcmp(buffer, people[j].name)){
						people[j].value += val/k;
						break;
					}
				}
			}	
		}
		for(i = 0; i < n; i++){
			printf("%s %d\n", people[i].name, people[i].value);
		}
		f = scanf("%d\n", &n);
		if(f != EOF){
			printf("\n");
		}
	}
	return 0;	
}