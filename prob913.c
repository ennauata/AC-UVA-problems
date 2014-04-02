//
//  prob913.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 2/19/14.
//  Copyright (c) 2014 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>
#include <math.h>

int main(){
	unsigned long long int res, sum, n;
	while(scanf("%llu", &n) != EOF){
		sum = ((n-1)/2)*((n-1)/2);
		res = 3*(2*(sum+n)-3);
		printf("%llu\n", res); 
	}
	return 0;
}