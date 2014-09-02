//
//  prob10033.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 5/28/14.
//  Copyright (c) 2014 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int main(){
	int t;
	char comm[10000][5], buffer[10], *exit;
	int regs[10];
	int op, r1, r2, i, pc, k, j, stop, aux;
	scanf("%d\n", &t);
	k = 0;
	while(t){
		exit = gets(buffer);
		//printf("%lu\n", strlen(buffer));
		if(strlen(buffer) >= 3 && exit != NULL){
			strcpy(comm[k], buffer);
			//printf("%s\n", comm[k]);
			k++;
		}
		else{
			for(i = 0; i < 10; i++){
				regs[i] = 0;
			}
			pc = 0;
			r1 = 0;
			r2 = 0;
			stop = 0;
			//printf("%d\n", k);
			// executa
			i = 0;
			while(1){
				//printf("%s\n", comm[i]);
				op = comm[i][0] - '0';
				r1 = comm[i][1] - '0';
				r2 = comm[i][2] - '0';
				pc++;
				switch(op){
		
					case 1:
						stop = 1;
					break;
					
					case 2:
						regs[r1] = r2;
					break;
					
					case 3:
						regs[r1] = (regs[r1]+r2)%1000;
					break;
					
					case 4:
						regs[r1] = (regs[r1]*r2)%1000;
					break;
					
					case 5:
						regs[r1] = regs[r2];
					break;
					
					case 6:
						regs[r1] = (regs[r1]+regs[r2])%1000;
					break;
					
					case 7:
						regs[r1] = (regs[r1]*regs[r2])%1000;
					break;
					
					case 8:
					
						regs[r1] = 0;
						
						regs[r1] += comm[regs[r2]][0] - '0';
						regs[r1] *= 10;
						
						regs[r1] += comm[regs[r2]][1] - '0';
						regs[r1] *= 10;
						
						regs[r1] += comm[regs[r2]][2] - '0';
					
					break;
					
					case 9:
						aux = regs[r1];
						
						comm[regs[r2]][2] = aux%10 + '0';
						aux /= 10;
						
						comm[regs[r2]][1] = aux%10 + '0';
						aux /= 10;
						
						comm[regs[r2]][0] = aux%10 + '0';
						
					break;
					
					case 0:
					if(regs[r2]){
						i = regs[r1]-1;
					}
					break;
				}
				if(stop){
					break;
				}
				//printf("*************\n");
				//for(j = 0; j < 10; j++){
				//	printf("%d\n", regs[j]);
				//}
				//printf("*************\n");
				i++;
			}
			// decrementa
			t--;
			k = 0;
			printf("%d\n", pc);
			if(t){
				printf("\n");
			}
		}
	}
	return 0;
}