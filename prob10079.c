//
//  prob10079.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 1/7/14.
//  Copyright (c) 2014 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>

int main(){
	int n, i, div;
	long long int res;
	scanf("%d", &n);
	while(n >= 0){
		res = 1;
		div = 1;
		for(i = 1; i <= n; i++){
			res = res + i;
		}
		printf("%lld\n", res);
		scanf("%d", &n);
	}
	return 0;
}