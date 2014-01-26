//
//  prob457.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 11/27/13.
//  Copyright (c) 2013 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>

int main(){
	int dishes[40], aux[40];
	int DNA[10];
	int t, i, j, n, k, sum;
	scanf("%d\n", &t);
		for(i = 0; i < t; i++){
			for(j = 0; j < 10; j++){
				scanf("%d", &n);
				DNA[j] = n;
			}
			for(j = 0; j < 40; j++){
				dishes[j] = 0;
			}
			dishes[19] = 1;
			for(j = 0; j < 50; j++){
				for(k = 0; k < 40; k++){
					if(dishes[k] == 0){
						printf(" ");
					}
					else if(dishes[k] == 1){
						printf(".");
					}
					else if(dishes[k] == 2){
						printf("x");
					}
					else{
						printf("W");
					}
				}
				for(k = 0; k < 40; k++){
					if(k == 0){
						sum = dishes[k+1] + dishes[k];
						aux[k] = DNA[sum];
					}
					else if(k == 39){
						sum = dishes[k-1] + dishes[k];
						aux[k] = DNA[sum];
					}
					else{
						sum = dishes[k-1] + dishes[k] + dishes[k+1];
						aux[k] = DNA[sum];
					}
				}
				for(k = 0; k < 40; k++)
					dishes[k] = aux[k];
					
				printf("\n");
			}
			if(i != t-1)
				printf("\n");
		}
	return 0;
}
