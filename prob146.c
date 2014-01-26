//
//  prob146.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 1/25/14.
//  Copyright (c) 2014 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>
#include <string.h>
int main(){
	char seq[60];
	int i, j, counting, map[26], k;
	while(scanf("%s", seq)){
		if(seq[0] == '#'){
			break;
		}
		else{
			counting = 0;
			j = 0;
			for(i = 0; i < 26; i++){
				map[i] = 0;
			}
			for(i = 0; i < strlen(seq)-1; i++){
				if(seq[i] < seq[i+1]){
					counting = 1;
					j = i;
					for(k = 0; k < 26; k++){
						map[k] = 0;
					}
				}
				map[seq[i] - 'a']++;
			}
			map[seq[i] - 'a']++;
			//printf("%d\n", j); 
			if(!counting){
				printf("No Successor\n");
			}
			else{
				//for(i = 0; i < 26; i++){
				//	printf("%d", map[i]);
				//}
				//printf("\n");
				for(i = 0; i < 26; i++){
					if(seq[j] < i + 'a' && map[i]){
						map[i]--;
						seq[j++] = i + 'a';
						break;
					}
				}
				for(i = 0; i < 26; i++){
					for(k = 0; k < map[i]; k++){
						seq[j++] = i + 'a';
					}
				}
				printf("%s\n", seq);
			}
			//printf("%s\n", seq);
		}
	}
	return 0;
}