//
//  prob10034.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 4/2/14.
//  Copyright (c) 2014 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#define N 101

typedef struct coord{
	double x, y;
	int visited;
} coord;

double calc_dist(coord a, coord b){
	return sqrt(pow(a.x-b.x, 2)+pow(a.y-b.y, 2));
}

int main(){
	int t, n, i, min_idx, current, j;
	double x, y, min, dist, total;
	coord freckles[N];
	int visited[N], size;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(i = 0; i < n; i++){
			scanf("%lf%lf", &x, &y);
			freckles[i].x = x;
			freckles[i].y = y;
			freckles[i].visited = 0;
		}
		size = 0;
		visited[size++] = 0;
		freckles[0].visited = 1;
		total = 0;
		while(size < n){
			min = 9999999.;
			for(i = 0; i < size; i++){
				current = visited[i];
				for(j = 0; j < n; j++){
					if(!freckles[j].visited){
						dist = calc_dist(freckles[current], freckles[j]);
						if(dist < min){
							min = dist;
							min_idx = j;
						}
					}
				}
			}
			visited[size++] = min_idx;
			freckles[min_idx].visited = 1;
			total += min;
		}
		printf("%.2lf\n", total);
		if(t != 0){
			printf("\n");
		}
	}
	return 0;
}