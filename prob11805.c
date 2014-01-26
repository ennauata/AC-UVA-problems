//
//  prob489.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 11/26/13.
//  Copyright (c) 2013 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>

int main(){
	int i, t, n, k, p, res;
	scanf("%d", &t);
	for(i = 0; i < t; i++){
		scanf("%d %d %d", &n, &k, &p);
		res = (k+p)%n;
		if(!res){
			printf("Case %d: %d\n", i+1, n);
		}
		else{
			printf("Case %d: %d\n", i+1, res);
		}
	}
	return 0;
}