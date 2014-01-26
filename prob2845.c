//
//  prob2845.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 11/20/13.
//  Copyright (c) 2013 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>
#define MAX 20000000
#include <stdlib.h>

int a_sequence(int *vector, int size, int *res, int *vecAux){
	int n = 1, i, j, aux, n_aux = 0, k;
	
	res[0] = vector[0];
	for(i = 1; i < size; i++){
		aux = n;
		for(j = 0; j < aux; j++){
			vecAux[n_aux] = res[n] = res[j] + vector[i]; 
			n++;
			n_aux++;
		}
		for(k = 0; k < n_aux; k++){
			if(i < size - 1 && vecAux[k] == vector[i+1]){
				return -1;
			}
		}
		res[n++] = vector[i];
	}
	return n_aux;
}
int main(){
	int d, i, a, end, n = 0, t = 0;
	int *vector;
	int *res;
	int *vecAux;
	
	vecAux = malloc(MAX*sizeof(int));
	end = scanf("%d", &d);
	vector = malloc(30*sizeof(int));
	res = malloc(MAX*sizeof(int));
	while(end != EOF){
		t++;
		for(i = 0; i < d; i++){
			scanf("%d", &a);
			vector[i] = a;
		}
		
		n = a_sequence(vector, d, res, vecAux);
		
		printf("Case #%d:", t);
		printf(" %d", vector[0]);
		for(i = 1; i < d; i++){
			printf(" %d", vector[i]);
			if(vector[i-1] >= vector[i]){
				n = -1;
			}
		}
		if(n>=0){
			printf("\nThis is an A-sequence.\n");
		}
		else{
			printf("\nThis is not an A-sequence.\n");
		}
		
		end = scanf("%d", &d);
	}
}