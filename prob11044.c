//
//  prob11044.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 2/20/14.
//  Copyright (c) 2014 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>

int main(){
	int t, m, n, i;
	scanf("%d", &t);
	for(i = 0; i < t; i++){
		scanf("%d %d", &n, &m);
		printf("%d\n", (n/3)*(m/3));
	}
	return 0;
}