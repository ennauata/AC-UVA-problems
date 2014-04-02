//
//  prob10302.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 2/1/14.
//  Copyright (c) 2014 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>

int main(){
	long int n;
	while(scanf("%ld", &n) != EOF){
		printf("%ld\n", n * n * (n + 1) * (n + 1) /4 );
	}
	return 0;
}