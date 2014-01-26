//
//  prob10783.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 12/30/13.
//  Copyright (c) 2013 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>

int main(){
	int t, i, j, a, b, sum;
	scanf("%d\n", &t);
	for(i = 0; i < t; i++){
		scanf("%d\n%d\n", &a, &b);
		sum = 0;
		for(j = a; j <= b; j++){
			if(j%2){
				sum += j;
			}
		}
		printf("Case %d: %d\n", i+1, sum);
	}
	return 0;
}