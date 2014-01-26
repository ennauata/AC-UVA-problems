//
//  prob299.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 12/28/13.
//  Copyright (c) 2013 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>

int main(){
	int t, i, j, n, aux, count, k;
	int sequence[100];
	scanf("%d", &t);
	for(i = 0; i < t; i++){
		scanf("%d", &n);
		for(j = 0; j < n; j++){
			scanf("%d", &sequence[j]);
		}
		/*
		for(j = 0; j < n; j++){
			printf("%d ", sequence[j]);
		}
		printf("\n");
		*/
		count = 0;
		for(j = 0; j < n; j++){
			for(k = j; k < n; k++){
				if(sequence[j] > sequence[k]){
					aux = sequence[j];
					sequence[j] = sequence[k];
					sequence[k] = aux;
					count++;
				}
			}
		}
		printf("Optimal train swapping takes %d swaps.\n", count);
	}
	return 0;
}