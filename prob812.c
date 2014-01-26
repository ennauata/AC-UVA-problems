//
//  prob812.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 11/14/13.
//  Copyright (c) 2013 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>

int main(){
	int value, j=0, c50, c10, c5, c1;
	scanf("%d", &value);
	while(value){
		j++;
		c50 = value/50;
		value = value%50;
		
		c10 = value/10;
		value = value%10;
		
		c5 = value/5;
		value = value%5;
		
		c1 = value;
		printf("Teste %d\n", j);
		printf("%d %d %d %d\n", c50, c10, c5, c1);
		scanf("%d", &value);
		if (value) {
			printf("\n");
		}
	}
}