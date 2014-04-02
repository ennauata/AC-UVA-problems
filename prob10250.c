//
//  prob10250.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 3/14/14.
//  Copyright (c) 2014 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>

int main(){
	long double x1, y1, x2, y2, dx, dy, mx, my;
	while(scanf("%Lf %Lf %Lf %Lf", &x1, &y1, &x2, &y2) != EOF){
		mx = (x1+x2)/2;
		my = (y1+y2)/2;
		dx = mx-x1;
		dy = my-y1;
		printf("%Lf %Lf %Lf %Lf\n", mx-dy, my+dx, mx+dy, my-dx);
	}
	return 0;
}