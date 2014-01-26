//
//  prob458.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 11/25/13.
//  Copyright (c) 2013 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>

int main(){
	char code;
	while(scanf("%c", &code) != EOF){
		if(code != '\n'){
			code -= 7;
			printf("%c", code);
		}
		else{
			printf("\n");
		}
	}
	return 0;
}