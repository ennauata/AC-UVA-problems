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

int main(){
	int n, i;
	double numb, avg, vec[MAX], error, sum1, sum2, ref;
	scanf("%d", &n);
	while(n){
		avg = 0;
		for(i = 0; i < n; i++){
			scanf("%lf", &numb);
			vec[i] = numb;
			avg += numb;
		}
		error = avg/n - round((avg/n)*100)/100;
		avg = round((avg/n)*100)/100;
		sum1 = 0; 
		sum2 = 0;
		for(i = 0; i < n; i++){
			if(vec[i] - avg > 0){
				sum1 += vec[i] - avg;
			}
			else{
				sum2 += avg - vec[i];
			}
		}
		avg /= n;
		ref = 0;
		for(i = 0; i < n; i++){
			if(vec[i] - avg > 0){
				ref += vec[i] - avg;
			}
		}
		while(sum2 <= sum1){
			
			sum2 += 0.01;
		}
		printf("$%lf %f\n", sum1, sum2);
		scanf("%d", &n);
	}
	return 0;
}