//
//  prob10142.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 6/1/14.
//  Copyright (c) 2014 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>
#include <string.h>

typedef struct stack{
	int val[30], size;
} stack;
int eliminated, votes[30], el_map[30], n, k, max, min, total;
char candidates[30][200], buffer[200];
stack stacks[1100];

void init(int i){
	stacks[i].size = 0;
}

void push(int i, int n){
	stacks[i].val[stacks[i].size++] = n;
}

int top(int l){
	int i;
	for(i = 0; i < n; i++){
		if(!el_map[stacks[l].val[i]]){
			return stacks[l].val[i];
		}
	}
	return -1;
}

int main(){
	int t, i, j, num, stop, br;
	scanf("%d\n", &t);
	while(t--){
		scanf("%d\n", &n);
		for(i = 0; i < n; i++){
			gets(candidates[i]);
			el_map[i] = 0;
		}
		for(i = 0; i < k; i++){
			init(i);
		}
		k = 0;
		while(gets(buffer)){
			if(strlen(buffer) > 0){
				//printf("%s\n", buffer);
				i = 0;
				num = 0;
				j = 0;
				br = 0;
				while(i < n){
					if(buffer[j] <= '9' && buffer[j] >= '0'){
						num *= 10;
						num += buffer[j] - '0';
						br = 1;
					}
					else {
						if(br){
							push(k, num-1);
							i++;
							num = 0;
							br = 0;
						}
					}
					j++;
				}
				//push(k, num-1);
				k++;
			}
			else{
				break;
			}
		}
		//for(i = 0; i < k; i++){
		//	for(j = 0; j < n; j++){
		//		printf("%d ", stacks[i].val[j]);
		//	}
		//	printf("\n");
		//}
		while(1){
			for(i = 0; i < n; i++){
				votes[i] = 0;
			}
			for(i = 0; i < k; i++){
				if(top(i) >= 0){
					votes[top(i)]++;
				}
			}
			min = 2000;
			max = -1;
			total = 0;
			for(i = 0; i < n; i++){
				if(votes[i] < min && !el_map[i]){
					min = votes[i];
				}
				if(votes[i] > max && !el_map[i]){
					max = votes[i];
				}
				if(!el_map[i]){
					total += votes[i];
				}
			}
			//for(i = 0; i < n; i++){
			//	printf("%d ", el_map[i]);
			//}
			//printf("\n");
			//printf("%d %d %d\n", min, max, total);
			if(2*max > total || min == max){
				for(i = 0; i < n; i++){
					if(votes[i] == max && !el_map[i]){
						printf("%s\n", candidates[i]);
					}
				}
				break;
			}
			for(i = 0; i < n; i++){
				if(votes[i] == min){
					//printf("%d\n", i);
					el_map[i] = 1;
				}
			}
			stop = 1;
			for(i = 0; i < n; i++){
				if(!el_map[i]){
					stop = 0;
				}
			}
			if(stop){
				break;
			}
		}
		if(t){
			printf("\n");
		}
	}
	return 0;
}