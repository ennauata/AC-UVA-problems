//
//  prob10424.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 2/7/14.
//  Copyright (c) 2014 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#define MAX 999999

int main(){
	char name1[MAX], name2[MAX];
	int i, sum1, sum2, p1, p2;
	while(gets(name1)){
		gets(name2);
		//printf("%s\n", name1);
		//printf("%s\n", name2);
		sum1 = 0;
		for(i = 0; i < strlen(name1); i++){
			 if(name1[i] >= 'a' && name1[i] <= 'z'){
			 	sum1 += name1[i] - 'a' + 1;
			 }
			 else if(name1[i] >= 'A' && name1[i] <= 'Z'){
			 	sum1 += name1[i] - 'A' + 1;
			 }
		}
		p1 = sum1;
		while(p1/10 != 0){
			sum1 = p1;
			p1 = 0;
			while(sum1/10 != 0){
				p1 += sum1%10;
				sum1 /= 10;
			}
			p1 += sum1;
		}
		sum2 = 0;
		for(i = 0; i < strlen(name2); i++){
			 if(name2[i] >= 'a' && name2[i] <= 'z'){
			 	sum2 += name2[i] - 'a' + 1;
			 }
			 else if(name2[i] >= 'A' && name2[i] <= 'Z'){
			 	sum2 += name2[i] - 'A' + 1;
			 }
		}
		p2 = sum2;
		while(p2/10 != 0){
			sum2 = p2;
			p2 = 0;
			while(sum2/10 != 0){
				p2 += sum2%10;
				sum2 /= 10;
			}
			p2 += sum2;
		}
		if(p2 > p1){
			printf("%.2f %%\n", 100*(float)p1/p2);
		}
		else{
			printf("%.2f %%\n", 100*(float)p2/p1);
		}
	}
	return 0;
}