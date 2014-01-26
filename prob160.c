//
//  prob160.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 1/15/14.
//  Copyright (c) 2014 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>
#include <math.h>

int primos[100000];
int num;

void crivo(int max) {
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
        }
    }
}

int main(){
	int n, i, j, k;
	int res[100];
	crivo(100);
	scanf("%d", &n);
	while(n){
		for(i = 0; i < num; i++){
			res[i] = 0;
		}
		for(i = 2; i <= n; i++){
			for(j = 0; j < num && primos[j] <= i; j++){
				k = i;
				while(k%primos[j] == 0){
					k /= primos[j];
					res[j]++;
				}
			}
		}
		printf("%3d! =", n);
		for(i = 0; i < num; i++){
			if(res[i] != 0){
				if(i == 15){
					printf("\n      ");
				}
				printf("%3d", res[i]);
			}
			else{
				break;
			}
		}
		printf("\n");
		scanf("%d", &n);
	}
	return 0;
}