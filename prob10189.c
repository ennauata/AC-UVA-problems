//
//  prob10189.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 12/28/13.
//  Copyright (c) 2013 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>

int main(){
	int rows, cols, i, j, k, l, count, t = 1;
	char map[200][200];
	scanf("%d %d\n", &rows, &cols);
	while(rows && cols){
		for(i = 0; i < rows; i++){
			for(j = 0; j < cols; j++){
				scanf("%c", &map[i][j]);
			}
			scanf("\n");
		}
		/*
		for(i = 0; i < rows; i++){
			for(j = 0; j < cols; j++){
				printf("%c", map[i][j]);
			}
			printf("\n");
		}*/
		for(i = 0; i < rows; i++){
			for(j = 0; j < cols; j++){
				if(map[i][j] == '.'){
					count = 0;
					for(k = -1; k <= 1; k++){
						if(k + i >= 0 && k + i < rows){
							for(l = -1; l <= 1; l++){
								if(l + j >= 0 && l + j < cols){
									if(map[k+i][l+j] == '*'){
										count++;
									}
								}
							}
						}
					}
					map[i][j] = count + '0';
				}
			}
		}
		printf("Field #%d:\n", t++);
		for(i = 0; i < rows; i++){
			for(j = 0; j < cols; j++){
				printf("%c", map[i][j]);
			}
			printf("\n");
		}
		scanf("%d %d\n", &rows, &cols);
		if(rows || cols){
			printf("\n");
		}
	}
	return 0;
}