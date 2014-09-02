//
//  prob706.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 5/21/14.
//  Copyright (c) 2014 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#define MAX 200

char vec[8];
int buffer[50][MAX];
int s;

void clearBuffer(){
	int i, j;
	for(i = 0; i < 50; i++){
		for(j = 0; j < MAX; j++){
			buffer[i][j] = 0;
		}
	}
}

void printHorizontalLine(int s_i, int s_j){
	int i;
	for(i = 0; i < s; i++){
		buffer[s_i][s_j+i] = 1;
	}
}

void printVerticalLine(int s_i, int s_j){
	int i;
	for(i = 0; i < s; i++){
		buffer[s_i+i][s_j] = -1;
	}
}

int main(){
	int i, j, shift, map[7], k;
	scanf("%d", &s);
	while(s){
		scanf("%s", vec);
		clearBuffer();
		shift = 0;
		for(k = 0; k < strlen(vec); k++){
			for(i = 0; i < 7; i++){
				map[i] = 0;
			}
			switch(vec[k]){
				case '1':
					map[2] = 1;
					map[5] = 1;
					break;
				case '2':
					map[0] = 1;
					map[2] = 1;
					map[3] = 1;
					map[4] = 1;
					map[6] = 1;
					break;
				case '3':
					map[0] = 1;
					map[2] = 1;
					map[3] = 1;
					map[5] = 1;
					map[6] = 1;
					break;
				case '4':
					map[1] = 1;
					map[2] = 1;
					map[3] = 1;
					map[5] = 1;
					break;
				case '5':
					map[0] = 1;
					map[1] = 1;
					map[3] = 1;
					map[5] = 1;
					map[6] = 1;
					break;
				case '6':
					map[0] = 1;
					map[1] = 1;
					map[3] = 1;
					map[4] = 1;
					map[5] = 1;
					map[6] = 1;
					break;
				case '7':
					map[0] = 1;
					map[2] = 1;
					map[5] = 1;
					break;
				case '8':
					map[0] = 1;
					map[1] = 1;
					map[2] = 1;
					map[3] = 1;
					map[4] = 1;
					map[5] = 1;
					map[6] = 1;
					break;
				case '9':
					map[0] = 1;
					map[1] = 1;
					map[2] = 1;
					map[3] = 1;
					map[5] = 1;
					map[6] = 1;
					break;
				case '0':
					map[0] = 1;
					map[1] = 1;
					map[2] = 1;
					map[4] = 1;
					map[5] = 1;
					map[6] = 1;
					break;
			}
			for(i = 0; i < 7; i++){
				if(map[i]){
					if(i == 0){
						printHorizontalLine(0, shift+1);
					}
					else if(i == 1){
						printVerticalLine(1, shift);
					}
					else if(i == 2){
						printVerticalLine(1, shift+s+1);
					}
					else if(i == 3){
						printHorizontalLine(s+1, shift+1);
					}
					else if(i == 4){
						printVerticalLine(s+2, shift);
					}
					else if(i == 5){
						printVerticalLine(s+2, shift+s+1);
					}
					else if(i == 6){
						printHorizontalLine(2*s+2, shift+1);
					}
				}
			}
			shift += (s+3);
		}
		for(i = 0; i < 2*s+3; i++){
			for(j = 0; j < shift-1; j++){
				if(buffer[i][j] == 0){
					printf(" ");
				}
				else if(buffer[i][j] == -1){
					printf("|");
				}
				else if(buffer[i][j] == 1){
					printf("-");
				}
			}
			printf("\n");
		}
		printf("\n");
		scanf("%d", &s);
	}
	return 0;
}