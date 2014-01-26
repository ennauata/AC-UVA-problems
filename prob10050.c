//
//  prob10050.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 1/13/14.
//  Copyright (c) 2014 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>
#define MAX 99999

int main(){
	int t, k, n, p, i, j, count;
	int h[MAX], days[MAX];
 	scanf("%d", &t);	
	for(k = 0; k < t; k++){
		scanf("%d", &n);
		scanf("%d", &p);
		for(i = 0; i < p; i++){
			scanf("%d", &h[i]);
		}
		for(i = 1; i <= n; i++){
			days[i] = 0;
		}
		for(i = 0; i < p; i++){
			for(j = h[i]; j <= n; j += h[i]){
				days[j] = 1;
			}
		}
		count = 0;
		for(i = 1; i <= n; i++){
			if(i%7 != 6 && i%7 != 0 && days[i] == 1){
				count++;
			}
		}
		printf("%d\n", count);
	}
 return 0;
}