//
//  prob120.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 1/27/14.
//  Copyright (c) 2014 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>
#define MAX 99999

typedef struct stack{
	int itens[MAX];
	int top;
} stack;

void initialize(stack *s){
	s->top = -1;
}

void push(stack *s, int value){
	s->itens[++(s->top)] = value;
}

int pop(stack *s){
	return s->itens[(s->top)--];
}

void flip(stack *s, int n){
	int i, size;
	stack aux;
	initialize(&aux);
	size = s->top;
	for(i = 0; i <= size-n+1; i++){
		push(&aux, pop(s));
	}
	for(i = 0; i <= size-n+1; i++){
		s->itens[++(s->top)] = aux.itens[i];
	}
}

int main(){
	stack s, aux;
	int numb, i, j, max, k_max, flag;
	char ctrl;
	initialize(&s);
	initialize(&aux);
	while(scanf("%d%c", &numb, &ctrl) != EOF){
		push(&aux, numb);
		if(ctrl == '\n'){
			while(aux.top != -1){
				push(&s, pop(&aux));
			}
			for(i = s.top; i >= 0; i--){
				if(!i){
					printf("%d\n", s.itens[i]);
				}
				else{
					printf("%d ", s.itens[i]);
				}
			}
			for(i = 0; i <= s.top; i++){
				max = s.itens[i];
				k_max = i;
				for(j = i; j <= s.top; j++){
					if(s.itens[j] > max){
						max = s.itens[j];
						k_max = j;
						flag = 1;
					}
				}
				if(flag && k_max != i){
					flip(&s, k_max+1);
					flip(&s, i+1);
					if(k_max == s.top){
						printf("%d ", i+1);
					}
					else{
						printf("%d %d ", k_max+1, i+1);
					}
				}
				else if(!flag){
					break;
				}
			}
			printf("0\n");
			initialize(&s);
			initialize(&aux);
		}
	}
	return 0;
}