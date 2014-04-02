//
//  prob539.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 3/31/14.
//  Copyright (c) 2014 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>
#define N 50


int max;
int visited[N][N];
int nodes[N];
int graph[N][N];
int n, m;
void backTracking(int k, int lev){
	int j;
	if(lev > max){
		max = lev;
	}
	for(j = 0; j < n; j++){
		if(!visited[k][j] && graph[k][j]){
			visited[k][j] = visited[j][k] = 1;
			nodes[k] = 1;
			backTracking(j, lev+1);
			visited[k][j] = visited[j][k] = 0;
		}
	}
}

int main(){
	int x, y, i, j;
	scanf("%d%d", &n, &m);
	while(n != 0 && m != 0){
		for(i = 0; i < n; i++){
			for(j = 0; j < n; j++){
				graph[i][j] = 0;
				visited[i][j] = 0;
			}
		}	
		for(i = 0; i < m; i++){
			scanf("%d%d", &x, &y);
			graph[x][y] = graph[y][x] = 1;
		}
		max = 0;
		for(i = 0; i < n; i++){
			backTracking(i, 0);
		}
		printf("%d\n", max);
		scanf("%d%d", &n, &m);
	}
	return 0;
}