//
//  prob10235.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 3/4/14.
//  Copyright (c) 2014 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>
#include <math.h>

int primos[100000];
int hash[1000001];
int num;
int crivo(int max) {
    int i, j;
    int sim;
	for(i = 0; i < 1000001; i++){
		hash[i] = 0;
	}
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
			hash[i] = 1;
        }
    }
    return num;
}

int reverse(int num){
	int res = 0;
	while(num){
		res = 10*res + num%10;
		num /= 10;
	}
	return res;
}

int main(){
	int num, rev;
	crivo(1000000);
	while(scanf("%d", &num) != EOF){
		if(hash[num] == 0){
			printf("%d is not prime.\n", num);
		}
		else{
			rev = reverse(num);
			if((rev == num) || (hash[rev] == 0)){
				printf("%d is prime.\n", num);
			}
			else{
				printf("%d is emirp.\n", num);
			}
		}
	}
	return 0;
}