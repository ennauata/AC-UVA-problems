//
//  prob11195.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 1/10/14.
//  Copyright (c) 2014 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>
#define MAX 99999
/*
int rows, cols, primary, secondary, count, n; 
char map[15][15];
void backtracking(int i){
	int j;	
	if(i == n){
		count++;
		return;
	}
	if(i < n){
		for(j = 0; j < n; j++){	
			if((cols&(1<<j)) == 0 && (rows&(1<<(i+1))) == 0 && (secondary&(1 << (i+j))) == 0 && (primary&(1 << (n + (i - j)))) == 0 &&  map[i][j] == '.'){
				rows = rows|(1<<i);
				cols = cols|(1<<j);
				primary = primary|(1 << (n+(i-j))); 
				secondary = secondary|(1 << (i+j));
				backtracking(i+1);
				rows = rows&(~(1<<i));
				cols = cols&(~(1<<j));
				primary = primary&(~(1 << (n+(i-j))));
				secondary = secondary&(~(1 << (i+j)));
			}
		}
	}
	return;
}

int main(){
	int i, j, t = 1;
	scanf("%d\n", &n);
	while(n){
		for(i = 0; i < n; i++){
			scanf("%s", map[i]);
		}
		primary = 0;
		secondary = 0;
		count = 0;
		rows = 0;
		cols = 0;
		backtracking(0);
		printf("Case %d: %d\n", t++, count);
		scanf("%d\n", &n);
	}	
}
*/

typedef struct node{
	int i;
	int p;
	int r;
	int c;
	int s;
} node;
typedef struct{
	node itens[MAX];
	int top;
} stack;

void push(stack *st, int i, int r, int c, int p, int s){
	node n;
	n.i = i;
	n.p = p;
	n.r = r;
	n.c = c;
	n.s = s;
	st->itens[++(st->top)] = n;
}

node pop(stack *s){
	return s->itens[(s->top)--];
}
int rows, cols, primary, secondary, count, n; 
char map[15][15];
int main(){
	int i, j, t = 1;
	stack s;
	node nd;
	scanf("%d\n", &n);
	while(n){
		for(i = 0; i < n; i++){
			scanf("%s", map[i]);
		}
		count = 0;
		s.top = -1;
		push(&s, 0, 0, 0, 0, 0);
		while(s.top != -1){
		    nd = pop(&s);
			i = nd.i;
			primary = nd.p;
			secondary = nd.s;
			rows = nd.r;
			cols = nd.c;
			if(i == n){
				count++;
			}
			if(i < n){
				for(j = 0; j < n; j++){	
					if((cols&(1<<j)) == 0 && (rows&(1<<i)) == 0 && (secondary&(1 << (i+j))) == 0 && (primary&(1 << (n + (i - j)))) == 0  && map[i][j] == '.'){
						rows = rows|(1<<i);
						cols = cols|(1<<j);
						primary = primary|(1 << (n+(i-j))); 
						secondary = secondary|(1 << (i+j));
						push(&s, i+1, rows, cols, primary, secondary);
						rows = rows&(~(1<<i));
						cols = cols&(~(1<<j));
						primary = primary&(~(1 << (n+(i-j))));
						secondary = secondary&(~(1 << (i+j)));
					}
				}
			}
		}
		printf("Case %d: %d\n", t++, count);
		scanf("%d\n", &n);
	}	
}

