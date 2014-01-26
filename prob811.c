//
//  prob811.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 11/14/13.
//  Copyright (c) 2013 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>

int main(){
	int n, value, i, j=0;
	scanf("%d", &n);
	while(n){
	j++;
		for(i = 0; i < n; i++){
			scanf("%d", &value);
			if(value == i+1){
				printf("Teste %d\n", j);
				printf("%d\n", value);
			}
		}
		scanf("%d", &n);
		if(n){
			printf("\n");
		}
	}
}