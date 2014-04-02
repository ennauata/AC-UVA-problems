//
//  prob624.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 3/4/14.
//  Copyright (c) 2014 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>
#define MAX 9999

int main(){
	int w, i, t, c[25], m[25][MAX], j;
	int track[25][MAX][2];
	int buffer[25], k;
	while(scanf("%d %d", &w, &t) != EOF){
		for(i = 1; i <= t; i++){
			scanf("%d", &c[i]);
		}
		for(i = 0; i <= t; i++){
			for(j = 0; j <= w; j++){
				track[i][j][0] = -1;
				track[i][j][1] = -1;
				if(!i || !j){
					m[i][j] = 0;
				}
			}
		}
		for(i = 1; i <= t; i++){
			for(j = 1; j <= w; j++){
				if(c[i] <= j){
					if(m[i-1][j] > m[i-1][j-c[i]] + c[i]){
						m[i][j] = m[i-1][j];
						track[i][j][0] = j;
						track[i][j][1] = 0;
					}
					else{
						m[i][j] = m[i-1][j-c[i]] + c[i];
						track[i][j][0] = j-c[i];
						track[i][j][1] = 1;
					}
				}
				else{
					m[i][j] = m[i-1][j];
					track[i][j][0] = j;
					track[i][j][1] = 0;
				}
			}
		}
		i = t;
		j = w;
		k = 0;
		while(j && i){
			//printf("CURR: %d\n", track[i][j][0]);
			if(track[i][j][1]){
				buffer[k++] = c[i];
			}
			j = track[i][j][0];
			i--;
		}
		for(i = k-1; i >= 0; i--){
			printf("%d ", buffer[i]);
		}
		printf("sum:%d\n", m[t][w]);
		/*
		for(i = 0; i <= t; i++){
			for(j = 0; j <= w; j++){
				printf("%d ", m[i][j]);
			}
			printf("\n");
		}
		for(i = 0; i <= t; i++){
			for(j = 0; j <= w; j++){
				printf("%d ", track[i][j][0]);
			}
			printf("\n");
		}
		for(i = 0; i <= t; i++){
			for(j = 0; j <= w; j++){
				printf("%d ", track[i][j][1]);
			}
			printf("\n");
		}
		*/
	}
	return 0;
}