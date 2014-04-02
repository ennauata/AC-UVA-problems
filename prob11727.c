//
//  prob11727.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 1/26/14.
//  Copyright (c) 2014 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>

int main(){
	int t, i, a, b, max, c, res, min;
	scanf("%d", &t);
	for(i = 0 ; i < t; i++){
		scanf("%d %d %d", &a, &b, &c);
		if(a > b){
			max = a;
			min = b;
		}
		else{
			max = b;
			min = a;
		}
		if(c > max){
			max = c;
		}
		if(c < min){
			min = c;
		}
		printf("Case %d: %d\n", i+1, (a+b+c)-(max+min));
	}
	return 0;
}