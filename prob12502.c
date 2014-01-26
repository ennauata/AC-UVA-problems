//
//  prob12502.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 11/24/13.
//  Copyright (c) 2013 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>

int main(){
	float x, y, z, res, par;
	int i, n;
	scanf("%d", &n);
	for(i = 0; i < n; i++){
		scanf("%f %f %f", &x, &y, &z);
		par = (x+y)/3;
		res = x - par;
		res *= z;
		res /= par;
		res += 0.5;
		printf("%d\n", (int)res);
	}
	return 0;
}