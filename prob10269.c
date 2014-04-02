//
//  prob10269.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 3/13/14.
//  Copyright (c) 2014 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>
#define MAX 99999

int main(){
	int t, i, k, x, y, num, a, b, m, l, p;
	int map[MAX][MAX];
	scanf("%d", &t);
	for(p = 0; p < t; p++){
		scanf("%d %d %d %d %d", &a, &b, &m, &l, &k);
		for(i = 0; i < m; i++){
			scanf("%d %d %d", &x, &y, &num);
			map[x][y] = num;
		}		
	}
	return 0;
}