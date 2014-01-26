//
//  prob445.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 11/25/13.
//  Copyright (c) 2013 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>

int main(){
	char c;
	int numb, count, i;
	
	count = 0;
	while(scanf("%c", &c) != EOF){
		if(c >= 48 && c <= 57){
			numb = c - '0';
			count += numb;
		}
		else if(c == '!'){
			printf("\n");
		}
		else if(c == 'b'){
			for(i = 0; i < count; i++){
				printf(" ");
			}
			count = 0;
		}
		else if(c == '\n'){
			printf("\n");
		}
		else{
			for(i = 0; i < count; i++){
				printf("%c", c);
			}
			count = 0;
		}
	}
	return 0;
}