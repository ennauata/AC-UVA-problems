//
//  prob532.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 4/6/14.
//  Copyright (c) 2014 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#define MAX 999999

typedef struct coord{
	int x, y, z;
	int recLev;
} coord;	

int i, j, k, l, r, c, tail, head, flag;
coord start, curr;
coord queue[MAX];
char maze[40][40][40];
int mark[40][40][40];
	
void add(coord el){
	queue[head++] = el;
	if(head == MAX){
		head = 0;
	}
}	

coord rmv(){
	coord res;
	res = queue[tail++];
	if(tail == MAX){
		tail = 0;
	}
	return res;
}

int main(){
	int x, y, z, recLev;
	coord next;
	int step[2] = {1, -1};
	scanf("%d%d%d", &l, &r, &c);
	while(l || r || c){
		for(k = 0; k < l; k++){
			for(i = 0; i < r; i++){
				scanf("%s", maze[k][i]);
				for(j = 0; j < c; j++){
					if(maze[k][i][j] == 'S'){
						start.x = k;
						start.y = i;
						start.z = j;
						start.recLev = 0;
						mark[k][i][j] = 1;
					}
					else{
						mark[k][i][j] = 0;
					}
				}
			}
		}
		tail = head = 0;
		flag = 0;
		add(start);
		while(tail != head){
			curr = rmv();
			x = curr.x;
			y = curr.y;
			z = curr.z;
			recLev = curr.recLev;
			if(maze[x][y][z] == 'E'){
				printf("Escaped in %d minute(s).\n", recLev); 
				flag = 1;
				break;
			}
			else{
				maze[x][y][z] = '#';
				next.recLev = recLev+1;
				for(i = 0; i < 2; i++){
					if((x+step[i] < l) && (x+step[i] >= 0) && (maze[x+step[i]][y][z] != '#')){
						next.x = x+step[i];
						next.y = y;
						next.z = z;
						if(!mark[next.x][next.y][next.z]){
							mark[next.x][next.y][next.z] = 1;
							add(next);
						}
					}
				}
				for(i = 0; i < 2; i++){
					if((y+step[i] < r) && (y+step[i] >= 0) && (maze[x][y+step[i]][z] != '#')){
						next.x = x;
						next.y = y+step[i];
						next.z = z;
						if(!mark[next.x][next.y][next.z]){
							mark[next.x][next.y][next.z] = 1;
							add(next);
						}
					}
				}
				for(i = 0; i < 2; i++){
					if((z+step[i] < c) && (z+step[i] >= 0) && (maze[x][y][z+step[i]] != '#')){
						next.x = x;
						next.y = y;
						next.z = z+step[i];
						if(!mark[next.x][next.y][next.z]){
							mark[next.x][next.y][next.z] = 1;
							add(next);
						}
					}
				}
			}
		}
		if(!flag){
			printf("Trapped!\n");
		}
		scanf("%d%d%d", &l, &r, &c);
	}
	return 0;
}