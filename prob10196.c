//
//  prob10196.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 5/30/14.
//  Copyright (c) 2014 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>

char chess[15][15];
	
int searchVertical(int i, int j, char c){
	int k;
	for(k = 1; k + i < 8; k++){\
		if(chess[i+k][j] == c){
			return 1;
		}
		else if(chess[i+k][j] != '.'){
			break;
		}
	}
	for(k = 1; i - k >= 0; k++){
		if(chess[i-k][j] == c){
			return 1;
		}
		else if(chess[i-k][j] != '.'){
			break;
		}
	}
	return 0;
}

int searchHorizontal(int i, int j, char c){
	int l;
	for(l = 1; l + j < 8; l++){
		if(chess[i][l+j] == c){
			return 1;
		}
		else if(chess[i][l+j] != '.'){
			break;
		}
	}
	for(l = 1; j - l >= 0; l++){
		if(chess[i][j-l] == c){
			return 1;
		}
		else if(chess[i][j-l] != '.'){
			break;
		}
	}
	return 0;
}

int searchPrimaryDiagonal(int i, int j, char c){
	int k, l;
	for(k = 1, l = 1; k + i < 8 && j + l < 8; k++, l++){
		if(chess[i+k][j+l] == c){
			return 1;
		}
		else if(chess[i+k][j+l] != '.'){
			break;
		}
	}
	for(k = 1, l = 1; i - k >= 0 && j - l >= 0; k++, l++){
		if(chess[i-k][j-l] == c){
			return 1;
		}
		else if(chess[i-k][j-l] != '.'){
			break;
		}
	}
	return 0;
}

int searchSecondaryDiagonal(int i, int j, char c){
	int k, l;
	for(k = 1, l = 1; i + k < 8 && j - l >= 0; k++, l++){
		if(chess[i+k][j-l] == c){
			return 1;
		}
		else if(chess[i+k][j-l] != '.'){
			break;
		}
	}
	for(k = 1, l = 1; i - k >= 0 && j + l < 8; k++, l++){
		if(chess[i-k][j+l] == c){
			return 1;
		}
		else if(chess[i-k][j+l] != '.'){
			break;
		}
	}
	return 0;
}
							
int main(){
	int n_i_step[2] = {1, -1}, n_j_step[2] = {2, -2}, found, f1, f2, f3, f4;
	int i, j, k, l, stop, t, flag;
	t = 0;
	flag = 1;
	while(1){
		for(i = 0; i < 8; i++){
			scanf("%s", chess[i]);
		}
		stop = 1;
		for(i = 0; i < 8; i++){
			//printf("%s\n", chess[i]);
			for(j = 0; j < 8; j++){
				found = 0;
				if(chess[i][j] != '.'){
					if(flag){
						printf("Game #%d: ", ++t);
						flag = 0;
					}
					//printf("%c\n", chess[i][j]);
					stop = 0;
					switch(chess[i][j]){
						case 'k':
							for(k = -1; k < 1; k++){
								if(i+k < 8 && i+k >= 0){
									for(l = -1; l < 1; l++){
										if(j+l < 8 && j+l >= 0){
											if(chess[i+k][j+l] == 'K'){
												printf("white king is in check.\n");
												found  = 1;
											}
										}	
									}
								}
							}
						break;
			
						case 'K':
							for(k = -1; k < 1; k++){
								if(i+k < 8 && i+k >= 0){
									for(l = -1; l < 1; l++){
										if(j+l < 8 && j+l >= 0){
											if(chess[i+k][j+l] == 'k'){
												printf("black king is in check.\n");
												found = 1;
											}
										}	
									}
								}
							}
						break;
						
						case 'n':
							for(k = 0; k < 2; k++){
								if(i + n_i_step[k] < 8 && i + n_i_step[k] >= 0){
									for(l = 0; l < 2; l++){
										if(j + n_j_step[l] < 8 && j + n_j_step[l] >= 0){
											if(chess[i+n_i_step[k]][j+n_j_step[l]] == 'K'){
												printf("white king is in check.\n");
												found = 1;
											}
										}
									}
								}
							}
							for(k = 0; k < 2; k++){
								if(i + n_j_step[k] < 8 && i + n_j_step[k] >= 0){
									for(l = 0; l < 2; l++){
										if(j + n_i_step[l] < 8 && j + n_i_step[l] >= 0){
											if(chess[i+n_j_step[k]][j+n_i_step[l]] == 'K'){
												printf("white king is in check.\n");
												found = 1;
											}
										}
									}
								}
							}
						break;
						
						case 'N':
							for(k = 0; k < 2; k++){
								if(i + n_i_step[k] < 8 && i + n_i_step[k] >= 0){
									for(l = 0; l < 2; l++){
										if(j + n_j_step[l] < 8 && j + n_j_step[l] >= 0){
											if(chess[i+n_i_step[k]][j+n_j_step[l]] == 'k'){
												printf("black king is in check.\n");
												found = 1;
											}

										}
									}
								}
							}
							for(k = 0; k < 2; k++){
								if(i + n_j_step[k] < 8 && i + n_j_step[k] >= 0){
									for(l = 0; l < 2; l++){
										if(j + n_i_step[l] < 8 && j + n_i_step[l] >= 0){
											if(chess[i+n_j_step[k]][j+n_i_step[l]] == 'k'){
												printf("black king is in check.\n");
												found = 1;
											}

										}
									}
								}
							}
						break;
						
						case 'q':
							f1 = searchVertical(i, j, 'K');
							f2 = searchHorizontal(i, j, 'K');
							f3 = searchPrimaryDiagonal(i, j, 'K');
							f4 = searchSecondaryDiagonal(i, j, 'K');
							if(f1 || f2 || f3 || f4){
								printf("white king is in check.\n");
								found = 1;
							}
						break;
						
						case 'Q':
							f1 = searchVertical(i, j, 'k');
							f2 = searchHorizontal(i, j, 'k');
							f3 = searchPrimaryDiagonal(i, j, 'k');
							f4 = searchSecondaryDiagonal(i, j, 'k');
							if(f1 || f2 || f3 || f4){
								printf("black king is in check.\n");
								found = 1;
							}
						break;
						
						case 'b':
							f1 = searchPrimaryDiagonal(i, j, 'K');
							f2 = searchSecondaryDiagonal(i, j, 'K');
							if(f1 || f2){
								printf("white king is in check.\n");
								found = 1;
							}
						break;
						
						case 'B':
							f1 = searchPrimaryDiagonal(i, j, 'k');
							f2 = searchSecondaryDiagonal(i, j, 'k');
							if(f1 || f2){
								printf("black king is in check.\n");
								found = 1;
							}
						break;
						
						case 'r':
							f1 = searchVertical(i, j, 'K');
							f2 = searchHorizontal(i, j, 'K');
							if(f1 || f2){
								printf("white king is in check.\n");
								found = 1;
							}
						break;
						
						case 'R':
							f1 = searchVertical(i, j, 'k');
							f2 = searchHorizontal(i, j, 'k');
							if(f1 || f2){
								printf("black king is in check.\n");
								found = 1;
							}
						break;
						
						case 'p':
							if(i + 1 < 8 && j + 1 < 8){
								if(chess[i+1][j+1] == 'K'){
									printf("white king is in check.\n");
									found = 1;
								}
							}
							if(found){
								break;
							}
							if(i + 1 < 8 && j - 1 >= 0){
								if(chess[i+1][j-1] == 'K'){
									printf("white king is in check.\n");
									found = 1;
								}
							}
						break;
						
						case 'P':
							if(i - 1 >= 0 && j + 1 < 8){
								if(chess[i-1][j+1] == 'k'){
									printf("black king is in check.\n");
									found = 1;
								}
							}
							if(found){
								break;
							}
							if(i - 1 >= 0 && j - 1 >= 0){
								if(chess[i-1][j-1] == 'k'){
									printf("black king is in check.\n");
									found = 1;
								}
							}
						break;
					}
					if(found){
						break;
					}
				}
			}
			if(found){
				break;
			}
		}
		if(stop){
			return 0;
		}
		if(!found){
			printf("no king is in check.\n");
		}
		flag = 1;
		//printf("\n");
	}
	return 0;
}