//
//  prob10369.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 3/11/14.
//  Copyright (c) 2014 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define MAX 99999
#define INF 99999

typedef struct node{
	float x, y;
	int visited;
} node;
int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}
int main(){
	node unf[MAX];
	node n;
	int t, i, j, k, s, p, min_j, size, flag, tam;
	float x, y, min, d, res[MAX];
	scanf("%d", &t);
	for(k = 0; k < t; k++){
		scanf("%d %d", &s, &p);
		for(i = 0; i < p; i++){
			scanf("%f %f", &x, &y);
			n.x = x;
			n.y = y;
			n.visited = 0;
			unf[i] = n;
		}
		unf[0].visited = 1;
		size = p-1;
		tam = 0;
		while(size){
			min = INF;
			flag = 0;
			for(i = 0; i < p; i++){
				if(unf[i].visited == 1){
					for(j = 0; j < p; j++){
						if(unf[j].visited == 0){
							d = sqrt(pow((unf[j].x-unf[i].x), 2)+pow((unf[j].y-unf[i].y), 2));
							if(d < min){
								min = d;
								min_j = j;
								flag = 1;
							}
						}
					}
				}
			}
			if(flag){
				res[tam++] = min;
			}
			unf[min_j].visited = 1;
			size--;
		}
		qsort (res, tam, sizeof(int), compare);
		printf("%.2f\n", res[tam-s]);
	}
	return 0;
}