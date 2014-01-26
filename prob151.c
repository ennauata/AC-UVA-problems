//
//  prob151.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 1/9/14.
//  Copyright (c) 2014 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>

int main(){
	int regions[200], count, possible, i, k, n, remain, j;
	scanf("%d", &n);
	while(n){
		for(k = 1; k <= n; k++){
			remain = n;
			possible = 0;
			i = 1;
			count = 0;
			for(j = 1; j <= n; j++){
				regions[j] = 0;
			}
			while(remain > 0){
				if(regions[i] == 0){
					if(count%k == 0){
						regions[i] = 1;
						//printf("%d ", i);
						remain--;
						count = 0;
					}
					if(!remain){
						if(i == 13){
							possible = 1;
						}
						break;
					}
					count++;
				}
				i++;
				if(i > n){
					i = 1;
				}
			}
			//printf("\n");
			if(possible){
				printf("%d\n", k);
				break;
			}
		}
		scanf("%d", &n);
	}
	return 0;
}