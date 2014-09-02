//
//  prob686.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 4/10/14.
//  Copyright (c) 2014 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#define N 99999

int primes[N];
int size;
void crivo(long int n){
	int isPrime, p, j;
	primes[0] = 2;
	p = 3;
	size = 1;
	while(p <= sqrt(n)){
		j = 0;
		isPrime = 1;
		while((j < size)&&(primes[j] <= sqrt(p))){
			if(!(p%primes[j])){
				isPrime = 0;
			}
			j++;
		}
		if(isPrime){
			primes[size++] = p;
		}
		p += 2;
	}
}

int main(){
	int i, j, n, count;
	crivo(2000000000);
	while(scanf("%d", &n)){
		if(n == 0){
			break;
		}
		count = 0;
		for(i = 0; i < size; i++){
			if(primes[i] < n){
				for(j = i; j < size; j++){
					if(primes[i]+primes[j] == n){
						count++;
					}
					else if(primes[i]+primes[j] > n){
						break;
					}
				}
			}
			else{
				break;
			}
		}
		printf("%d\n", count);
	}
}