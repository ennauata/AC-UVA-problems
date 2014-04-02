//
//  prob10003.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 2/3/14.
//  Copyright (c) 2014 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#define MAX 9999

int res, numbs[MAX], n, total, sum, memo[MAX][MAX];

int rec_func(int inf, int sup, int k, int l){
	int i, temp, min = 0;
	if(k < l){
		min = total;
		for(i = k; i <= l; i++){
			temp = 0;
			if(memo[k][i] == -1){
				printf("%d %d\n", k, l);
				temp += rec_func(inf, numbs[i], k, i);
			}
			else{
				temp += memo[k][i];
			}
			if(memo[i+1][l] == -1){
				temp += rec_func(numbs[i+1], sup, i+1, l);
			}
			else{
				temp += memo[i+1][l];
			}
			if(temp < min){
				min = temp;
			}
		}
		memo[k][l] = sup - inf + min;
	}
	else{
		memo[k][l] = 0;
	}
	return min;
}


int main(){
	int i, j;
	scanf("%d", &total);
	while(total){
		scanf("%d", &n);
		for(i = 1; i <= n; i++){
			scanf("%d", &numbs[i]);
		}
		numbs[0] = 0;
		numbs[n+1] = total;
		sum = 0;
		for(i = 0; i <= n; i++){
			for(j = 0; j <= n; j++){
				memo[i][j] = -1;
			}
		}
		rec_func(0, total, 0, n+1);
		printf("%d\n", sum);
		scanf("%d", &total);
	}
	return 0;
}