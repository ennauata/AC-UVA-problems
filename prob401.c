//
//  prob401.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 11/28/13.
//  Copyright (c) 2013 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>
#include <string.h>

char reverse(char c){
	char reverse;
	switch(c){
		case 'A':
			reverse = 'A';
			break;
		case 'E':
			reverse = '3';
			break;
		case 'H':
			reverse = 'H';
			break;
		case 'I':
			reverse = 'I';
			break;
		case 'J':
			reverse = 'L';
			break;
		case 'L':
			reverse = 'J';
			break;
		case 'M':
			reverse = 'M';
			break;
		case 'O':
			reverse = 'O';
			break;
		case 'S':
			reverse = '2';
			break;
		case 'T':
			reverse = 'T';
			break;
		case 'U':
			reverse = 'U';
			break;
		case 'V':
			reverse = 'V';
			break;
		case 'W':
			reverse = 'W';
			break;
		case 'X':
			reverse = 'X';
			break;
		case 'Y':
			reverse = 'Y';
			break;
		case 'Z':
			reverse = '5';
			break;
		case '1':
			reverse = '1';
			break;
		case '2':
			reverse = 'S';
			break;
		case '3':
			reverse = 'E';
			break;
		case '5':
			reverse = 'Z';
			break;
		case '8':
			reverse = '8';
			break;
		default:
			reverse = '*';
			break;
	}
	return reverse;
}

int main(){
	char word[1000];
	int inf, sup, is_palindrome, is_mirrored;
	while(scanf("%s", word) != EOF){
		inf = 0;
		sup = (int)strlen(word) - 1;
		is_palindrome = 1;
		is_mirrored = 1;
		while(inf <= sup){
			if(word[inf] != word[sup]){
				is_palindrome = 0;
			}
			if(word[inf] != reverse(word[sup])){
				is_mirrored = 0;
			}
			inf++;
			sup--;
		}
		if(is_palindrome && is_mirrored){
			printf("%s -- is a mirrored palindrome.\n\n", word);
		}
		else if(is_palindrome){
			printf("%s -- is a regular palindrome.\n\n", word);
		}
		else if(is_mirrored){
			printf("%s -- is a mirrored string.\n\n", word);
		}
		else{
			printf("%s -- is not a palindrome.\n\n", word);
		}
	}
	
	return 0;
}