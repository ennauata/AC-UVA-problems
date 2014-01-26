//
//  prob816.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 11/17/13.
//  Copyright (c) 2013 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int knapsack(int *values, int *bits, int sup, int total){
	int possible, value;	
	// Base
	if(sup){
		if(total){
			return 0;
		}
		else{
			return 1;
		}
	}
	// Induction
	
	possible = knapsack(values, bits, sup-1, total);
	if(!possible){
		value = values[sup];
		if(total - value < 0){
			return 0;
		}
		else{
			possible = knapsack(values, bits, sup-1, total-value);
			if(possible){
				total += value;
				bits[sup] = 1;
				return 1;	
			}
			else{
				return 0;
			}
		}
	}
	else{
		return 1;
	}
}

int main(){
	int n, i, x, y, k, numb, l = 0, total, test;
	int *values, *bits;
	scanf("%d %d %d", &x, &y, &n);
	while(n){
		l++;
		values = malloc(n*sizeof(int));
		bits = malloc(n*sizeof(int));
		for(i = 0; i < n; i++){
			scanf("%d", &numb);
			values[i] = numb;
			bits[i] = 0;
		}
		test = knapsack(values, bits, n, 10);
		for(i = 0; i < n; i++){
			printf("%d ", bits[i]);
		}
		printf("Teste %d\n", l);
		printf("%d\n", test);
		scanf("%d %d %d", &x, &y, &n);
		if(n){
			printf("\n");
		}
		free(values);
		free(bits);
	}
	return 0;
}