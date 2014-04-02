//
//  prog568.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 2/2/14.
//  Copyright (c) 2014 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#define MAX 10001

int main(){
	int i, vec[MAX], res, d, n;
	vec[0] = 1;
	for(i = 1; i < MAX; i++){
		res = vec[i-1]*i;
		d = res%10;
		while(!d){
			res /= 10;
			d = res%10;
		}
		vec[i] = res%100000;
	}
	while(scanf("%d", &n) != EOF){
		printf("%5d -> %d\n", n, vec[n]%10);
	}
	return 0;
}