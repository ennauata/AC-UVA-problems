//
//  prob810.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 11/17/13.
//  Copyright (c) 2013 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int main(){
	int n, i, k, numb, end, begin, max, min, sum, average, l = 0;
	int *sequence;
	scanf("%d %d", &n, &k);
	while(n){
		l++;
		sequence = malloc(n*sizeof(int));
		for(i = 0; i < n; i++){
			scanf("%d", &numb);
			sequence[i] = numb;
		}
		end = 0;
		begin = 0;
		sum = 0;
		for(i = 0; i < k; i++){
			sum += sequence[end++];
		}
		max = sum/k;
		min = sum/k;
		for(i = k; i < n; i++){
			sum += sequence[end];
			sum -= sequence[begin];
			average = sum/k;
			if(average > max){
				max = average;
			}
			if(average < min){
				min = average;
			}
			end++;
			begin++;
		}
		printf("Teste %d\n", l);
		printf("%d %d\n", min, max);
		scanf("%d %d", &n, &k);
		if(n){
			printf("\n");
		}
		free(sequence);
	}
	return 0;
}