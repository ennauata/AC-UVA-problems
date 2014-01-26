//
//  prob488.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 11/26/13.
//  Copyright (c) 2013 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>

int main(){
	int t, i, a, f, j, k, increasing, l, flag;
	scanf("%d\n", &t);
	for(i = 0; i < t; i++){
		scanf("\n%d\n%d", &a, &f);
		increasing = 1;
		k = 0;
		j = 0;
		flag = 0;
		if(a != 0){
			while(j != f){
				if(increasing){
					for(l = 0; l < k; l++)
						printf("%d", k);
					k++;
				}
				else{
					for(l = 0; l < k; l++)
						printf("%d", k);
					k--;
				}
				if(k == 0){
					increasing = !increasing;
					j++;
				}
				else if(k == a){
					increasing = !increasing;
				}
				if(flag){
					printf("\n");
				}
				flag = 1;
			}
		}
		if(i != t-1)
			printf("\n");
	}
	return 0;
}

