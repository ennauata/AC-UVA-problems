//
//  prob101.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 1/3/14.
//  Copyright (c) 2014 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>
#include <string.h>

typedef struct stack{
	int top;
	int itens[26];
} stack;

void init(stack s[26], int len){
	int i;
	for(i = 0; i < len; i++){
		s[i].top = -1;
	}
}

void push(stack *s, int value){
	s->itens[++(s->top)] = value;
}

int pop(stack *s){
	return s->itens[(s->top)--];
}

int main(){
	stack pos[26];
	stack buffer;
	int n, a, b, i, j, item, stack_a, stack_b;
	char mode[10], dir[10];
	scanf("%d\n", &n);
	buffer.top = -1;
	init(pos, 25);
	for(i = 0; i < n; i++){
		push(&pos[i], i);
	}	
	while(1){
		scanf("%s", mode);
		if(strncmp(mode, "quit", 4) == 0){
			break;
		}
		else{
			scanf("%d %s %d\n", &a, dir, &b);
		}
		// Find a
		for(i = 0; i < n; i++){
			for(j = 0; j <= pos[i].top; j++){
				if(pos[i].itens[j] == a){
					stack_a = i;
				}
			}
		}
		// Find b
		for(i = 0; i < n; i++){
			for(j = 0; j <= pos[i].top; j++){
				if(pos[i].itens[j] == b){
					stack_b = i;
				}
			}
		}
		if(a != b && stack_a != stack_b){
			if(strncmp(mode, "move", 4) == 0 && strncmp(dir,"onto", 4) == 0){
				//printf("move %d onto %d\n", a, b);
				// Return blocks on top of a
				while(pos[stack_a].itens[pos[stack_a].top] != a){
					item = pop(&pos[stack_a]);
					push(&pos[item], item);
				}
				pop(&pos[stack_a]);
				// Return blocks on top of b and put block a onto block b
				while(pos[stack_b].itens[pos[stack_b].top] != b){
					item = pop(&pos[stack_b]);
					push(&pos[item], item);
				}
				push(&pos[stack_b], a);
			}
			else if(strncmp(mode, "move", 4) == 0 && strncmp(dir,"over", 4) == 0){
				//printf("move %d over %d\n", a, b);
				// Return blocks on top of a
				while(pos[stack_a].itens[pos[stack_a].top] != a){
					item = pop(&pos[stack_a]);
					push(&pos[item], item);
				}
				pop(&pos[stack_a]);
				// Puts block a over the stack containing block b
				push(&pos[stack_b], a);
			}
			else if(strncmp(mode, "pile", 4)== 0 && strncmp(dir,"onto", 4) == 0){
				//printf("pile %d onto %d\n", a, b);
				// Move blocks on top of a to a buffer
				while(pos[stack_a].itens[pos[stack_a].top] != a){
					item = pop(&pos[stack_a]);
					push(&buffer, item);
				}
				item = pop(&pos[stack_a]);
				push(&buffer, item);
				// Return blocks on top of b and copy stacked elements from the buffer
				while(pos[stack_b].itens[pos[stack_b].top] != b){
					item = pop(&pos[stack_b]);
					push(&pos[item], item);
				}
				push(&pos[stack_b], pop(&buffer));
				while(buffer.top != -1){
					push(&pos[stack_b], pop(&buffer));
				}
			}
			else if(strncmp(mode, "pile", 4) == 0 && strncmp(dir,"over", 4) == 0){
				//printf("pile %d over %d\n", a, b);
				// Move blocks on top of a to a buffer
				while(pos[stack_a].itens[pos[stack_a].top] != a){
					item = pop(&pos[stack_a]);
					push(&buffer, item);
				}
				item = pop(&pos[stack_a]);
				push(&buffer, item);
				// Copy stacked elements from the buffer
				push(&pos[stack_b], pop(&buffer));
				while(buffer.top != -1){
					push(&pos[stack_b], pop(&buffer));
				}
			}
		}
	}
	for(i = 0; i < n; i++){
		printf("%d:", i);
		for(j = 0; j <= pos[i].top; j++){
			printf(" %d", pos[i].itens[j]);
		}
		printf("\n");
	}
	return 0;
}