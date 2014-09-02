//
//  prob10127.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 4/10/14.
//  Copyright (c) 2014 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>

int main(){
	long long int n, i, count;
	while(scanf("%lld", &n) != EOF){
		i = 1;
		count = 1;
		while(i%n){
			i %= n;
			i = i*10+1;
			count++;
		}
		printf("%lld\n", count);
	}
	return 0;
}