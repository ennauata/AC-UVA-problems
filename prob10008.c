//
//  prob10008.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 1/2/14.
//  Copyright (c) 2014 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int qnty;
	char key;
} node;

typedef int (*compfn)(const void*, const void*);

int compare(node *elem1, node *elem2)
{
   if ( elem1->qnty < elem2->qnty)
      return -1;

   else if (elem1->qnty > elem2->qnty)
      return 1;

   else{
	  if(elem1->key > elem2->key){
	  	return -1;
	  }
	  else{
	  	return 1;
	  }
	}
}

int main(){
	int i, n, j;
	char c;
	node table[26];
	for(j = 0, c = 'A'; j < 26; j++, c++){
		table[j].qnty = 0;
		table[j].key = c;
		//printf("%c\n", c);
	}
	scanf("%d\n", &n);
	for(i = 0; i < n; i++){
		while(scanf("%c", &c)){
			if(c == '\n'){
				break;
			}
			if(c <= 'Z' && c >= 'A'){
				table[c - 'A'].qnty++;
			}	
			if(c <= 'z' && c >= 'a'){
				table[c - 'a'].qnty++;
			}
		}
	}
	qsort((void *) &table, 26, sizeof(node), (compfn)compare);  
	for(j = 25; j >= 0; j--){
		if(table[j].qnty > 0){
			printf("%c %d\n", table[j].key, table[j].qnty);
		}
	}
	return 0;
}