//
//  prob11172.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 12/26/13.
//  Copyright (c) 2013 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>

int main(){
	int t, k, num1, num2;
	scanf("%d", &t);
	for(k = 0; k < t; k++){
		scanf("%d %d\n", &num1, &num2);
		if(num1 > num2){
			printf(">\n");
		}
		else if(num1 < num2){
			printf("<\n");
		}
		else{
			printf("=\n");
		}
	}
	return 0;
}