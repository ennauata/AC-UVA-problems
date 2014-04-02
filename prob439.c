//
//  prob438.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 1/28/14.
//  Copyright (c) 2014 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>
#define MAX 500000

typedef struct coord{
	char c;
	int n, count;	
} coord;

typedef struct queue{
	coord itens[MAX];
	int front, back;
} queue;

void init(queue *q){
	q->front = q->back = 0;
}

void push_front(queue *q, char c1, int n1, int count){
	coord node;
	node.c = c1;
	node.n = n1;
	node.count = count;
	q->itens[(q->front)++] = node;
	if(q->front == MAX){
		q->front = 0;
	}
}

coord remove_back(queue *q){
	return q->itens[(q->back)++];
	if(q->back == MAX){
		q->back = 0;
	}
}	

int main(){
	coord node;
	int n1, n2, count, ni;
	char c1, c2, ci;
	queue q;
	while(scanf("%c%d %c%d\n", &c1, &n1, &c2, &n2) != EOF){
		count = 0;
		init(&q);
		ci = c1;
		ni = n1;
		push_front(&q, c1, n1, 0);
		while(q.front != q.back){
			node = remove_back(&q);
			c1 = node.c;
			n1 = node.n;
			count = node.count;
			if(c1 == c2 && n1 == n2){
				printf("To get from %c%d to %c%d takes %d knight moves.\n", ci, ni, c2, n2, count);
				break;
			}
			else{
				// Up
				if(c1 - 2 >= 'a'){
					if(n1 - 1 >= 1){
						push_front(&q, c1-2, n1-1, count+1);
					}
					if(n1 + 1 <= 8){
						push_front(&q, c1-2, n1+1, count+1);
					}
				}
				// Down
				if(c1 + 2 <= 'h'){
					if(n1 - 1 >= 1){
						push_front(&q, c1+2, n1-1, count+1);
					}
					if(n1 + 1 <= 8){
						push_front(&q, c1+2, n1+1, count+1);
					}
				}
				// Left
				if(n1 - 2 >= 1){
					if(c1 - 1 >= 'a'){
						push_front(&q, c1-1, n1-2, count+1);
					}
					if(c1 + 1 <= 'h'){
						push_front(&q, c1+1, n1-2, count+1);
					}
				}
				// Right
				if(n1 + 2 <= 8){
					if(c1 - 1 >= 'a'){
						push_front(&q, c1-1, n1+2, count+1);
					}
					if(c1 + 1 <= 'h'){
						push_front(&q, c1+1, n1+2, count+1);
					}
				}
			}
		}
	}
	return 0;
}