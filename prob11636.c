//
//  prob11636.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 3/1/14.
//  Copyright (c) 2014 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>

int main(){
	int seq[10001], i, j, min, n, t = 1;
	seq[1] = 0;
	for(i = 2; i < 10001; i++){
		if(i%2){
			seq[i] = seq[(i/2)+1]+1;
		}
		else{
		 	seq[i] = seq[i/2]+1;
		}
	}
	while(scanf("%d", &n)){
		if(n < 0){
			break;
		}
		else{
			printf("Case %d: %d\n", t++, seq[n]);
		}
	}
	return 0;
}