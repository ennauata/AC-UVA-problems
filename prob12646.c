//
//  prob12646.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 1/21/14.
//  Copyright (c) 2014 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>

int main(){
	int a, b, c;
	while(scanf("%d %d %d", &a, &b, &c) != EOF){
		if(a == b && b == c){
			printf("*\n");
		}
		else{
			if(a == b){
				printf("C\n");
			}
			else if(a == c){
				printf("B\n");
			}
			else{
				printf("C\n");
			}
		}
	}
	return 0;
}