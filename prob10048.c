//
//  prob10048.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 4/3/14.
//  Copyright (c) 2014 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>
#define N 200
#define MAX 999999

int max(int a, int b){
	if(a > b)
		return a;
	else
		return b;
}

int min(int a, int b){
	if(a < b)
		return a;
	else
		return b;
}

int main(){
	int s, q, c, x, y, val, i, j, k, t = 1;
	int map[N][N];
	scanf("%d%d%d", &c, &s, &q);
	while(s||q||c){
		printf("Case #%d\n", t++);
		for(i = 0; i < c; i++){
			for(j = 0; j < c; j++){
				map[i][j] = MAX;
			}
		}
		for(i = 0; i < s; i++){
			scanf("%d%d%d", &x, &y, &val);
			map[x-1][y-1] = val;
			map[y-1][x-1] = val;
		}
		for(k = 0; k < c; k++){
			for(i = 0; i < c; i++){
				for(j = 0; j < c; j++){
					map[i][j] = min(map[i][j], max(map[i][k], map[k][j]));
				}
			}
		}
		for(i = 0; i < q; i++){
			scanf("%d%d", &x, &y);
			if(map[x-1][y-1] == MAX){
				printf("no path\n");
			}
			else{
				printf("%d\n", map[x-1][y-1]);
			}
		}
		scanf("%d%d%d", &c, &s, &q);
		if(c&&s&&q){
			printf("\n");
		}
	}
	return 0;
}