//
//  prob340.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 11/29/13.
//  Copyright (c) 2013 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>
#define MAX 1000000

int main(){
	int n, s, check, num;
	int secret[MAX];
	int guess[MAX];
	
	scanf("%d", &n);
	while(n){
		check = 0;
		for(i = 0; i < n; i++){
			scanf("%d", &num);
			check += num;
			secret[i] = num;
		}
	 	while(sum){
			for(i = 0; i < n; i++){
				scanf("%d", &num);
				guess[i] = num;
			}
			
			check = 0;
			for(i = 0; i < n; i++){
				scanf("%d", &num);
				check += num;
				secret[i] = num;
			}
		}
		scanf("%d", &n);
	}
	return 0;
}