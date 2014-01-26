//
//  prob10474.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 12/9/13.
//  Copyright (c) 2013 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>
#define MAX 99999

int main(){
	int n, q, i;
	int marbles[MAX], queries[MAX];
	scanf("%d %d", &n, &q);
	while(n && q){
		for(i = 0; i < n; i++){
			scanf("%d", marbles[i++]);
		}
		for(j = 0; j < q; j++){
			scanf("%d", queries[j++]);
		}
		
		scanf("%d %d", &n, &q);
	}
}