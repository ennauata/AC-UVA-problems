//
//  prob3830.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 11/17/13.
//  Copyright (c) 2013 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>

int main(){
	int n, i, numb, sum;
	scanf("%d", &n);
	sum = 0;
	for(i = 0; i < n; i++){
		scanf("%d", &numb);
		sum += numb;
	}
	printf("%d\n", sum);
	return 0;
}