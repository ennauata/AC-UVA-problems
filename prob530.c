//
//  prob471. .c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 4/10/14.
//  Copyright (c) 2014 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){
	int i;
	double n, k;
	double sum;
	scanf("%lf%lf", &n, &k);
	while(n || k){
		if(k > n/2){
			k = n - k;
		}
		sum = 1;
		for(i = 1; i <= k; i++, n--){
			sum *= n/i;
		}
		printf("%.0lf\n", sum);
		scanf("%lf%lf", &n, &k);
	}
}