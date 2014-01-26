//
//  prob784.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 12/22/13.
//  Copyright (c) 2013 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#define MAX 99999

typedef struct coord{
	int x;
	int y;
} coord;

void push(coord s[MAX], int *top, int x, int y){
	s[++(*top)].x = x;
	s[*top].y = y;
}

coord pop(coord s[MAX], int *top){
	coord c;
	c.x = s[*top].x;
	c.y = s[(*top)--].y;
	return c;
}

int main(){
	int t, i, j, k, numRows, top, s_x, s_y, x_current, y_current;
	char maze[30][100], buffer[100];
	coord stack[MAX], c;
	scanf("%d\n", &t);
	for(i = 0; i < t; i++){
		j = 0;
		while(gets(buffer)){
			if(buffer[0] == '_'){
				break;
			}
			for(k = 0; k < strlen(buffer) + 1; k++){
				maze[j][k] = buffer[k];			
			}
			j++;
		}
		numRows = j;
		/*for(j = 0; j < numRows; j++){
			printf("%s\n", maze[j]);
		}*/
		for(j = 0; j < numRows; j++){
			for(k = 0; k < strlen(maze[j]); k++){
				if(maze[j][k] == '*'){
					s_x = j;
					s_y = k;
				}
			}
		}
		top = -1;
		push(stack, &top, s_x, s_y);
		x_current = s_x;
		y_current = s_y;
		while(top != -1){
			// Left
			if( maze[x_current][y_current - 1] == ' '){
				push(stack, &top, x_current, y_current - 1);
			}
			// Right
			if( maze[x_current][y_current + 1] == ' '){
				push(stack, &top, x_current , y_current+1);
			}
			// Up
			if( maze[x_current - 1][y_current] == ' '){
				push(stack, &top, x_current - 1, y_current);
			}
			// Down
			if( maze[x_current + 1][y_current] == ' '){
				push(stack, &top, x_current + 1, y_current);
			}
			maze[x_current][y_current] = '#';
			c = pop(stack, &top);
			x_current = c.x;
			y_current = c.y;
		}
		for(j = 0; j < numRows; j++){
			printf("%s\n", maze[j]);
		}
		printf("_____\n");
	}
	return 0;
}