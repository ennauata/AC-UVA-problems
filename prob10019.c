//
//  prob10019.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 1/26/14.
//  Copyright (c) 2014 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>

int count(int numb){
	int ones = 0;
	while(numb){
		numb &= numb-1;
		ones++;
	}
	return ones;
}

int toDec(int numb){
	int base = 1, res = 0;
	while(numb){
		res += base*(numb%10);
		numb /= 10;
		base *= 16;
	}
	return res;
}

int main(){
	int n, b1, b2, dec, t, i;
	scanf("%d", &t);
	for(i = 0; i < t; i++){
		scanf("%d", &n);
		b1 = count(n);
		dec = toDec(n);
		b2 = count(dec);
		printf("%d %d\n", b1, b2);
	}
	return 0;
}