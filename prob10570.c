//
//  prob10570.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 3/18/14.
//  Copyright (c) 2014 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>
#define MAX 9999

int numb[MAX];
int numb2[MAX];

void swap(int i, int j){
	int aux;
	aux = numb[i];
	numb[i] = numb[j];
	numb[j] = aux;
}

int min(int a, int b){
	if(a > b)
		return b;
	else 
		return a;
}

int main(){
	int n, i, flag, count, count2, k;
	scanf("%d", &n);
	while(n){
		for(i = 0; i < n; i++){
			scanf("%d", &numb[i]);
			numb2[i] = numb[i];
		}
		i = 1;
		count = 0;
		while(i){
			k = i;
			flag = 0;
			while(numb[k] != numb[i-1] + 1){
				k++;
				flag = 1;
				if(k == n){
					break;
				}
			}
			swap(k, i);
			if(flag)
				count++;
			i++;
			if(i == n-1){
				i = 0;
			}
		}
		i = 1;
		count2 = 0;
		while(i){
			k = i;
			flag = 0;
			while(numb2[k] != numb2[i-1] - 1){
				k++;
				flag = 1;
				if(k == n){
					break;
				}
			}
			swap(k, i);
			if(flag)
				count2++;
			i++;
			if(i == n-1){
				i = 0;
			}
		}
		printf("%d\n", min(count2, count));
		scanf("%d", &n);
	}
	return 0;
}