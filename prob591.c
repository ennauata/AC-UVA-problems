//
//  prob591.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 1/2/14.
//  Copyright (c) 2014 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>
#define MAX 100

int main(){
	int n, i, stacks[MAX], max, res, t = 1;
	scanf("%d", &n);
	while(n){
		max = 0;
		for(i = 0; i < n; i++){
			scanf("%d", &stacks[i]);
			max += stacks[i];
		}
		max /= n;
		res = 0;
		for(i = 0; i < n; i++){
			if(max < stacks[i]){
				res += stacks[i] - max;
			}
		}
		printf("Set #%d\n", t++);
		printf("The minimum number of moves is %d.\n\n", res);
		scanf("%d", &n);
	}
	return 0;
}