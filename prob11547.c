//
//  prob11547.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 2/6/14.
//  Copyright (c) 2014 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int main(){
	int i, n, res, t;
	scanf("%d", &t);
	for(i = 0; i < t; i++){
		scanf("%d", &n);
		res = abs((((((n*63)+7492)*5)-498)/10)%10);
		printf("%d\n", res);
	}
	return 0;
}