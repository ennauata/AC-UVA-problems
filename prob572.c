//
//  prob572.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 1/27/14.
//  Copyright (c) 2014 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>

int mark[110][110], n, m, count;
char map[110][110];

void dfs(int i, int j){
	int k, l;
	for(k = i-1; k <= i+1; k++){
		if(k >= 0 && k < n){
			for(l = j-1; l <= j+1; l++){
				if(l >= 0 && l < m && map[k][l] == '@' && !mark[k][l]){
					mark[k][l] = 1;
					dfs(k, l);
				}
			}
		}
	}
}

int main(){
	int i, j;
	scanf("%d %d", &n, &m);
	while(n && m){
		for(i = 0; i < n; i++){
			scanf("%s", map[i]);
			for(j = 0; j < m; j++){
				mark[i][j] = 0;
			}
		}
		count = 0;
		for(i = 0; i < n; i++){
			for(j = 0; j < m; j++){
				if(!mark[i][j] && map[i][j] == '@'){
					mark[i][j] = 1;
					count++;
					dfs(i, j);
				}
			}
		}
		printf("%d\n", count);
		scanf("%d %d", &n, &m);
	}
	return 0;
}