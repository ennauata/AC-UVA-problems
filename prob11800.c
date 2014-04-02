//
//  prob11800.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 3/26/14.
//  Copyright (c) 2014 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct point{
	double x, y;
} point;

double dot(point a, point b, point c, point d){
	double dx1 = a.x-b.x; double dy1 = a.y-b.y;
	double dx2 = c.x-d.x; double dy2 = c.y-d.y;
	return dx1*dx2+dy1*dy2;
}

double cross(point a, point b, point c, point d){
	double dx1 = a.x-b.x; double dy1 = a.y-b.y;
	double dx2 = c.x-d.x; double dy2 = c.y-d.y;
	return dx1*dy2-dx2*dy1;
}

int isParallel(point a, point b, point c, point d){
	//printf("%f\n", cross(a, b, c, d));
	if(cross(a, b, c, d) == 0)
		return 1;
	return 0; 
}

double getDist(point a, point b){
	return sqrt(pow(a.x-b.x, 2)+pow(a.y-b.y, 2)); 
}

int equalLateral(point a, point b, point c){
	double dist1, dist2;
	dist1 = getDist(a, b);
	dist2 = getDist(a, c);
	//printf("%f %f\n", dist1, dist2);
	if(dist1 == dist2)
		return 1;
	return 0;
}

int anglRet(point a, point b, point c){
	if(dot(a, b, a, c) == 0)
		return 1;
	return 0;
}

double theta(point a, point b){
	double t;
	double dx = b.x-a.x; double ax = abs(dx);
	double dy = b.y-a.y; double ay = abs(dy);
	if(ax+ay == 0){
		t = 0;
	}
	else{
		t = (double) dy/(ax+ay);
	}
	if(dx < 0)
		t = 2-t;
	else if(dy < 0)
		t = 4+t;
	return t*90.0;
}

point a, b, c, d;
int flag;
void convexHull(){
	int i, j, min, M, N = 4;
	double th, v;
	point t;
	point p[10];
	p[0] = a;
	p[1] = b;
	p[2] = c;
	p[3] = d;
	for(min = 0, i = 1; i < N; i++)
		if(p[i].y  < p[min].y) min = i;
	p[N] = p[min]; th = 0.0;
	for(M = 0; M < N; M++){
		t = p[M]; 
		p[M] = p[min]; 
		p[min] = t;
		min = N; v = th; th = 360.1;
		for(i = M+1; i <= N; i++){
			if(theta(p[M], p[i]) >= v){
				if(theta(p[M], p[i]) < th){
					min = i;
					th = theta(p[M], p[min]);
				}
			}
		}
		if(min == N) break;
	}
	for(i = 0 ; i < N; i++){
		for(j = i+1; j < N; j++){
			if((p[i].x == p[j].x) && (p[i].y == p[j].y)){
				flag = 1;
			}
		}
	}
	a = p[0];
	b = p[1];
	c = p[2];
	d = p[3];
}

int main(){
	int n, i;
	scanf("%d", &n);
	for(i = 0; i < n; i++){
		scanf("%lf%lf%lf%lf%lf%lf%lf%lf", &a.x, &a.y, &b.x, &b.y, &c.x, &c.y, &d.x, &d.y);
		//printf("%lf %lf %lf %lf %lf %lf %lf %lf\n\n", a.x, a.y, b.x, b.y, c.x, c.y, d.x, d.y);
		flag = 0;
		convexHull();
		//printf("%lf %lf %lf %lf %lf %lf %lf %lf\n\n", a.x, a.y, b.x, b.y, c.x, c.y, d.x, d.y);
		printf("Case %d: ", i+1);
		if((isParallel(a, b, d, c) || isParallel(a, d, b, c)) && !flag){
			if(isParallel(a, b, d, c) && isParallel(a, d, b, c)){
				if(equalLateral(a, b, d)){
					if(anglRet(a, b, d)){
						printf("Square\n");
					}
					else{
						printf("Rhombus\n");
					}
				}
				else if(anglRet(a, b, d)){
					printf("Rectangle\n");
				}	
				else{
					printf("Parallelogram\n");
				}
			}
			else{
				printf("Trapezium\n");
			}
		}
		else{
			printf("Ordinary Quadrilateral\n");
		}
	}
	return 0;
}