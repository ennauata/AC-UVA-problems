//
//  prob100.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 11/30/13.
//  Copyright (c) 2013 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>

int main(){
	long long int n, i, j, max, count, a, b;
	while(scanf("%lld %lld", &a, &b) != EOF){
		max = 1;
		if(a > b){
			j = a;
			i = b;
		}
		else{
			i = a;
			j = b;
		}
		while(i <= j){
			count = 0;
			n = i;
			while(1){
				count++;
				if(n == 1)
					break;
				if(n%2){
					n = 3*n +1;
				}
				else{
					n /= 2;
				}
			}
			
			if(count > max){
				max = count;
			}
			i++;
		}
		printf("%lld %lld %lld\n", a, b, max);
	}
	return 0;
}