//
//  prob10055.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 11/24/13.
//  Copyright (c) 2013 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>

int main(){
	long long int n1, n2, diff;
	while(scanf("%lld %lld", &n1, &n2) != EOF){
		if(n1>n2){
			diff = n1 - n2;
		}
		else{
			diff = n2 - n1;
		}
		printf("%lld\n", diff);
	}
	return 0;
}