//
//  prob12696.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 1/21/14.
//  Copyright (c) 2014 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>

int main(){
	int t, i, count;
	float l, w, d, kg;
	scanf("%d", &t);
	count = 0;
	for(i = 0; i < t; i++){
		scanf("%f %f %f %f", &l, &w, &d, &kg);
		if((l <= 56 && w <= 45 && d <= 25 && kg <= 7)||(l + w + d <= 125 && kg <= 7)){
			printf("1\n");
			count++;
		}
		else{
			printf("0\n");
		}
	}	
	printf("%d\n", count);
	return 0;	
}