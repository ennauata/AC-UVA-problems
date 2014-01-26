//
//  prob374.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 1/23/14.
//  Copyright (c) 2014 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>
#define MAX 100000

int b, p, m, store[MAX];
int recfunc(int exp){
	int res1, res2;
	if(exp > 1){
		if(exp/2 < MAX){
			if(store[exp/2] == -1){
				res1 = recfunc(exp/2);
				store[exp/2] = res1;
			}
			else{
				res1 = store[exp/2];
			}
		}
		else{
			res1 = recfunc(exp/2);
		}
		if(exp - exp/2 < MAX){
			if(store[exp - exp/2] == -1){
				res2 = recfunc(exp - exp/2);
				store[exp - exp/2] = res2; 
			}
			else{
				res2 = store[exp - exp/2]; 
			}
		}
		else{
			res2 = recfunc(exp - exp/2);
		}
		return ((res1%m)*(res2%m))%m;
	}
	return 0;
}

int main(){
	int res, i;
	while(scanf("%d %d %d\n\n", &b, &p, &m) != EOF){
		for(i = 0; i < MAX; i++){
			store[i] = -1;
		}
		if(p){
			store[1] = b%m;
			res = recfunc(p);
			printf("%d\n", res);
		}
		else{
			printf("1\n");
		}
	}
	return 0;
}