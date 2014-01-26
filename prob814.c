//
//  prob813.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 11/14/13.
//  Copyright (c) 2013 Nelson Isao Nauata Junior. All rights reserved.
//

// Complexity O(n)
#include <stdio.h>
#include <math.h>

int max(int x, int y){
	if(x > y)
		return x;
	else 
		return y;
}
int min(int x, int y){
	if(x < y)
		return x;
	else 
		return y;
}

int main(){
	int i, n, x, y, u, v, x_int, y_int, u_int, v_int, exist, l=0;
	
	scanf("%d", &n);
	
	while(n){
		l++;
		x_int = -1000000;
		y_int = 1000000;
		u_int = 1000000;
		v_int = -1000000;
		exist = 1;
		for (i = 0; i < n; i++) {
			scanf("%d %d %d %d", &x, &y, &u, &v);
			if((x <= u_int) && (y >= v_int) && (u >= x_int) && (v <= y_int)){
				x_int = max(x, x_int);
				y_int = min(y, y_int);
				u_int = min(u, u_int);
				v_int = max(v, v_int);
			}
			else{
				exist = 0;
			}
		}
		printf("Teste %d\n", l);
		if(!exist){
			printf("nenhum\n");
		}
		else{
			printf("%d %d %d %d\n", x_int, y_int, u_int, v_int);
		}
		scanf("%d", &n);
		if(n){
			printf("\n");
		}	
	}
}