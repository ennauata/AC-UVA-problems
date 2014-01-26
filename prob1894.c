//
//  prob1894.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 11/22/13.
//  Copyright (c) 2013 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int main(){
	int n, c, v, i, total, sum;
	int *varetas;
	scanf("%d", &n);
	while(n){
		varetas = malloc(n*sizeof(int));
		for(i = 0; i < n; i++){
			scanf("%d %d", &c, &v);
			varetas[i] = v;
		}
		total = 0;
		sum = 0;
		for(i = 0; i < n; i++){
			total += varetas[i]/4;
			varetas[i] %= 4;
			sum += varetas[i]/2;
			varetas[i] %= 2;
		}
		total += sum/2;
		printf("%d\n", total);
		free(varetas);
		scanf("%d", &n);
	}
}