//
//  prob623.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 1/30/14.
//  Copyright (c) 2014 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#define MAX 2600

typedef struct bigNumber{
	int *value;
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
int matrix[MAX][MAX];
bigNumber multiply(bigNumber a, bigNumber b){
	int total, remain, inf, sup, aux, size;
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
	/*
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
	*/
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
	int numb, i, n, j, *value, **matrix;
	matrix = malloc(MAX*sizeof(int*));
	for(i = 0; i < MAX; i++){
		matrix[i] = malloc(MAX*sizeof(int));
	}
	bigNumber *vec, aux;
	vec = malloc(1010*sizeof(bigNumber));
	value = malloc(MAX*sizeof(int));
	aux.value = value;
	aux.value[0] = 1;
	aux.size = 1;
	vec[1] = aux;
	for(i = 1; i < 1000; i++){
		numb = i+1;
		aux.size = 0;
		while(numb){
			aux.value[aux.size++] = numb%10;
			numb /= 10;
			/*
			for(j = 0; j < aux.size; j++){
				printf("%d", aux.value[j]);
			}
			printf("\n");
			*/
		}
		vec[i+1] = multiply(vec[i], aux);
	}
	while(scanf("%d", &n) != EOF){
		printf("%d!\n", n);
		for(i = 0; i < vec[n].size; i++){
			printf("%d", vec[n].value[i]);
		}
		printf("\n");
	}
	return 0;
}
