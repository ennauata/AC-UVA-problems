//
//  prob10469.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 1/26/14.
//  Copyright (c) 2014 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>

int main(){
	unsigned int a, b;
	while(scanf("%d %d", &a, &b) != EOF){
		printf("%d\n", a^b);
	}
	return 0;
}