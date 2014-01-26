//
//  10344.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 12/16/13.
//  Copyright (c) 2013 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>

typedef struct{
	int value;
	int used;
} node;

int brute_force_op(int *sequence, int total, int next, int *possible){
	int i;
	if(next < 5){
		for(i = 0; i < 3; i++){
			if(i == 0){
				brute_force_op(sequence, total + sequence[next], next+1, possible);
			}
			else if(i == 1){ 
				brute_force_op(sequence, total - sequence[next], next+1, possible);
			}
			else{
				brute_force_op(sequence, total * sequence[next], next+1, possible);
			}
		}
	}
	else if(next == 5){
		printf("%d\n", total);
		if(total == 23){
			*possible = 1;
			return 1;
		}
	}
	return 0;
}

void brute_force_numb(node *input, int *sequence, int recLev, int *possible){
	int i;
	if(!(*possible)){
		for(i = 0; i < 5; i++){
			if(!input[i].used){
				input[i].used = 1;
				sequence[recLev] = input[i].value;
				brute_force_numb(input, sequence, recLev + 1, possible);
				input[i].used = 0;
			}
		}
		brute_force_op(sequence, sequence[0], 1, possible);
	}
}


int main(){
	node input[5];
	int i, numb, sequence[5], possible, stop;
	stop = 0;
	for(i = 0; i < 5; i++){
		scanf("%d", &numb);
		input[i].value = numb;
		input[i].used = 0;
		if(numb == 0){
			stop++;
		}
	}
	while(stop != 5){
		possible = 0;
		brute_force_numb(input, sequence, 0, &possible);
		if(possible){
			printf("Possible\n");
		}
		else{
			printf("Impossible\n");
		}
		stop = 0;
		for(i = 0; i < 5; i++){
			scanf("%d", &numb);
			input[i].value = numb;
			input[i].used = 0;
			if(numb == 0){
				stop++;
			}
		}
	}
	return 0;
}
