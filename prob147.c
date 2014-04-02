//
//  prob147.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 2/24/14.
//  Copyright (c) 2014 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>

int main(){
	long int coins[11] = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000}, sum[12][30001];
	int i, j, k;
	double n;
	for(i = 0; i <= 11; i++){
		for(j = 0; j < 30001; j++){
			if(j == 0 || i == 0){
				sum[i][j] = 1;
			}
			else{
				sum[i][j] = 0;
			}
		}
	}
	for(i = 1; i <= 11; i++){
		for(j = 1; j < 30001; j++){
			if(j - coins[i] < 0){
				sum[i][j] = sum[i-1][j];
			}
			else{
				sum[i][j] = sum[i-1][j] + sum[i][j-coins[i]];
			}
		}
	}
	while(scanf("%lf", &n)){
		if(n){
			k = 100*n + 0.005;
			//printf("k = %d\n", k);
			if(k%5 != 0){
				printf("%6.2f%17d\n", n, 0);
			}
			else{
				printf("%6.2f%17ld\n", n, sum[11][k]);
			}
		}
		else{
			break;
		}
	}
	return 0;
}