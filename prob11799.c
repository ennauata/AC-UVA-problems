//
//  prob11799.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 4/12/14.
//  Copyright (c) 2014 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>

int main(){
	int t, n, max, val, k;
	scanf("%d", &t);
	k = t;
	while(t--){
		scanf("%d", &n);
		max = -1;
		while(n--){
			scanf("%d", &val);
			if(val > max){
				max = val;
			}
		}
		printf("Case %d: %d\n", k-t, max);
	}
	return 0;
}