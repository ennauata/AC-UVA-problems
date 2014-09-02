//
//  prob10205.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 6/14/14.
//  Copyright (c) 2014 Nelson Isao Nauata Junior. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <sstream>

using namespace std;
typedef struct card{
	string suit;
	int value;
} card;


int main(){
	int t, n, i, k, j;
	card deck[55], aux_deck[55];
	string line;
	int map[110][55];
	
	cin >> t;
	while(t--){
		// init deck
		for(i = 0; i < 52; i++){
			deck[i+1].value = (i%13)+2;
			if(i/13 == 0){
				deck[i+1].suit = "Clubs";
			}
			else if(i/13 ==  1){
				deck[i+1].suit = "Diamonds";
			}
			else if(i/13 == 2){
				deck[i+1].suit = "Hearts";
			}
			else if(i/13 == 3){
				deck[i+1].suit = "Spades";
			}
		}
		
		cin >> n;
		for(k = 0; k < n; k++){
			//cout << n <<  "\n";
			for(i = 1; i <= 52; i++){
				cin >> map[k][i];
			}
			// print deck
			//for(i = 1; i <= 52; i++){
			//	cout << i << " " << deck[i].value << " " << deck[i].suit << "\n";
			//}
		}
		
		cin.ignore();
		getline(cin, line);
		while(1){
			istringstream iss(line);
			iss >> k;
			//cout << k << "\n";
			
			// execute
			for(j = 1; j <= 52; j++){
				i = map[k-1][j];
				aux_deck[j] = deck[i];
			}
			
			// copy 
			for(i = 1; i <= 52; i++){
				deck[i] = aux_deck[i];
			}
			
			//cin.ignore();
			getline(cin, line);
			
			//cout << line.length() << "\n";
			if(!line.length() || cin.eof()){
				break;
			}
		}
		
		// print deck
		for(i = 1; i <= 52; i++){
			if(deck[i].value == 11){
				cout << "Jack" << " of " << deck[i].suit << "\n";
			}
			else if(deck[i].value == 12){
				cout << "Queen" << " of " << deck[i].suit << "\n";
			}
			else if(deck[i].value == 13){
				cout << "King" << " of " << deck[i].suit << "\n";
			}	
			else if(deck[i].value == 14){
				cout << "Ace" << " of " << deck[i].suit << "\n";
			}
			else{
				cout << deck[i].value << " of " << deck[i].suit << "\n";
			}
		}
		if(t){
			cout << "\n";
		}
	}
	return 0;
}

