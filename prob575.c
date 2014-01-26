//
//  prob575.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 1/5/14.
//  Copyright (c) 2014 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <math.h>
#define MAX 99999


int main(){
	char skew[MAX];
	int i, total, exp;
	while(gets(skew)){
		//printf("%d\n", (int)strlen(skew));
		if(skew[0] == '0' && strlen(skew) == 1){
			break;
		}
		else{
			total = 0;
			for(i = (int)strlen(skew)-1, exp = 1; i >= 0; i--, exp++){
				total += (skew[i] - '0')*(pow(2, exp)-1); 
			}
			printf("%d\n", total);
		}
	}
	return 0;
}