//
//  prob10929.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 4/12/14.
//  Copyright (c) 2014 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#define N 2000

int main(){
	int even, odd, ctrl, i;
	char numb[N];
	while(gets(numb)){
		if((strlen(numb) == 1)&&(numb[0]=='0')){
			break;
		}
		else{
			ctrl = 0;
			even = 0;
			odd = 0;
			for(i = 0; i < strlen(numb); i++){
				if(ctrl){
					even += numb[i]-'0';
				}
				else{
					odd += numb[i]-'0';
				}
				ctrl = !ctrl;
			}
			if((even%11) == (odd%11)){
				printf("%s is a multiple of 11.\n", numb);
			}
			else{
				printf("%s is not a multiple of 11.\n", numb);
			}
		}
	}
	return 0;
}