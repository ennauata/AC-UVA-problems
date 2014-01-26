//
//  prob113.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 12/29/13.
//  Copyright (c) 2013 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>
#define MAX 1000

typedef struct bigNumber{
	int value[MAX];
	int size;
} bigNumber;

int max(int a, int b){
	if(a > b){
		return a;
	}
	else{
		return b;
	}
}
bigNumber multiply(bigNumber a, bigNumber b){
	int matrix[MAX][MAX], total, remain, inf, sup, aux, size;
	bigNumber res;
	int i, j;
	
	// Zero
	for(i = 0; i < MAX; i++){
		for(j = 0; j < MAX; j++){
			matrix[i][j] = 0;
		}
	}

	// Reverse 
	inf = 0;
	sup = a.size - 1;
	while(inf < sup){
		aux = a.value[inf];
		a.value[inf] = a.value[sup];
		a.value[sup] = aux;
		inf++;
		sup--;
	}
	/*
	for(i = 0; i < a.size; i++){
		printf("%d", a.value[i]);
	}
	printf("\n");
	*/
	// Reverse 
	inf = 0;
	sup = b.size - 1;
	while(inf < sup){
		aux = b.value[inf];
		b.value[inf] = b.value[sup];
		b.value[sup] = aux;
		inf++;
		sup--;
	}
	/*
	for(i = 0; i < b.size; i++){
		printf("%d", b.value[i]);
	}
	printf("\n");
	*/
	
	size = (b.size-1)+a.size;	
	for(i = 0; i < b.size; i++){
		remain = 0;
		for(j = 0; j < a.size; j++){
			total = a.value[j]*b.value[i] + remain;
			if(total > 9){
				remain = total/10;
				total = total%10;
			}
			else{
				remain = 0;
			}
			matrix[i][j+i] = total;
		}
		if(remain > 0){
			matrix[i][j+i] = remain;
			if(i == b.size-1 && j== a.size){
				size++;
			}
		}
	}
	/*
	for(i = 0; i < b.size; i ++){
		for(j = 0; j < size; j++){
			printf("%d", matrix[i][j]);
		}
		printf("\n");
	}
	*/
	remain = 0;
	res.size = 0;
	
	for(j = 0; j < size; j++){
		total = 0;
		for(i = 0; i < b.size; i++){
			total += matrix[i][j]; 
		}
		total += remain;
		if(total > 9){
			remain = total/10;
			total = total%10;
		}
		else{
			remain = 0;
		}
		res.value[j] = total;
		res.size++; 
	}
	if(remain > 0){
		res.value[j] = remain;
		res.size++; 
	}
	
	// Reverse 
	inf = 0;
	sup = res.size - 1;
	while(inf < sup){
		aux = res.value[inf];
		res.value[inf] = res.value[sup];
		res.value[sup] = aux;
		inf++;
		sup--;
	}
	
	return res;
}

int main(){
	int i, stop, zero;
	char c;
	bigNumber res, a, b;
	while(1){
		stop = 1;
		i = 0;
		// Read 
		while(scanf("%c", &c) != EOF){
			if(c == '\n'){
				break;
			}
			else{
				a.value[i++] = c - '0';
			}
			stop = 0;
		}
		a.size = i;
		
		// Read
		i = 0;
		while(scanf("%c", &c) != EOF){
			if(c == '\n'){
				break;
			}
			else{
				b.value[i++] = c - '0';
			}
			stop = 0;
		}
		b.size = i;
		
		if(stop){
			break;
		}
		else{
			res = multiply(a, b);
			zero = 1;
			for(i = 0; i < res.size; i++){
				if(res.value[i] != 0){
					zero = 0;
				}
			}
			if(zero){
				res.size = 1;
			}
			for(i = 0; i < res.size; i++){
				printf("%d", res.value[i]);
			}
			printf("\n");
		}
	}
	return 0;
}