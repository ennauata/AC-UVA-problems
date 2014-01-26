//
//  prob369.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 1/10/14.
//  Copyright (c) 2014 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>
#define LIM 100

void gen_triangle(unsigned long long int triangle[110][110]){
	int i, j;
	for(i = 0; i <= LIM; i++){
		triangle[i][0] = 1;
		triangle[0][i] = 1;
	}
	for(i = 1; i <= LIM; i++){
		for(j = 1; j <= LIM-i; j++){
			triangle[i][j] = triangle[i][j-1] + triangle[i-1][j];
		}
	}
	/*
	for(i = 0; i <= LIM; i++){
		for(j = 0; j <= LIM-i; j++){
			printf("%lld   ", triangle[i][j]);
		}
		printf("\n");
	}
	*/
}	

int main(){
	unsigned long long int triangle[110][110];
	int n, m;
	gen_triangle(triangle);
	scanf("%d %d", &n, &m);
	while(n && m){
		printf("%d things taken %d at a time is %llu exactly.\n", n, m, triangle[n-m][m]);
		scanf("%d %d", &n, &m);
	}
	return 0;
}