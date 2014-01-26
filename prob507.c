//
//  prob507.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 1/1/14.
//  Copyright (c) 2014 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>
#define MAX 99999

int main(){
	int t, j, r, i, begin, end, max, c_max, c_begin;
	int stops[MAX];
	scanf("%d", &t);
	for(i = 0; i < t; i++){
		scanf("%d", &r);
		for(j = 0; j < r-1; j++){
			scanf("%d", &stops[j]);
		}
		c_begin = 0;
		c_max = stops[0];
		max = stops[0];
		begin = 0;
		end = 0;
		for(j = 1; j < r-1; j++){
			if(c_max < 0){
				c_max = stops[j];
				c_begin = j;
			}
			else{
				c_max += stops[j];
			}
			if(c_max > max){
				max = c_max;
				begin = c_begin;
				end = j;
			}
			else if(c_max == max && (j-c_begin > end-begin)){
				max = c_max;
				begin = c_begin;
				end = j;	
			}
		}
		if(max <= 0){
			printf("Route %d has no nice parts\n", i+1);
		}
		else{
			printf("The nicest part of route %d is between stops %d and %d\n", i+1, begin+1, end+2);
		}
	}
	return 0;
}