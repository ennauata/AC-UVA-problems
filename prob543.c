//
//  prob543.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 1/15/14.
//  Copyright (c) 2014 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int primos[100000];
int is_prime[1000000];
int num;

int crivo(int max) {
    int i, j;
    int sim;

    primos[0] = 2;
    num = 1;

    for (i = 3; i <= max; i+=2) {
        sim = 1;
        for (j = 0; primos[j] <= sqrt(i); j++) {
            if (i % primos[j] == 0) {
                sim = 0;
                break;
            }
        }
        if (sim == 1) {
            primos[num++] = i;
			is_prime[i] = 1;
        }
    }
    return num;
}

int main(void) {
    int n, prime1, prime2, size;
    int aux;
    int i, diff;
	
	for(i = 0; i < 1000000; i++){
		is_prime[i] = 0;
	}
    size = crivo(1000000);
	//printf("%d\n", size);
	scanf("%d", &n);
	while(n){
		diff = -1;
		for(i = 0; primos[i] <= n/2 && i < size; i++){
			aux = n - primos[i];
			if(is_prime[aux] && abs(primos[i] - aux) > diff){
				diff = abs(primos[i] - aux);
				prime1 = primos[i];
				prime2 = aux;
			}
					}
		printf("%d = %d + %d\n", n, prime1, prime2);
		scanf("%d", &n);
	}
	return 0;
}
