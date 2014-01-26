//
//  prob10905.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 12/15/13.
//  Copyright (c) 2013 Nelson Isao Nauata Junior. All rights reserved.
//

#define MAX 99999
#include <stdio.h>
typedef struct node{
	int value;
	int used;
} node;

void push(int *stack, int *top, int value){
	stack[++(*top)] = value;
}

int pop(int *stack, int *top){
	return stack[(*top)--];
}

long long int side(long long int a, int b){
	int stack[MAX], top;
	top = -1;
	while(b){
		push(stack, &top, b%10);
		b /= 10;
	}
	while(top != -1){
		a = a*10 + pop(stack, &top);
	}
	return a;
}


void brute_force(node *vec, long long int *max, int n, int *path, int recLev){
	int i;
	long long int acc;
	for(i = 0; i < n; i++){
		if(!vec[i].used){
			vec[i].used = 1;
			path[recLev] = vec[i].value;
			brute_force(vec, max, n, path, recLev + 1);
			vec[i].used = 0;
		}
	}
	acc = 0;
	for(i = 0; i <= recLev; i++){
		acc = side(acc, path[i]);
	}
	printf("%lld\n", acc);
	if(acc > *max){
		*max = acc;
	}
}
int main(){
	int n, i, num, path[MAX];
	long long int max;
	node vec[MAX], nd;
	scanf("%d\n", &n);
	while(n){
		for(i = 0; i < n; i++){
			scanf("%d", &num);
			nd.value = num;
			nd.used = 0;
			vec[i] = nd;
		}
		max = -1;
		brute_force(vec, &max, n, path, 0);
		printf("ANSWER : %lld\n", max);
		scanf("%d\n", &n);
	}
	return 0;
}