//
//  prob105.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 4/9/14.
//  Copyright (c) 2014 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>
#define N 20000

typedef struct coord{
	int h, l, r;
} coord;

coord vec[N], n;;
int size;
int max[2*N];

int main(){
	int h, l, r, i, j, sup, prev;
	size = 0;
	sup = 0;
	while(scanf("%d %d %d", &l, &h, &r) != EOF){
		n.l = l;
		n.h = h;
		n.r = r;
		vec[size++] = n;
		if(n.r > sup){
			sup = n.r;
		}
	}
	for(i = vec[0].l; i <= sup; i++){
		max[i] = -1;
	}
	for(i = 0; i < size; i++){
		max[vec[i].l] = 0;
		max[vec[i].r] = 0;
		for(j = 0; j < size; j++){
			if((vec[j].h > max[vec[i].l])&&(vec[i].l >= vec[j].l)&&(vec[i].l < vec[j].r)){
				max[vec[i].l] = vec[j].h;
			}
			if((vec[j].h > max[vec[i].r])&&(vec[i].r >= vec[j].l)&&(vec[i].r < vec[j].r)){
				max[vec[i].r] = vec[j].h;
			}
		}	
	}
	prev = -1;
	for(i = vec[0].l; i <= sup; i++){
		if((max[i] != -1)&&(max[i]!=prev)){
			printf("%d %d", i, max[i]);
			prev = max[i];
			if(i != sup){
				printf(" ");
			}
			else{
				printf("\n");
			}
		}
	}
}