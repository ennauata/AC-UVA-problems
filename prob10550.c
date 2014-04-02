//
//  prob10550.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 3/3/14.
//  Copyright (c) 2014 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int main(){
	int n1, n2, n3, n4, total;
	scanf("%d %d %d %d", &n1, &n2, &n3, &n4);
	while(1){
		if(n1 == 0 && n2 == 0 && n3 == 0 && n4 == 0){
			break;
		}
		total = 0;
		if(n2-n1 > 0){
			total += (360-9*abs(n2-n1));	
		}
		else{
			total += 9*abs(n2-n1);
		}
		if(n3-n2 > 0){
			total += 9*abs(n3-n2);
		}
		else{
			total += (360-9*abs(n3-n2));
		}
		if(n4-n3 > 0){
			total += (360-9*abs(n4-n3));
		}
		else{
			total += 9*abs(n4-n3);
		}
		printf("%d\n", total+1080);
		scanf("%d %d %d %d", &n1, &n2, &n3, &n4);
	}
	return 0;
}