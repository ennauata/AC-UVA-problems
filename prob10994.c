//
//  prob10994.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 3/17/14.
//  Copyright (c) 2014 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>
#define MAX 2147483647

int main(){
	int i;
	long int p, q, sum, n_p, n_q, first;
	scanf("%ld %ld", &p, &q);
	while(p >= 0 && q >= 0){
		sum = 0;
		first = 0;
		while(q){
			n_p = p/10;
			n_q = q/10;
			//printf("%d %d\n", n_p, n_q);
			sum += (n_q-n_p)*45;
			for(i = 1; i <= q%10; i++)
				sum += i; 
			for(i = 1; i < p%10; i++)
				sum -= i;
			if(first){
				sum -= p%10;
			}
			if(p%10 > 0){
				first = 1;
			}
			p = n_p;
			q = n_q;
		}
		printf("%ld\n", sum);
		scanf("%ld %ld", &p, &q);
	}
	return 0;
}