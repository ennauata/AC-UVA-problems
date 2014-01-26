//
//  prob10035.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 12/25/13.
//  Copyright (c) 2013 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>

int max(int a, int b){
	if(a > b){
		return a;
	}
	else{
		return b;
	}
}

int main(){
	int len1, len2, aux, carries, r, inf, sup, sum, i, max_len;
	char c;
	int numb1[10], numb2[10];
	while(1){
		// Reset
		for(i = 0; i < 10; i++){
			numb1[i] = 0;
			numb2[i] = 0;
		}
		// Read 1
		len1 = 0;
		while(scanf("%c", &c)){
			if(c == ' '){
				break;
			}
			else{
				numb1[len1] = c - '0';
				len1++;
			}
		}
		// Read 2
		len2 = 0;
		while(scanf("%c", &c)){
			if(c == '\n'){
				break;
			}
			else{
				numb2[len2] = c - '0';
				len2++;
			}
		}
		if(len1 == 1 && len2 == 1 && numb1[0] == 0 && numb2[0] == 0){
			break;
		}
		
		// Reverse 1
		inf = 0;
		sup = len1-1;
		while(inf < sup){
			aux = numb1[inf];
			numb1[inf] = numb1[sup];
			numb1[sup] = aux;
			sup--;
			inf++;
		}
		/*
		for(i = 0; i < len1; i++){
			printf("%d ", numb1[i]);
		}
		printf("\n");
		*/
		// Reverse 2
		inf = 0;
		sup = len2-1;
		while(inf < sup){
			aux = numb2[inf];
			numb2[inf] = numb2[sup];
			numb2[sup] = aux;
			sup--;
			inf++;
		}
		/*
		for(i = 0; i < len2; i++){
			printf("%d ", numb2[i]);
		}
		printf("\n");
		*/
		carries = 0;
		max_len = max(len1, len2);
		r = 0;
		for(i = 0; i < max_len; i++){
			sum = numb1[i] + numb2[i] + r;
			if(sum > 9){
				carries++;
				r = 1;
			}
			else{
				r = 0;
			}
		}
		if(carries){
			if(carries == 1){
				printf("%d carry operation.\n", carries);
			}
			else{
				printf("%d carry operations.\n", carries);
			}
		}
		else{
			printf("No carry operation.\n");	
		}
		
	}
	return 0;
}