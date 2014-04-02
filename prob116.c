//
//  prob116.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 3/1/14.
//  Copyright (c) 2014 Nelson Isao Nauata Junior. All rights reserved.
//
#include <stdio.h>
#define MAX 2000
#define INFINITY 5368709111
#define MIN(A,B) ((A) < (B)) ? (A) : (B)

typedef struct node{
	long int p_i;
	long int w;
} node;

typedef struct coord{
	long int i, j;
} coord;

typedef struct queue{
	coord itens[MAX];
	long int tail, head;
} queue;

long int n, m;
long int dist[MAX][MAX];
node graph[MAX][MAX];
queue q;

void push(coord c){
	q.itens[q.head++] = c;
	if(q.head == MAX){
		q.head = 0;
	}
}

coord pop(){
	coord res;
	res = q.itens[q.tail++];
	if(q.tail == MAX){
		q.tail = 0;
	}
	return res;
}

void bfs_relax(){
	coord nd, ax;
	long int dx[3] = {-1, 0, 1}, i, next;
	q.tail = q.head = 0;
	for(i = 0; i < n; i++){
		nd.i = i;
		nd.j = m-1;
		push(nd);
		dist[i][m-1] = graph[i][m-1].w;
	}
	while(q.tail != q.head){
		nd = pop();
		if(nd.j >  0){
			for(i = 0; i < 3; i++){
				next = (nd.i+dx[i]+n)%n;
				if(dist[nd.i][nd.j]+graph[next][nd.j-1].w < dist[next][nd.j-1]){
					graph[next][nd.j-1].p_i = nd.i;
					dist[next][nd.j-1] = dist[nd.i][nd.j]+graph[next][nd.j-1].w;
					ax.i = next;
					ax.j = nd.j-1;
					push(ax);
				}
				else if (dist[nd.i][nd.j]+graph[next][nd.j-1].w == dist[next][nd.j-1]) {
					graph[next][nd.j-1].p_i = MIN(nd.i, graph[next][nd.j-1].p_i);
				}
			}
		}
	}
}

int main(){
	long int i, j, p, q; 
	long int min; 
	long int buffer[MAX], k, buffer_l[MAX];
	while(scanf("%ld %ld", &n, &m) != EOF){
		for(i = 0; i < n; i++){
			for(j = 0; j < m; j++){
				scanf("%ld", &graph[i][j].w);
				dist[i][j] = INFINITY;
				graph[i][j].p_i = -1;
			}
		}
		bfs_relax();
		min = dist[0][0];
		k = 0;
		p = 0;
		q = 0;
		while(p != -1){
			buffer[k++] = p;
			p = graph[p][q++].p_i;
		}
		for(i = 1; i < n; i++){
			if(dist[i][0] < min){
				min = dist[i][0];
				k = 0;
				p = i;
				q = 0;
				while(p != -1){
					buffer[k++] = p;
					p = graph[p][q++].p_i;
				}
			}
			else if(dist[i][0] == min){
				k = 0;
				p = i;
				q = 0;
				while(p != -1){
					buffer_l[k++] = p;
					p = graph[p][q++].p_i;
				}
				for(p = 0; p < m; p++){
					if(buffer_l[p] < buffer[p]){
						for(q = 0; q > k; q++){
							buffer[q] = buffer_l[q];
						}
						break;
					}
					else if(buffer_l[p] < buffer[p]){
						break;
					}
				}
			}
		}
		for(i = 0; i < m; i++){
			printf("%ld", buffer[i]+1);
			if(i != m-1){
				printf(" ");
			}
		}
		printf("\n");
		printf("%ld\n", min);
	}
	return 0;
}