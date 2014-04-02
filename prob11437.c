//
//  prob11437.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 3/25/14.
//  Copyright (c) 2014 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct point{
	double x, y;
} point;

double dot(point a, point b){
	return a.x * b.y - a.y * b.x;
}

point getInter(point a, point b, point c, point d){
	point e;
	double dx = b.x - a.x, dy = b.y - a.y;
	double da = d.x -c.x, db = d.y - c.y;
	double s = (da * (c.y - a.y) + db * (a.x - c.x))/(double)(da * dy - db * dx);
	e.x = a.x + s * dx;
	e.y = a.y + s * dy;
	return e;
}

point sum(point a, point b){
	point c;
	c.x = a.x + b.x;
	c.y = a.y + b.y;
	return c;
}

point minus(point a, point b){
	point c;
	c.x = a.x - b.x;
	c.y = a.y - b.y;
	return c;
}

point mul(point a, double b){
	point c;
	c.x = a.x * b;
	c.y = a.y * b;
	return c;
}

int main(){
	int n, i;
	double area;
	point a, b, c, d, e, f, r, p, q;
	scanf("%d", &n);
	for(i = 0; i < n; i++){
		scanf("%lf %lf %lf %lf %lf %lf", &a.x, &a.y, &b.x, &b.y, &c.x, &c.y);
		d = sum(b, mul(minus(c, b), 1./3));
		e = sum(c, mul(minus(a, c), 1./3));
		f = sum(a, mul(minus(b, a), 1./3));
		r = getInter(f, c, a, d);
		p = getInter(a, d, b, e);
		q = getInter(c, f, b, e);
		area = abs(dot(minus(q, p), minus(r, p)))/2;
		printf("%.0lf\n", area);
	}
	return 0;
}