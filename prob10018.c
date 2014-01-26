//
//  prob10018.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 12/26/13.
//  Copyright (c) 2013 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>
#define MAX 99999

int main(){
	int t, i, len, inf, sup, r, s, k, palindromo, count;
	int numb[MAX], inverse[MAX], sum[MAX];
	char c;
	scanf("%d\n", &t);
	for(k = 0; k < t; k++){
		len = 0;
		while(scanf("%c", &c)){
			if(c == '\n'){
				break;
			}
			numb[len] = c - '0';
			len++;
		}
		palindromo = 0;
		count = 0;
		while(!palindromo){
			// Reverse
			inf = 0;
			sup = len - 1;
			while(inf <= sup){
				inverse[sup] = numb[inf];
				inverse[inf] = numb[sup];
				inf++;
				sup--;
			}
			/*
			for(i = 0; i < len; i++){
				printf("%d ", numb[i]);
			}
			printf("\n");
			for(i = 0; i < len; i++){
				printf("%d ", inverse[i]);
			}
			printf("\n");
			*/
			//Sum
			r = 0;
			for(i = 0; i < len; i++){
				s = r + inverse[i] + numb[i];
				if(s > 9){
					s = s%10;
					r = 1;
				}
				else{
					r = 0;
				}
				sum[i] = s;
			}
			if(r){
				sum[i] = r;
				len++;
			}
			/*
			printf("------\n");
			for(i = 0; i < len; i++){
				printf("%d ", sum[i]);
			}
			printf("\n");
			*/
			// Verify Palindromo
			inf = 0;
			sup = len - 1;
			palindromo = 1;
			while(inf < sup){
				if(sum[inf] != sum[sup]){
					palindromo = 0;
				}
				inf++;
				sup--;
			}
			for(i = 0; i < len; i++){
				numb[i] = sum[i];
			}
			count++;
		}
		printf("%d ", count);
		for(i = 0; i < len; i++){
			printf("%d", numb[i]);
		}
		printf("\n");
	}
	return 0;
}