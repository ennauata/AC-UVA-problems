//
//  prob483.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 1/6/14.
//  Copyright (c) 2014 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#define MAX 99999

int main(){
	int k, inf, sup, newline, i, size;
	char buffer[MAX], aux, c;
	while(1){
		size = 0;
		newline = 0;
		while(1){
			k = scanf("%c", &c);
			if(k == EOF || c == '\n' || c == ' '){
				if(c == '\n'){
					newline = 1;
				}
				buffer[size] = '\0';
				break;
			}
			else{
				buffer[size++] = c;
			}
		}
		if(k == EOF){
			break;
		}
		else{
			inf = 0;
			sup = size-1;
			while(inf < sup){
				aux = buffer[inf];
				buffer[inf] = buffer[sup];
				buffer[sup] = aux;
				inf++;
				sup--;
			}
			if(newline){
				printf("%s\n", buffer);
			}
			else{
				printf("%s ", buffer);
			}
		}
	}
	return 0;
}