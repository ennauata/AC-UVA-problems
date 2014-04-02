//
//  prob11764.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 2/24/14.
//  Copyright (c) 2014 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>

int main(){
	int t, i, n, j, low, high, curr, prev;
	scanf("%d", &t);
	for(i = 0; i < t; i++){
		low = 0;
		high = 0;
		scanf("%d", &n);
		scanf("%d", &prev);
		for(j = 0; j < n-1; j++){
			scanf("%d", &curr);
			if(prev > curr){
				low++;
			}
			else if(prev < curr){
				high++;
			}
			prev = curr;
		}
		printf("Case %d: %d %d\n", i+1, high, low);
	}
	return 0;
}