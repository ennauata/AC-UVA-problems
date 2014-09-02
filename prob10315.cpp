//
//  File.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 6/3/14.
//  Copyright (c) 2014 Nelson Isao Nauata Junior. All rights reserved.
//

#include <iostream>
#include <stdio.h>

using namespace std;

char card[5];
int type[2][4], val[2][20];
int play[2], pos;
	
int compare(int ref){
	int i;
	for(i = 14; i >= 2; i--){
		if(val[0][i] == ref && val[1][i] != ref){
			cout << "Black wins.\n";
			return 1;
		}
		if(val[0][i] != ref && val[1][i] == ref){
			cout << "White wins.\n";
			return 1;
		}
	}
	return 0;
}

int main(){
	int i, j, l, k, flush[2], straight[2], four_of_a_kind[2], aux, three_of_a_kind[2], two_pairs[2], one_pair[2], full_house[2];
	// init
	for(j = 0; j < 2; j++){
		for(i = 0; i < 20; i++){
			val[j][i] = 0;
		}
	}
	for(j = 0; j < 2; j++){
		for(i = 0; i < 4; i++){
			type[j][i] = 0;
		}
	}
	j = 0;
	k = 0;
	l = 0;
	cin >> card;
	while(1){
		//cout << "l = " << l << "\n" << "i = " << i << "\n";
		if(k == 5){
			l++;
		}
		else if(k == 10){
			//for(j = 0; j < 2; j++){
			//	for(i = 1; i <= 13; i++){
			//		cout << val[j][i] << " ";
			//	}
			//	cout << "\n";
			//}
			//cout << "\n";
		
			// init
			for(j = 0; j < 2; j++){
				flush[j] = 0;
				straight[j] = 0;
				four_of_a_kind[j] = 0;
				three_of_a_kind[j] = 0;
				two_pairs[j] = 0;
				one_pair[j] = 0;
				full_house[j] = 0;
				play[j] = 1;
			}

			//cout << "teste:\n"<<max[0]<<"\n"<<max[1]<<"\n";
			// get flush
			for(j = 0; j < 2; j++){
				for(i = 0; i < 4; i++){
					if(type[j][i]){
						flush[j]++;
					}
				}
				if(flush[j] > 1){
					flush[j] = 0;
				}
			}
			
			// get straight
			for(j = 0; j < 2; j++){
				aux = 0;
				for(i = 2; i <= 14; i++){
					if(val[j][i]){
						aux++;
					}
					else{
						aux = 0;
					}
					if(aux == 5){
						straight[j] = 1;
						break;
					}
				}
			}
			
			// get four of a kind
			for(j = 0; j < 2; j++){
				for(i = 2; i <= 14; i++){
					if(val[j][i] == 4){
						four_of_a_kind[j] = 1;
					}
				}
			}
			
			// get three of a kind
			for(j = 0; j < 2; j++){
				for(i = 2; i <= 14; i++){
					if(val[j][i] == 3){
						three_of_a_kind[j] = 1;
					}
				}
			}
			
			// get two pairs and one pair
			for(j = 0; j < 2; j++){
				for(i = 2; i <= 14; i++){
					if(val[j][i] == 2){
						two_pairs[j]++;
					}
				}
				if(two_pairs[j] == 2){
					two_pairs[j] = 1;
				}
				else if(two_pairs[j] == 1){
					two_pairs[j] = 0;
					one_pair[j] = 1;
				}
				else{
					two_pairs[j] = 0;
					one_pair[j] = 0;
				}
			}
			
			
			// get full house
			for(j = 0; j < 2; j++){
				if(one_pair[j] && three_of_a_kind[j]){
					full_house[j] = 1;
				}
			}
			
			for(j = 0; j < 2; j++){
				if(one_pair[j]){
					play[j] = 2;
				}
				if(two_pairs[j]){
					play[j] = 3;
				}
				if(three_of_a_kind[j]){
					play[j] = 4;
				}
				if(straight[j]){
					play[j] = 5;
				} 
				if(flush[j]){
					play[j] = 6;
				}
				if(full_house[j]){
					play[j] = 7;
				}
				if(four_of_a_kind[j]){
					play[j] = 8;
				}
				if(straight[j] && flush[j]){
					play[j] = 9;
				}
			}
			
			//cout << play[0] << "\n";
			//cout << play[1] << "\n";
			
			if(play[0] > play[1]){
				cout << "Black wins.\n";
			}
			else if(play[1] > play[0]){
				cout << "White wins.\n";
			}
			else if (play[0] == play[1]){
				if(play[0] == 1 || play[0] == 9 || play[0] == 5 || play[0] == 6){
					if(!compare(1)){
						cout << "Tie.\n";
					}
				}
				else if(play[0] == 7){
					if(!compare(3)){
						if(!compare(2)){
							cout << "Tie.\n";
						}
					}
				}
				else if(play[0] == 4){
					if(!compare(3)){
						cout << "Tie.\n";
					}
				}
				else if(play[0] == 2 || play[0] == 3){
					if(!compare(2)){
						if(!compare(1)){
							cout << "Tie.\n";
						}
					}
				}
				else if(play[0] == 8){
					if(!compare(4)){
						cout << "Tie.\n";
					}
				}
			}
			if(cin.eof()){
				return 0;
			}
			// init
			l = 0;
			k = 0;
			j = 0;
			for(j = 0; j < 2; j++){
				for(i = 0; i < 20; i++){
					val[j][i] = 0;
				}
			}
			for(j = 0; j < 2; j++){
				for(i = 0; i < 4; i++){
					type[j][i] = 0;
				}
			}
		}
		//cout << card[0] << " ISSA\n";
		pos = 0;
		if(card[0] >= '2' && card[0] <= '9'){
			pos = card[0]-'0';
		}
		else if(card[0] == 'T'){
			pos = 10;
		}
		else if(card[0] == 'J'){
			pos = 11;
		}
		else if(card[0] == 'Q'){
			pos = 12;
		}
		else if(card[0] == 'K'){
			pos = 13;
		}
		else if(card[0] == 'A'){
			pos = 14;
		}
		val[l][pos]++;
		
		if(card[1] == 'C'){
			type[l][0] = 1;
		}
		else if(card[1] == 'D'){
			type[l][1] = 1;
		}
		else if(card[1] == 'H'){
			type[l][2] = 1;
		}
		else if(card[1] == 'S'){
			type[l][3] = 1;
		}
		k++;
		cin >> card;
	}	
	return 0;
}