//
//  prob10004.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 1/4/14.
//  Copyright (c) 2014 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>

typedef struct stack{
	int itens[300];
	int top;
} stack;

void push(stack *s, int i){
	s->itens[++(s->top)] = i;
}

int pop(stack *s){
	return s->itens[(s->top)--];
}

void init(stack *s){
	s->top = -1;
}


int main(){
	int n, e, n1, n2, i, j, v, c1, c2, possible;
	int map[300][300];
	int mark[300];
	stack s;
	scanf("%d", &n);
	while(n){
		init(&s);
		possible = 1;
		for(i = 0; i < n; i++){
			for(j = 0; j < n; j++){
				map[i][j] = 0;
			}
			mark[i] = 0;
		}
		scanf("%d", &e);
		
		for(i = 0; i < e; i++){
			scanf("%d %d", &n1, &n2);
			map[n1][n2] = map[n2][n1] = 1;
		}
		push(&s, 0);
		v = 0;
		mark[0] = 1;
		while(s.top != -1){
			//printf("%d\n", s.top);
			for(i = 0; i < n; i++){
				if(map[v][i] == 1 && mark[i] == 0){
					push(&s, i);
				}
			}
			v = pop(&s);
			c1 = 0;
			c2 = 0;
			for(i = 0; i < n; i++){
				if(map[v][i] == 1 && mark[i] == 1){
					c1 = 1;
				}
				else if(map[v][i] == 1 && mark[i] == -1){
					c2 = 1;
				}
			}
			if(c1 && c2){
				possible = 0;
				break;
			}
			else if(c1){
				mark[v] = -1;
			}
			else if(c2){
				mark[v] = 1;
			}
		}
		if(possible){
			printf("BICOLORABLE.\n");
		}
		else{
			printf("NOT BICOLORABLE.\n");
		}
		scanf("%d", &n);
	}
	return 0;
}