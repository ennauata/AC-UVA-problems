//
//  prob10300.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 11/25/13.
//  Copyright (c) 2013 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>

int main(){
	int n, i, j, f, size, animals, fl, sum;
	scanf("%d", &n);
	for(i = 0; i < n; i++){
		sum = 0;
		scanf("%d", &f);
		for(j = 0; j < f; j++){
			scanf("%d %d %d", &size, &animals, &fl);
			sum += size*fl;
		}
		printf("%d\n", sum);
	}	
	return 0;
}