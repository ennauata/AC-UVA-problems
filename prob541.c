//
//  prob541.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 1/17/14.
//  Copyright (c) 2014 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>

int main(){
	int n, map[100][100], sum_r, sum_c, cols[100], rows[100], count_c, count_r, k, l, i, j;
	scanf("%d", &n);
	while(n){
		for(i = 0; i < n; i++){
			for(j = 0; j < n; j++){
				scanf("%d", &map[i][j]);
			}
		}
		count_c = 0;
		count_r = 0;
		for(i = 0; i < n; i++){
			sum_r = 0;
			sum_c = 0;
			for(j = 0; j < n; j++){
				sum_r += map[i][j];
				sum_c += map[j][i];
			}
			rows[i] = sum_r;
			cols[i] = sum_c;
			if(sum_r%2 == 1){
				count_r++;
				k = i;
			}
			if(sum_c%2 == 1){
				count_c++;
				l = i;
			}
			if(count_c > 1 || count_r > 1){
				break;
			}
		}
		if(count_c > 1 || count_r > 1){
			printf("Corrupt\n");
		}
		else if(count_c == 0 && count_r == 0){
			printf("OK\n");
		}
		else{
			printf("Change bit (%d,%d)\n", k+1, l+1);
		}
		scanf("%d", &n);
	}
	return 0;
}