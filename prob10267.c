//
//  prob10267.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 5/25/14.
//  Copyright (c) 2014 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>
#define MAX 1000000

typedef struct{
	int x, y;
} coord;

coord stack[MAX];
int size;
int step_i[4] = {1, -1, 0, 0};
int step_j[4] = {0, 0, -1, 1};
char bitmap[500][500], C, fileName[500];
char comm;
int N, M;

void push(coord e){
	stack[size++] = e;
}

coord pop(){
	return stack[--size];
}

void fill(int y, int x, char new_c, char old_c){
	int k, new_x, new_y;
	coord c;
	c.x = x;
	c.y = y;
	push(c);
	while(size){
		//printf("size = %d\n", size);
		c = pop();
		x = c.x;
		y = c.y;
		bitmap[y][x] = new_c;
		for(k = 0; k < 4; k++){
			new_x = step_i[k] + x;
			new_y = step_j[k] + y;
			if(new_x < M && new_x >= 0 && new_y < N && new_y >= 0 && bitmap[new_y][new_x] == old_c){
				c.x = new_x;
				c.y = new_y;
				push(c);
			}
		}
	}
}

int main(){
	int i, j, X, Y, Y1, Y2, X1, X2, si, sj, ei, ej; 
	char trash[100];
	while(scanf("%c ", &comm) != EOF){		
		//printf("comm = %c\n", comm);
		if(comm == 'I'){
			scanf("%d %d\n", &M, &N);
			for(i = 0; i < N; i++){
				for(j = 0; j < M; j++){
					bitmap[i][j] = 'O';
				}
			}
			//printf("N = %d M = %d\n", N, M);
		}
		else if(comm == 'C'){
			for(i = 0; i < N; i++){
				for(j = 0; j < M; j++){
					bitmap[i][j] = 'O';
				}
			}
		}
		else if(comm == 'L'){
			scanf("%d %d %c\n", &X, &Y, &C);
			if(Y >= 1 && Y <= N && X >= 1 && X <= M){
				bitmap[Y-1][X-1] = C;
			}
		}
		else if(comm == 'V'){
			scanf("%d %d %d %c\n", &X, &Y1, &Y2, &C);
			if(Y1 >= 1 && Y1 <= N && X >= 1 && X <= M && Y2 >= 1 && Y2 <= N){
				if(Y2 > Y1){
					for(i = Y1-1; i < Y2; i++){
						bitmap[i][X-1] = C;
					}
				}
				else{
					for(i = Y2-1; i < Y1; i++){
						bitmap[i][X-1] = C;
					}
				}
			}
		}
		else if(comm  == 'H'){
			scanf("%d %d %d %c\n", &X1, &X2, &Y, &C);
			if(X1 >= 1 && X1 <= M && Y >= 1 && Y <= N && X2 >= 1 && X2 <= M){
				if(X2 > X1){
					for(i = X1-1; i < X2; i++){
						bitmap[Y-1][i] = C;
					}
				}
				else{
					for(i = X2-1; i < X1; i++){
						bitmap[Y-1][i] = C;
					}	
				}
			}
		}
		else if(comm == 'K'){
			scanf("%d %d %d %d %c\n", &X1, &Y1, &X2, &Y2, &C);
			if(X1 >= 1 && X1 <= M && Y1 >= 1 && Y1 <= N && X2 >= 1 && X2 <= M && Y2 >= 1 && Y2 <= N){
				if(X1 < X2){
					si = X1;
					ei = X2;
				}
				else{
					si = X2;
					ei = X1;
				}
				if(Y1 < Y2){
					sj = Y1;
					ej = Y2;
				}
				else{
					sj = Y2;
					ej = Y1;
				}
				for(j = sj-1; j < ej; j++){
					for(i = si-1; i < ei; i++){
						bitmap[j][i] = C;
					}
				}
			}
		}	
		else if(comm == 'F'){
			scanf("%d %d %c\n", &X, &Y, &C);
			size = 0;
			if(Y >= 1 && Y <= N && X >= 1 && X <= M && bitmap[Y-1][X-1] != C){
				fill(Y-1, X-1, C, bitmap[Y-1][X-1]);
			}
		}
		else if(comm == 'S'){
			scanf("%s\n", fileName);
			printf("%s\n", fileName);
			for(i = 0; i < N; i++){
				for(j = 0; j < M; j++){
					printf("%c", bitmap[i][j]);
				}
				printf("\n");
			}
		}
		else if(comm == 'X'){
			break;
		}
		else{
			gets(trash);
		}
	}
	return 0;
}
