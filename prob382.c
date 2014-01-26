//
//  prob382.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 1/6/14.
//  Copyright (c) 2014 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>

int main(){
	int numb, i, sum;
	
	printf("PERFECTION OUTPUT\n");
	while(1){
		scanf("%d", &numb);
		if(!numb){
			break;
		}
		else{
			sum = 0;
			for(i = 1; i < numb; i++){
				if(numb%i == 0){
					sum += i;
				}
			}
			if(sum > numb){
				printf("%5d  ABUNDANT\n", numb);
			}
			else if(sum < numb){
				printf("%5d  DEFICIENT\n", numb);
			}
			else{
				printf("%5d  PERFECT\n", numb);
			}
			//printf("%d\n", sum);
		}
	}
	printf("END OF OUTPUT\n");
	return 0;
}