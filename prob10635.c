//
//  prob10635.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 2/11/14.
//  Copyright (c) 2014 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>
#define MAX 99999

int CeilIndex(int v[], int inf, int sup, int val){
	int m;
	while(sup - inf > 1){
		m = (inf + sup)/2;
		if(v[m] >= val){
			sup = m;
		}
		else{
			inf = m;
		}
	}
	return sup;
}

int main(){
	int i, j, t, k, n, p, q, p_l[MAX], list[MAX], numb, tailTable[MAX], len;
	scanf("%d\n", &t);
	for(k = 0; k < t; k++){
		scanf("%d %d %d\n", &n, &p, &q);
		for(i = 0; i < n*n; i++){
			p_l[i] = -1;
		}
		for(i = 0; i < p+1; i++){
			scanf("%d", &numb);
			p_l[numb-1] = i;
		}
		j = 0;
		for(i = 0; i < q+1; i++){
			scanf("%d", &numb);
			if(p_l[numb-1] != -1){
				list[j++] = p_l[numb-1];
			}
		}
		printf("%d\n", j);
		for(i = 0; i < j; i++){
			printf("%d ", list[i]);
		}
		printf("\n");
		len = 1;
		tailTable[0] = list[0];
		for(i = 1; i < j; i++){
			if(list[i] < tailTable[0]){
				tailTable[0] = list[i];
			}
			else if(list[i] > tailTable[len-1]){
				tailTable[len++] = list[i];
			}
			else{
				tailTable[CeilIndex(tailTable, -1, len-1, list[i])] = list[i];
			}
		}
		printf("Case %d: %d\n", k+1, len);
	}
	return 0;
}