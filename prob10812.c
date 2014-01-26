//
//  prob10812.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 1/10/14.
//  Copyright (c) 2014 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>

int main(){
	int n, i, sum, diff, sa, sb, impossible;
	scanf("%d", &n);
	for(i = 0 ; i < n; i++){
		scanf("%d %d", &sum, &diff);
		impossible = 0;
		if((sum + diff) % 2 == 0){
			sa = (sum + diff)/2;
		}
		else{
			impossible = 1;
		}
		if(sum - diff >= 0  && (sum - diff) % 2 == 0){
			sb = (sum - diff)/2;
		}
		else{
			impossible = 1;
		}
		if(impossible){
			printf("impossible\n");
		}
		else{
			if(sa > sb){
				printf("%d %d\n", sa, sb);
			}
			else{
				printf("%d %d\n", sb, sa);
			}
		}
	}
}