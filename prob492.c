//
//  prob492.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 2/19/14.
//  Copyright (c) 2014 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>

int main(){
	char c, st;
	int f, op;
	f = 1;
	while(scanf("%c", &c) != EOF){
		if(c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I' || c == 'o' || c == 'O' || c == 'u' || c == 'U'){
			if(f){
				f = 0;
				op = 1;
			}
			printf("%c", c);
		}
		else if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')){
			if(f){
				f = 0;
				op = 0;
				st = c;
			}
			else{
				printf("%c", c);
			}
		}
		else{
			if(op == 1){
				printf("ay");
			}
			else if(op == 0){
				printf("%cay", st);
			}
			printf("%c", c);
			op = -1;
			f = 1;
		}
	}
	return 0;
}