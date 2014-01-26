//
//  prob113.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 12/29/13.
//  Copyright (c) 2013 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#define MAX 1000

typedef struct bigNumber{
	int value[MAX];
	int size;
} bigNumber;

int min(int a, int b){
	if(a < b){
		return a;
	}
	else{
		return b;
	}
}

int main(){
	int i, stop, n, size;
	double numb;
	char c;
	bigNumber p;
	while(1){
		i = 0;
		stop = 1;
		scanf("%d\n", &n);
		while(scanf("%c", &c) != EOF){
			if(c == '\n'){
				break;
			}
			else{
				p.value[i++] = c - '0';
			}
			stop = 0;
		}
		p.size = i;
		
		if(stop){
			break;
		}
		/*
		for(i = 0; i < p.size; i++){
			printf("%d", p.value[i]);
		}
		printf("\n");
		*/
		size = min(10, p.size);
		numb = 0;
		for(i = 0; i < size; i++){
			numb *= 10;
			numb += p.value[i];
			//printf("%f\n", numb);
		}
		numb = numb/pow(10, size-1);
		numb = log10(numb) + p.size-1;
		numb /= n;
		numb = pow(10, numb);
		printf("%.f\n", numb);
	}
	return 0;
}