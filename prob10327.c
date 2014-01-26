//
//  prob10327.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 1/19/14.
//  Copyright (c) 2014 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>
#define MAX 20000

int main(){
	int n, i, numb[MAX], stop, count, aux, j;
	while(scanf("%d", &n) != EOF){
		for(i = 0; i < n; i++){
			scanf("%d", &numb[i]);
		}
		count = 0;
		for(i = 0; i < n; i++){
			stop = 1;
			for(j = 1; j < n - i; j++){
				if(numb[j-1] > numb[j]){
					aux = numb[j];
					numb[j] = numb[j-1];
					numb[j-1] = aux;
					stop = 0;
					count++;
				}
			}
			if(stop){
				break;
			}
		}
		/*for(i = 0 ; i < n; i++){
			printf("%d ", numb[i]);
		}
		printf("\n");*/
		printf("Minimum exchange operations : %d\n", count);
	}
	return 0;
}