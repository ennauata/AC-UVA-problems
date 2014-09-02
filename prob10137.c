//
//  prob10137.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 1/28/14.
//  Copyright (c) 2014 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#define MAX 99999 

double max(double a, double b){
	if(a > b){
		return a;
	}
	else{
		return b;
	}
}

int main(){
	int n, i;
	double vec[MAX], rem, sum, res1, res2, avg;
	double numb;
	scanf("%d", &n);
	while(n){
		sum = 0;
		for(i = 0; i < n; i++){
			scanf("%lf", &numb);
			vec[i] = numb*100;
			sum += vec[i];
		}
		avg = sum/n;
		rem = (int)(sum)%n;
		res1 = 0;
		res2 = 0;
		for(i = 0; i < n; i++){
			// Giving
			if(vec[i]-avg>=0){
				res1 += vec[i]-ceil(avg);
			}
			// Receiving
			else{
				res2 += floor(avg)-vec[i];
			}
		}
		printf("$%.2lf\n", max(res1, res2)/100);
		scanf("%d", &n);
	}
	return 0;
}