//
//  prob108.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 1/4/14.
//  Copyright (c) 2014 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>

int main(){
	int i, j, n, max, max_so_far;
	int matrix[110][110], buffer[110], inf, sup;
	scanf("%d", &n);
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			scanf("%d", &matrix[i][j]);
		}
	}
	/*
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
	*/
	inf = 0;
	sup = 0;
	max = matrix[0][0];
	while(sup - inf != n){
		//printf("inf = %d sup = %d\n", inf, sup);
		// Zera buffer
		for(i = 0; i < n; i++){
			buffer[i] = 0;
		}
		for(j = 0; j < n; j++){
			for(i = inf; i <= sup; i++){
				buffer[j] += matrix[i][j];
			}
		}
		/*
		for(i = 0; i < n; i++){
			printf("%d ", buffer[i]);
		}
		printf("\n");
		*/
		// Search for max sequence in each line
		max_so_far = buffer[0];
		for(j = 1; j < n; j++){
			if(max_so_far < 0){
				max_so_far = buffer[j];
			}
			else{
				max_so_far += buffer[j];
			}
			if(max_so_far > max){
				max = max_so_far;
			}
		}
		//printf("%d %d %d\n", max, begin, end);
		sup++;
		inf++;
		if(sup == n){
			sup = sup - inf + 1;
			inf = 0;
		}
	}

	printf("%d\n", max);
	return 0;
}