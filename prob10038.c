//
//  prob10038.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 12/25/13.
//  Copyright (c) 2013 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int main(){
	int n, i, prev, curr, diff, first, next_diff, jolly;
	int mark[3001];
	while(scanf("%d", &n) != EOF){
		for(i = 1; i < n; i++){
			mark[i] = 0;
		}
		scanf("%d", &prev);
		for(i = 0; i < n-1; i++){
			scanf("%d", &curr);
			diff = abs(curr - prev);
			mark[diff] = 1;
			prev = curr;
		}
		jolly = 1;
		for(i = 1; i < n; i++){
			if(mark[i] != 1){
				jolly = 0;
			}
		}
		if(jolly){
			printf("Jolly\n");
		}
		else{
			printf("Not jolly\n");
		}
	}
	return 0;
}