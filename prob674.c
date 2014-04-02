//
//  prob674.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 2/1/14.
//  Copyright (c) 2014 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>

int main(){
	int n, i, j, coins[5] = {1, 5, 10, 25, 50}, sum[6][7490];
	for(i = 0; i <= 5; i++){
		for(j = 0; j < 7490; j++){
			if(i == 0 || j == 0){
				sum[i][j] = 1;
			}
			else{
				sum[i][j] = 0;
			}
		}
	}
	for(i = 1; i <= 5; i++){
		for(j = 1; j < 7490; j++){
			if(j - coins[i] < 0){
				sum[i][j] = sum[i-1][j];
			}
			else{
				sum[i][j] = sum[i-1][j] + sum[i][j-coins[i]];
			}
		}
	}
	while(scanf("%d", &n) != EOF){
		printf("%d\n", sum[5][n]);
	}
	return 0;
}