//
//  prob12614.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 1/21/14.
//  Copyright (c) 2014 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>

int n, max, numb;

int main(){
	int t, i, j;
	scanf("%d", &t);
	for(i = 0; i < t; i++){
		max = -1;
		scanf("%d", &n);
		for(j = 0; j < n; j++){	
			scanf("%d", &numb);
			if(numb > max){
				max = numb;
			}
		}
		printf("Case %d: %d\n", i+1, max);
	}
	return 0;
}