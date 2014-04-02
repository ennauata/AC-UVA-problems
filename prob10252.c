//
//  prob10252.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 3/4/14.
//  Copyright (c) 2014 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare (const void * a, const void * b)
{
  return ( *(char*)a - *(char*)b );
}

int main(){
	char a[2000], b[2000], buffer[2000];
	int mark[2000], i, j, k;
	while(gets(a)){
		gets(b);
		for(i = 0; i < strlen(b); i++){
			mark[i] = 0;
		}
		k = 0;
		for(i = 0; i < strlen(a); i++){
			for(j = 0; j < strlen(b); j++){
				if((a[i] == b[j])&&(mark[j] == 0)){
					mark[j] = 1;
					buffer[k++] = a[i];
					break;	
				}
			}
		}
		qsort (buffer, k, sizeof(char), compare);
		for(i = 0; i < k; i++){
			printf("%c", buffer[i]);
		}
		printf("\n");
	}
	return 0;
}