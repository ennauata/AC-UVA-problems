//
//  prob673.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 11/29/13.
//  Copyright (c) 2013 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#define STACKSIZE 10000


typedef struct stack{
	int elements[STACKSIZE];
	int top;
}	stack;

int push(stack *s, int value){
	if(s->top < STACKSIZE){
		s->elements[++s->top] = value;
		return 0;
	}
	else{
		return 1;
	}
}

int empty(stack *s){
	if(s->top == -1){
		return 1;
	}
	else
		return 0;
}


int pop(stack *s){
	if(!empty(s)){
		return s->elements[s->top--];
	}
	return -1;
}

int clean(stack *s){
	s->top = -1;
	return 0;
}

int main(){
	int n, i, j;
	char set[10000], is_balanced, balanced;
	stack s;
	scanf("%d\n", &n);
	for(i = 0; i < n; i++){
		gets(set);
		balanced = 1;
		clean(&s);
		for(j = 0; j < strlen(set); j++){
			if(set[j] == '('){
				push(&s, -1);
			}
			else if(set[j] == '['){
				push(&s, -2);
			}
			else if(set[j] == ')' || set[j] == ']'){
				if(!empty(&s)){
					is_balanced = pop(&s);
				}
				else{
					balanced = 0; 
					break;
				}
				if(set[j] == ')'){
					is_balanced += 1;
				}
				else if(set[j] == ']'){
					is_balanced += 2;
				}
				if(is_balanced){
					balanced = 0;
					break;
				}
			}
		}
		if(balanced && empty(&s)){
			printf("Yes\n");
		}
		else{
			printf("No\n");
		}
	}
	return 0;
}