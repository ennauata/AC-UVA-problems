//
//  prob10167.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 12/18/13.
//  Copyright (c) 2013 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>

int main(){
	int i, n, j, k, line, half_a, half_b, stop;
	int matrix[100][2];
	scanf("%d", &n);
	while(n){
		for(i = 0; i < 2*n; i++){
			scanf("%d %d\n", &matrix[i][0], &matrix[i][1]);
		}
		stop = 0;
		for(i = -500; i <= 500; i++){
			for(j = -500; j <= 500; j++){
				half_a = 0;
				half_b = 0;
				for(k = 0; k < 2*n; k++){
					//printf("%d %d\n", matrix[k][0], matrix[k][1]);
					line = i*matrix[k][0] + j*matrix[k][1];
					if(line > 0){
						half_a++;
					}
					else if(line < 0){
						half_b++;
					}
				}
				if(half_a == n && half_b == n){
					printf("%d %d\n", i, j);
					//printf("%d %d\n", half_a, half_b);
					stop = 1;
					break;
				}
			}
			if(stop){
				break;
			}
		}
		scanf("%d", &n);
	}
	return 0;
}