//
//  prob10107.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 1/11/14.
//  Copyright (c) 2014 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>
#define MAX	99999

int main(){
	int numbs[MAX], size, aux, i, n, pos, j;
	size = 0;
	while(scanf("%d", &n) != EOF){
		if(size > 1){
			for(j = 0; j < size; j++){
				if(n < numbs[j]){
					break;
				}
			}
			for(i = size-1; i >= j; i--){
				numbs[i+1] = numbs[i];
			}
			numbs[j] = n;
		}
		else{
			numbs[size] = n; 
		}
		size++;
		/*
		for(i = 0; i < size; i++){
			printf("%d ", numbs[i]);
		}
		printf("\n");
		*/
		if(size%2 == 0){
			printf("%d\n", (int)((numbs[size/2-1]+numbs[size/2])/2));
		}
		else{
			printf("%d\n", numbs[size/2]);
		}
	}
}