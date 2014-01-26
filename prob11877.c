//
//  prob11877.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 11/26/13.
//  Copyright (c) 2013 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>

int main(){
	int n, total, remain, aux;
	scanf("%d", &n);
	while(n){
		total = 0;
		remain = n;
		while(remain >= 3){
			aux = remain;
			remain = aux/3;
			remain += aux%3;
			total += aux/3;
		}
		if(remain == 2){
			total++;
		}
		printf("%d\n", total);
		scanf("%d", &n);
	}
	return 0;
}
