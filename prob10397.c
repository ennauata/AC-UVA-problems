//
//  prob10397.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 3/19/14.
//  Copyright (c) 2014 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define MAX 1000

typedef int (*compfn)(const void*, const void*);

typedef struct node{
	double x, y;
} node;

typedef struct edge{
	int v1, v2;
	double val;
} edge;

double map[MAX][MAX]; 
int n;

int compare(edge *elem1, edge *elem2)
{
   if ( elem1->val < elem2->val)
      return -1;

   else if (elem1->val > elem2->val)
      return 1;

   else
      return 0;
}

int idx[MAX*MAX];
int flag;
int union_find(int a, int b) {
    if (idx[a] != a && idx[b] != b) {
        idx[a] = union_find(idx[a], idx[b]);
    } 
	else if (idx[a] != a) {
        idx[a] = union_find(idx[a], b);
    } 
	else if (idx[b] != b){
        idx[a] = union_find(a, idx[b]);
    } 
	else {
		if (a == b) {
            flag = 1;
        } 
		else {
            idx[b] = idx[a];
        }
    }
    return idx[a];
}

int main(){
	int m, i, j, k, l, q;
	double dist, sum;
	node pos[MAX];
	edge *edges;
	edges = (edge *)malloc(MAX*MAX*sizeof(edge));
	while(scanf("%d", &n) != EOF){
		for(i = 0; i < n; i++){
			scanf("%lf %lf", &pos[i].x, &pos[i].y);
		}
		for(i = 0; i < n; i++){
			for(j = 0; j < n; j++){
				map[i][j] = -1;
			}
		}
		scanf("%d", &m);
		for(i = 0; i < n; i++){
			idx[i] = i;
		}
		for(j = 0; j < m; j++){
			scanf("%d %d", &k, &l);
			k--;
			l--;
			dist = sqrt(pow(pos[k].x - pos[l].x, 2) + pow(pos[k].y - pos[l].y, 2));
			map[k][l] = dist;
			map[l][k] = dist;
			union_find(k, l);
		}
		k = 0;
		for(i = 0; i < n; i++){
			for(j = i+1; j < n; j++){
				if(map[i][j] < 0){
					dist = sqrt(pow(pos[i].x - pos[j].x, 2) + pow(pos[i].y - pos[j].y, 2));
					edges[k].v1 = i;
					edges[k].v2 = j; 
					edges[k++].val = dist;
				}
			}
		}
		qsort((void *) edges, k, sizeof(edge), (compfn)compare);
		sum = 0;
		for(i = 0; i < k; i++){
			q = edges[i].v1;
			l = edges[i].v2;
			flag = 0;
			union_find(l, q);
			if(!flag){
				map[q][l] = edges[i].val;
				map[l][q] = edges[i].val;
				sum += map[q][l];
			}
		}
		printf("%.2lf\n", sum);
	}
	return 0;
}