//
//  prob414.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 11/25/13.
//  Copyright (c) 2013 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>

int main(){
	int lines[13];
	int n, i, j, b, min, sum;
	char c;
	scanf("%d", &n);
	while(n){
		min = 50;
		for(i = 0; i< n; i++){
			b = 0;
			for(j = 0; j < 26; j++){
				scanf("%c", &c);
				if(c == ' '){
					b++;
				}
			}
			lines[i] = b;
			if(b < min){
				min = b;
			}
		}
		sum = 0;
		for(i = 0; i < n; i++){
			sum += (lines[i] - min);
		}
		printf("%d\n", sum);
		scanf("%d", &n);
	}
	return 0;
}