//
//  prob10970.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 1/26/14.
//  Copyright (c) 2014 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>

int count;
int main(){
	int m, n;
	while(scanf("%d %d", &m, &n) != EOF){
		count = 0;
		printf("%d\n", m*n - 1);
	}
	return 0;
}