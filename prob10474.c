//
//  prob10474.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 12/9/13.
//  Copyright (c) 2013 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>
#define MAX 10001

int main(){
	int n, q, i, j, pos, que, sum, t = 1;
	int marbles[MAX];
	scanf("%d %d", &n, &q);
	while(n && q){
		printf("CASE# %d:\n", t);
		for(i = 0; i < MAX; i++){
			marbles[i] = 0;
		}
		for(i = 0; i < n; i++){
			scanf("%d", &pos);
			marbles[pos]++;
		}
		for(j = 0; j < q; j++){
			scanf("%d", &que);
			sum = 1;
			for(i = 0; i < MAX; i++){
				if(marbles[i]){
					if(i == que){
						printf("%d found at %d\n", que, sum);
						break;
					}
				}
				else{
					if(i == que){
						printf("%d not found\n", que);
						break;
					}
				}
				sum += marbles[i];
			}
		}
		t++;
		scanf("%d %d", &n, &q);
	}
}