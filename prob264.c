//
//  prob264.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 1/31/14.
//  Copyright (c) 2014 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>
#define MAX 5000

int main(){
	int i, ref[MAX], n;
	ref[1] = 1;
	for(i = 2; i < MAX; i++){
		ref[i] = ref[i-1] + i - 1;
	}
	while(scanf("%d", &n) != EOF){
		for(i = 0; i < MAX; i++){
			if(ref[i] > n){
				break;
			}	
		}
		if(i%2 == 0){
			printf("TERM %d IS %d/%d\n", n, (i-1)-(n-ref[i-1]), 1+(n-ref[i-1]));
		}
		else{
			printf("TERM %d IS %d/%d\n", n, 1+(n-ref[i-1]), (i-1)-(n-ref[i-1]));
		}
	}
	return 0;
}