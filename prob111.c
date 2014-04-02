//
//  prob111.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 2/10/14.
//  Copyright (c) 2014 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>
#define MAX 100

int max(int a, int b){
	if(a > b){
		return a;
	}
	else{
		return b;
	}
}

int main(){
	int map[MAX][MAX], n, num, x[MAX], y[MAX], k, l, i;
	scanf("%d", &n);
	for(i = 1; i <= n; i++){
		scanf("%d", &num);
		x[num] = i;
	}
	//for(k = 0; k < n; k++){
	//	printf("%d ", x[k]);
	//}
	//printf("\n");
	i = 1;
	while(scanf("%d", &num) != EOF){
		y[num] = i++;
		if(i > n){
			for(k = 0; k <= n; k++){
				map[k][0] = 0;
				map[0][k] = 0;
			}
			for(k = 1; k <= n; k++){
				for(l = 1; l <= n; l++){
					if(x[k] == y[l]){
						map[k][l] = map[k-1][l-1] + 1;
					}
					else{
						map[k][l] = max(map[k-1][l], map[k][l-1]);
					}
				}
			}
			printf("%d\n", map[n][n]);
			i = 1;
			//for(k = 0; k < n; k++){
			//	printf("%d ", y[k]);
			//}
			//printf("\n");
		}
	}
	return 0;
}
