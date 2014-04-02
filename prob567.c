//
//  prob567.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 3/7/14.
//  Copyright (c) 2014 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>
#define MAX 9999
#define INFINITY 99999

int m_adj[MAX][MAX];
int size, pos;

void floyd_warshall(){
	int i, j, k;
	for(k = 1; k <= 20; k++){
		for(i = 1; i <= 20; i++){
			for(j = 1; j <= 20; j++){
				if(m_adj[i][k] != 0 && m_adj[k][j] != 0 && m_adj[i][j] != 0){
					if(m_adj[i][j] > m_adj[i][k] + m_adj[k][j]){
						m_adj[i][j] = m_adj[i][k] + m_adj[k][j];
					}
				}
			}
		}
	}
}

int main(){
	int i, j, n, x, y, k, t = 1;
	while(1){
		for(i = 1; i <= 20; i++){
			for(j = 1; j <= 20; j++){
				m_adj[i][j] = INFINITY;
			}
		}
		for(i = 1; i <= 20; i++){
			m_adj[i][i] = 0;
		}
		for(i = 1; i <= 19; i++){
			k = scanf("%d", &size);
			if(k == EOF){
				break;
			}
			for(j = 1; j <= size; j++){
				scanf("%d", &pos);
				m_adj[i][pos] = 1;
				m_adj[pos][i] = 1;
			}
		}
		if(k == EOF){
			break;
		}
		floyd_warshall();
		printf("Test Set #%d\n", t++);
		scanf("%d", &n);
		for(i = 1; i <= n; i++){
			scanf("%d %d", &x, &y);
			printf("%2d to %2d:%2d\n", x, y, m_adj[x][y]);
		}
		printf("\n");
	}
	return 0;
}