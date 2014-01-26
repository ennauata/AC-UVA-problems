//
//  prob10346.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 1/7/14.
//  Copyright (c) 2014 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>

int main(){
	int n, k, count;
	while(scanf("%d %d\n", &n, &k) != EOF){
		count = n;
		while(n >= k){
			count += n/k;
			n = n%k + n/k;
			//printf("%d\n", n);
		}	
		printf("%d\n", count);
	}
	return 0;
}