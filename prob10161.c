//
//  prob530.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 2/6/14.
//  Copyright (c) 2014 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>
#define MAX 99999
#define SUP 2100000000

int main(){
	int acc, next, n;
	scanf("%d", &n);
	while(n){
		next = 1;
		acc = 0;
		//printf("%d\n", n);
		while(next < SUP){
			next += acc;
			if(n == next){
				printf("%d %d\n", acc/2+1, acc/2+1);
				break;
			}
			else if((n >= next-acc/2)&&(n <= next+acc/2)){
				//printf("ACC %d NEXT %d\n", acc, next);
				//printf("ACC = %d\n", acc);
				if((acc/2)%2 == 0){
					if(n < next){
						printf("%d %d\n", acc/2+1, (acc/2+1)-(next-n));
					}
					else{
						printf("%d %d\n", (acc/2+1)-(n-next) , acc/2+1);
					}
				}
				else{
					if(n < next){
						printf("%d %d\n", (acc/2+1)-(next-n) , acc/2+1);
					}
					else{
						printf("%d %d\n", acc/2+1, (acc/2+1)-(n-next));
					}
				}
				break;
			}
			acc += 2;
			//printf("%d\n", next);
		}
		scanf("%d", &n);
	}
	return 0;
}