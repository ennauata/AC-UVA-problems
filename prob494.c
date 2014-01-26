//
//  prob494.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 11/25/13.
//  Copyright (c) 2013 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>

int main(){
	char c, count, found_a_word, trash;
	found_a_word = 0;
	trash = 1;
	count = 0;
	while(scanf("%c", &c) != EOF){
		if(!((65 <= c && c <= 90) || (97 <= c && c <= 122))){
			if(!trash){
				count++;
				trash = 1;
			}
			if(c == '\n'){
				printf("%d\n", count);
				count = 0;
				trash = 1;
			}
		}
		else{
			trash = 0;
		}
	}
	return 0;
}