//
//  prob256.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 1/30/14.
//  Copyright (c) 2014 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>
#include <math.h>

int main(){
	int i, n1, n2, n;
	/*
	int res[10][1000], s[10];
	for(i = 0; i < 10; i++){
		s[i] = 0;
	}
	// for 2
	for(i = 0; i < 100; i++){
		n1 = i/10;
		n2 = i%10;
		if(pow(n1+n2,2) == i){
			res[2][s[2]++] = i;
		}
	}
	// for 4
	for(i = 0; i < 10000; i++){
		n1 = i/100;
		n2 = i%100;
		if(pow(n1+n2,2) == i){
			res[4][s[4]++] = i;
		}
	}
	// for 6
	for(i = 0; i < 1000000; i++){
		n1 = i/1000;
		n2 = i%1000;
		if(pow(n1+n2,2) == i){
			res[6][s[6]++] = i;
		}
	}
	// for 8
	for(i = 0; i < 100000000; i++){
		n1 = i/10000;
		n2 = i%10000;
		if(pow(n1+n2,2) == i){
			res[8][s[8]++] = i;
		}

	}
	*/
	while(scanf("%d", &n) != EOF){
		if(n == 2){
			printf("00\n01\n81\n");
		}
		else if(n == 4){
			printf("0000\n0001\n2025\n3025\n9801\n");
		}
		else if(n == 6){
			printf("000000\n000001\n088209\n494209\n998001\n");
		}
		else{
			printf("00000000\n00000001\n04941729\n07441984\n24502500\n25502500\n52881984\n60481729\n99980001\n");
		}
	}
	return 0;
}