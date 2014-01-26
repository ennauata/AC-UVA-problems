//
//  prob10696.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 1/2/14.
//  Copyright (c) 2014 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>

int f91(int n){
	if(n <= 100){
		return f91(f91(n+11));
	}
	else{
		return n-10;
	}
}

int main(){
	int n, res;
	scanf("%d", &n);
	while(n){
		res = f91(n);
		printf("f91(%d) = %d\n", n, res);
		scanf("%d", &n);
	}
	return 0;
}