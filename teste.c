//
//  teste.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 4/12/14.
//  Copyright (c) 2014 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>
#define SEED 30
#define N 10
#define b 
#define m 10

int main(){
	int a[100], i;
	a[0] = SEED;
	for(i = 0; i <= N; i++)
		a[i] = (a[i-1]*b+1)%m;
	for(i = 0; i <= N; i++)
		printf("%d ", a[i]);
	printf("\n");
}