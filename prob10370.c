//
//  prob10370.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 1/2/14.
//  Copyright (c) 2014 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>
#define MAX 99999

int main(){
	int i, t, n, j, grades[MAX];
	double average, sum, res;
	scanf("%d", &t);
	for(i = 0; i < t; i++){
		scanf("%d", &n);
		for(j = 0; j < n; j++){
			scanf("%d", &grades[j]);
		}
		sum = 0;
		for(j = 0; j < n; j++){
			sum += grades[j];
		}
		average = sum/n;
		sum = 0;
		for(j = 0; j < n; j++){
			if(grades[j] > average){
				sum++;
			}
		}
		res = 100*sum/n;
		printf("%.3f%%\n", res);
	}
	return 0;
}