//
//  prob272.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 12/25/13.
//  Copyright (c) 2013 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>

int main(){
	char c;
	int open;
	open = 0;
	while(scanf("%c", &c) != EOF){
		if(c == '"'){
			if(!open){
				printf("``");
			}
			else{
				printf("''");
			}
			open = !open;
		}
		else{
			printf("%c", c);
		}
	}
	return 0;
}