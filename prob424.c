//
//  prob424.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 11/29/13.
//  Copyright (c) 2013 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#define MAX 10000

int main(){
	char number[MAX], c;
	char sum[MAX];
	int i , n1, n2, s, r, inf, sup, size;
	gets(number);
	for(i = 0; i < MAX; i++)
		sum[i] = '0';
	size = strlen(number);
	while(1){
		if(strlen(number) == 1 && number[0] == '0')
			break;
		inf = 0;
		sup = strlen(number)-1;
		while(inf < sup){
			c = number[inf];
			number[inf] = number[sup];
			number[sup] = c;
			inf++;
			sup--;
		}
		r = 0;
		for(i = 0; i < strlen(number); i++){
			n1 = number[i] - '0';
			n2 = sum[i] - '0';
			s = n1 + n2 + r;

			if(s > 9){
				sum[i] = s%10 + '0';
				r = 1;
			}
			else{
				sum[i] = s + '0';
				r = 0;
			}
		}
		while(r){
			n1 = sum[i] - '0';
			s = n1 + r;
			if(s > 9){
				sum[i] = '0';
				r = 1;
			}
			else{
				sum[i] = s + '0';
				r = 0;
			}
			i++;
		}
		if(i > size){
			size = i;
		}
		gets(number);
	}
	sum[size] = '\0';
	for(i = size - 1; i >= 0; i--){
		printf("%c", sum[i]);
	}
	printf("\n");
	return 0;
}