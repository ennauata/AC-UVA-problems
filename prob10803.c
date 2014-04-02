//
//  prob10803.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 3/18/14.
//  Copyright (c) 2014 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define MAX 200

typedef struct coord{
	double x, y;
} coord;

int main(){
	int l, i, j, k, t, n;
	double dist[MAX][MAX], aux, max;
	coord nodes[MAX];
	scanf("%d", &t);
	for(l = 1; l <= t; l++){
		scanf("%d", &n);
		for(i = 0; i < n; i++){
			scanf("%lf %lf", &nodes[i].x, &nodes[i].y);
		}
		for(i = 0; i < n; i++){
			for(j = 0; j < n; j++){
				if(i == j){
					dist[i][j] = 0;
				}
				else{ 
					aux = sqrt(pow(nodes[i].x - nodes[j].x, 2) + pow(nodes[i].y - nodes[j].y, 2));
					if(aux > 10){
						dist[i][j] = INFINITY;
					}
					else{
						dist[i][j] = aux;
					}
				}
			}
		}
		for(k = 0; k < n; k++){
			for(i = 0; i < n; i++){
				for(j = 0; j < n; j++){
					if(dist[i][j] > dist[i][k] + dist[k][j]){
						dist[i][j] = dist[i][k] + dist[k][j];
					}
				}
			}
		}
		max = -1;
		for(i = 0; i < n; i++){
			for(j = 0; j < n; j++){
				if(dist[i][j] > max){
					max = dist[i][j];
				}
			}
		}
		printf("Case #%d:\n", l);
		if(max < INFINITY){
			printf("%.4lf\n\n", max);
		}
		else{
			printf("Send Kurdy\n\n");
		}
	}
	return 0;
}