//
//  prob495.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 1/19/14.
//  Copyright (c) 2014 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#define MAX 1300

char memo[5500][MAX] = {'\0'};
char res[MAX];

int max(int a, int b, int c){
	int max;
	if(a > b){
		max = a;
	}
	else{
		max = b;
	}
	if(max > c){
		return max;
	}
	else{
		return c;
	}
}

void sum(char sum[MAX], char number[MAX]){
	int i , n1, n2, s, r, k, sum_size;
	
	//printf("%s\n", sum);
	//printf("%s\n", number);
	r = 0;
	sum_size = strlen(sum);
	strcpy(res, sum);
	for(i = 0; i < strlen(number); i++){
		if(i >= sum_size){
			n1 = number[i] - '0';
			s = n1 + r;
		}
		else{
			n1 = number[i] - '0';
			n2 = sum[i] - '0';
			s = n1 + n2 + r;
		}
		if(s > 9){
			res[i] = s%10 + '0';
			r = 1;
		}
		else{
			res[i] = s + '0';
			r = 0;
		}
	}
	while(r){
		if(i >= sum_size){
			s = r;
		}
		else{
			n1 = sum[i] - '0';
			s = n1 + r;
		}
		//printf("%d\n", n1);
		if(s > 9){
			res[i] = '0';
			r = 1;
		}
		else{
			res[i] = s + '0';
			r = 0;
		}
		i++;
	}
	k = max(i, strlen(number), sum_size);
	sum[k] = '\0';
	//printf("%d\n", k);
	//printf("%d\n", size);
	//printf("%s\n", sum);
}

int main(){
	int n, i;
	memo[0][0] = '0';
	memo[0][1] = '\0';
	memo[1][0] = '1';
	memo[1][1] = '\0';
	for(i = 2; i <= 5000; i++){
		sum(memo[i-1], memo[i-2]);
		strcpy(memo[i], res);
		//printf("%s\n", memo[i]);
	}
	while(scanf("%d", &n) != EOF){
		if(n == 0){
			printf("The Fibonacci number for %d is 0\n", n);
		}
		else if(n == 1){
			printf("The Fibonacci number for %d is 1\n", n);
		}
		else{
			//fibonacci(n);
			printf("The Fibonacci number for %d is ", n);
			for(i = strlen(memo[n])-1; i >= 0; i--){
				printf("%c", memo[n][i]);
			}
			printf("\n");
		}
	}
	//sum(str1, str2);
	//printf("%s\n", res);
	return 0;
}