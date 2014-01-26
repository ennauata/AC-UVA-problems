//
//  prob694.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 11/27/13.
//  Copyright (c) 2013 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>

int main(){
	long long int a, l, aux; 
	int count, t;
	t = 1;
	scanf("%lld %lld", &a, &l);
	while(a > 0){
		count = 0;
		aux = a;
		while(1){
			count++;
			if(a == 1)
				break;
			else if(a > l){
				count--;
				break;
			}
			if(a%2){
				a = 3*a + 1;	
			}
			else{
				a /= 2;
			}
		}
		printf("Case %d: A = %lld, limit = %lld, number of terms = %d\n", t++, aux, l, count);
		scanf("%lld %lld", &a, &l);
	}
	return 0;
}