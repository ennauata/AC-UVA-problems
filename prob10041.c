//
//  prob10041.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 1/5/14.
//  Copyright (c) 2014 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 99999

int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int main(){
	int n, i, r, j, numb[MAX], med, min;
	scanf("%d", &n);
	for(i = 0; i < n; i++){
		scanf("%d", &r);
		for(j = 0; j < r; j++){
			scanf("%d", &numb[j]);
		}
		qsort(numb, r, sizeof(int), cmpfunc);
		/*for(j = 0; j < r; j++){
			printf("%d ", numb[j]);
		}*/
		//printf("\n");
		if(r%2 != 0){
			med = numb[r/2]; 	
		}
		else{
			med = (numb[(r/2)-1] + numb[r/2])/2;
		}
		min = 0;
		//printf("%d\n", med);
		for(j = 0; j < r; j++){
			min += abs(med - numb[j]);
		}
		printf("%d\n", min);
	}
	return 0;
}