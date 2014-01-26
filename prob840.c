//
//  prob813.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 11/14/13.
//  Copyright (c) 2013 Nelson Isao Nauata Junior. All rights reserved.
//

// Complexity O(n)
#include <stdio.h>


int main(){
	int n, l=0, j, z, sum, dif, i;
	
	scanf("%d", &n);
	printf("\n");
	while(n){
		l++;
		sum = 0;
		printf("Teste %d\n", l);
		for(i = 0; i < n; i++){
			scanf("%d %d", &j, &z);
			dif = j - z;
			sum += dif;
			printf("%d\n", sum);
		}
		scanf("%d", &n);
		printf("\n");
	}
}