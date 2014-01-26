//
//  prob102.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 12/25/13.
//  Copyright (c) 2013 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>
#define MAX 9999999999

typedef struct node{
	int used;
	char value;
} node;

void permute(long long int bgc[3][3], char path[3], node vec[3], int recLev, int res[3], long long int *total){
	int i, lower;
	long long int sum_b, sum_c, sum_g;
	for(i = 0; i < 3; i++){
		if(!vec[i].used){
			path[recLev] = vec[i].value;
			vec[i].used = 1;
			permute(bgc, path, vec, recLev + 1, res, total);
			vec[i].used = 0;
		}
	}
	for(i = 0; i < 3; i++){
		if(path[i] == 'B'){
			sum_b = bgc[(i+1)%3][0] + bgc[(i+2)%3][0];
 		}
		else if(path[i] == 'G'){
			sum_c = bgc[(i+1)%3][1] + bgc[(i+2)%3][1];
		}
		else{
			sum_g = bgc[(i+1)%3][2] + bgc[(i+2)%3][2];
		}
	}
	if(sum_b + sum_c + sum_g < *total){
		*total = sum_b + sum_c + sum_g;
		for(i = 0; i < 3; i++){
			res[i] = path[i];
		}
	}
	else if(sum_b + sum_c + sum_g == *total){
		lower = 0;
		for(i = 0; i < 3; i++){
			if(path[i] > res[i]){
				break;
			}
			else if(path[i] < res[i]){
				lower = 1;
				break;
			}
		}
		if(lower){
			for(i = 0; i < 3; i++){
				res[i] = path[i];
			}
		}
	}
}

int main(){
	int i, j, k;
	int res[3];
	long long int total, bgc[3][3];
	char path[3];
	node vec[3];
	
	while(1){
		for(i = 0; i < 3; i++){
			for(j = 0; j < 3; j++){
				k = scanf("%lld", &bgc[i][j]);
			}
		}
		if(k == EOF){
			break;
		}
		vec[0].value = 'B';
		vec[0].used = 0;
		vec[1].value = 'G';
		vec[1].used = 0;
		vec[2].value = 'C';
		vec[2].used = 0;
		/*
		for(i = 0; i < 3; i++){
			for(j = 0; j < 3; j++){
				printf("%d ", bcg[i][j]);
			}
			printf("\n");
		}
		*/
		total = MAX;
		permute(bgc, path, vec, 0, res, &total);
		for(i = 0; i < 3; i++){
			printf("%c", res[i]);
		}
		printf(" %lld\n", total);
	}
}