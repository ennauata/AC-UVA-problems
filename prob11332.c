//
//  prob11332.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 1/28/14.
//  Copyright (c) 2014 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>

int func(int n){
	int res = 0;
	while(n){
		res += n%10;
		n /= 10;
	}
	if(res > 9){
		return func(res);
	}
	else{
		return res;
	}
}

int main(){
	int n, res;
	scanf("%d", &n);
	while(n){
		res = func(n);
		printf("%d\n", res);
		scanf("%d", &n);
	}
	return 0;
}