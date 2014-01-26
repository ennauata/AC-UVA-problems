//
//  prob842.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 11/21/13.
//  Copyright (c) 2013 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>
#include <math.h>
int main(){
	int n, t = 1;
	scanf("%d", &n);
	while(n){
		printf("Teste %d\n", t++);
		printf("%.0f\n", pow(2, n)-1);
		scanf("%d", &n);
	}
}