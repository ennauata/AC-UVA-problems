//
//  prob10012.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 4/7/14.
//  Copyright (c) 2014 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#define N 999999
#define MAX 9999999
#define ABS(X) ((X) < 0 ? -(X) : (X))

int n, m;
int mark[N];
int buffer[N];
double c[N];
double r[N];
double min;

double max(double a, double b){
	if(a > b){
		return a;
	}
	else{
		return b;
	}
}	

double getDist(double r1, double r2){
	return sqrt(pow(r1 + r2, 2) - pow(ABS(r1 - r2), 2));
}

void bf(int recLev){
	int i, j;
	double max_dist, dist;
	for(i = 0; i < m; i++){
		if(!mark[i]){
			mark[i] = 1;
			buffer[recLev] = i;
			bf(recLev+1);
			mark[i] = 0;
		}
	}
	if(recLev == m){
		c[0] = r[buffer[0]];
		for(i = 1; i < m; i++){
			max_dist = 0;
			for(j = 0; j < i; j++){
				dist = getDist(r[buffer[i]], r[buffer[j]]);
				if(dist+c[j] > max_dist){
					max_dist = dist+c[j];
				}
			}
			c[i] = max(max_dist, r[buffer[i]]);
		}
		for(i = 0; i < m; i++){
			if(c[i]+r[buffer[i]] > max_dist){
				max_dist = c[i]+r[buffer[i]];
			}
		}
		if(max_dist < min){
			min = max_dist;
		}ax
	}
}

int main(){
	int i, j;
	scanf("%d", &n);
	for(i = 0; i < n; i++){
		scanf("%d", &m);
		for(j = 0; j < m; j++){
			scanf("%lf", &r[j]);
			mark[j] = 0;
		}
		if(m > 1){
			min = MAX;
			bf(0);	
			printf("%.3lf\n", min);
		}
		else{
			printf("%.3lf\n", 2*r[0]);
		}
	}
	return 0;
}