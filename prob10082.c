//
//  prob10082.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 12/30/13.
//  Copyright (c) 2013 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int main(){
	int i, j, found;
	char c;
	char keyboard[4][13] = {{'`', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '='},
							{'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', '[', ']', '\\'},
							{'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', ';', '\'', '\0', '\0'},
							{'Z', 'X', 'C', 'V', 'B', 'N', 'M', ',', '.', '/', '\0', '\0', '\0'}};
	
	while(scanf("%c", &c) != EOF){
	found = 0;
		for(i = 0; i < 4; i++){
			for(j = 0; j < 13; j++){
				if(c == keyboard[i][j]){
					if(j - 1 >= 0){
						printf("%c", keyboard[i][j-1]);
					}
					else{
						printf("%c", keyboard[i][j]);
					}
					found = 1;
				}
			}
		}
		if(!found){
			printf("%c", c);
		}
	}
	return 0;
}