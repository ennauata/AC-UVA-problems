//
//  prob10222.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 1/30/14.
//  Copyright (c) 2014 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int main(){
	int i, j, flag;
	char kb_low[3][50] = {{"qwertyuiop[]\\"},{"asdfghjkl;'"},{"zxcvbnm,./"}};
	char c, kb_up[3][50] = {{"QWERTYUIOP[]\\"}, {"ASDFGHJKL;'"}, {"ZXCVBNM,./"}};
	while(scanf("%c", &c) != EOF){
		flag = 0;
		for(i = 0; i < 3; i++){
			for(j = 0; j < strlen(kb_low[i]); j++){
				if(c == kb_low[i][j] || c == kb_up[i][j]){
					if(j-2>=0){
						printf("%c", kb_low[i][j-2]);
					}
					else{
						printf("%c", kb_low[i][j]);
					}
					flag = 1;
				}
			}
		}
		if(!flag){
			printf("%c", c);
		}
	} 
	return 0;
}