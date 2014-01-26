//
//  prob1098.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 1/11/14.
//  Copyright (c) 2014 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int m, n, r1, c1, r2, c2, r3, c3, step, mark[8][8], count, mark_bfs[8][8], found1, found2, found3, found4;

void check(int i, int j){
	if(i == 0 && j == 1){
		found1 = 1;
	}
	if(i == r1 && j == c1){
		found2 = 1;
	}
	if(i == r2 && j == c2){
		found3 = 1;
	}
	if(i == r3 && j == c3){
		found4 = 1;
	}
	mark_bfs[i][j] = 1;
	// Up
	if(i+1 < m && mark_bfs[i+1][j] == 0){
		check(i+1, j);
	}
	// Down
	if(i-1 >= 0 && mark_bfs[i-1][j] == 0){
		check(i-1, j);
	}
	// Right
	if(j+1 < n && mark_bfs[i][j+1] == 0){
		check(i, j+1);
	}
	// Left
	if(j-1 >= 0 && mark_bfs[i][j-1] == 0){
		check(i, j-1);
	}
}

void bruteForce(int i, int j, int step){
	int k, l;
	// Count
	if(step == n*m && i == 0 && j == 1){
		count++;
		return;
	}
	// Prunning	
	// Didn't reach the checkpoints on time
	if(step == n*m/4 && (i != r1 || j != c1)){
		return;
	}
	if(step == n*m/2 && (i != r2 || j != c2)){
		return;
	}
	if(step == 3*n*m/4 && (i != r3 || j != c3)){
		return;
	}
	if(step == n*m && (i != 0 || j != 1)){
		return;
	}
	
	// Reached checkpoints before time
	if(step != n*m/4 && i == r1 && j == c1){
		return;
	}
	if(step != n*m/2 && i == r2 && j == c2){
		return;
	}
	if(step != 3*n*m/4 && i == r3 && j == c3){
		return;
	}
	if(step != n*m && i == 0 && j == 1){
		return;
	}
	
	// Not possible to reach
	if(step < n*m/4 && abs(i-r1) + abs(j-c1) > n*m/4 -step){
		return;
	}	
	if(step < n*m/2 && abs(i-r2) + abs(j-c2) > n*m/2 -step){
		return;
	}
	if(step< 3*n*m/4 && abs(i-r3) + abs(j-c3) > 3*n*m/4 -step){
		return;
	}
	if(abs(i-0) + abs(j-1) > n*m -step){
		return;
	}

	// Repeat
	if(mark[i][j] == 0 && i < m && j < n && i >= 0 && j >= 0){
		// Check if possible (bfs)
		found1 = found2 = found3 = found4 = 0;
		for(k = 0; k < m; k++){
			for(l = 0; l < n; l++){
				mark_bfs[k][l] = mark[k][l];
			}
		}
		check(i, j);
		//printf("%d %d %d %d\n", found1, found2, found3, found4);
		if(((step >= n*m/4) || found2) && ((step >= n*m/2) || found3) && ((step >= 3*n*m/4) || found4) && found1){
			mark[i][j] = 1;
			/*
			printf("%d %d\n\n", i, j);
			for(k = 0; k < m; k++){
				for(l = 0; l < n; l++){
				 	printf("%d ", mark[k][l]);
				}
				printf("\n");
			}
			printf("\n");
			*/
			// Up
			bruteForce(i+1, j, step+1);
			// Left
			if(step != n*m-1 && i == 0 && j == 2){
				mark[i][j] = 0;
				return;
			}
			else{
				bruteForce(i, j-1, step+1);
			}
			// Right
			if(step != n*m-1 && i == 0 && j == 0){
				mark[i][j] = 0;
				return;
			}
			else{
				bruteForce(i, j+1, step+1);
			}
			// Down
			if(step != n*m-1 && i == 1 && j == 1){
				mark[i][j] = 0;
				return;
			}
			else{
				bruteForce(i-1, j, step+1);
			}
			mark[i][j] = 0;
		}
	}
	return;
}


int main(){	
	int i, j, t = 1;
	scanf("%d %d", &m, &n);
	while(m && n){
		//printf("%d %d\n", m, n);
		scanf("%d %d %d %d %d %d", &r1, &c1, &r2, &c2, &r3, &c3);
		//printf("%d %d %d %d %d %d\n", r1, c1, r2, c2, r3, c3);
		for(i = 0; i < m; i++){
			for(j = 0; j < n; j++){
				mark[i][j] = 0;
			}
		}
		count = 0;
		mark[0][0] = 1;
		bruteForce(1, 0, 2);
		printf("Case %d: %d\n", t++, count);
		scanf("%d %d", &m, &n);
	}
	return 0;
}