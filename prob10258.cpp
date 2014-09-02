//
//  prob10258.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 6/21/14.
//  Copyright (c) 2014 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <sstream> 
#include <vector>
#include <stdlib.h>

using namespace std;


typedef struct info{
	int time, WA;
	char status;
} info;

typedef int (*compfn)(const void*, const void*);

typedef struct res{
	int player, n_problems, tti;
} res;

int compare(res *elem1, res *elem2)
{
   if(elem1->n_problems > elem2->n_problems){
		return -1;
   }
   else if(elem1->n_problems < elem2->n_problems){
		return 1;   
   }
   else{
   		if(elem1->tti > elem2->tti){
			return 1;
		}
		else if(elem1->tti < elem2->tti){
			return -1;
		}
		else{
			if(elem1->player > elem2->player){
				return 1;
			}
			else if(elem1->player < elem2->player){
				return -1;
			}
		}
   }
	return 0;
}

int main(){
	int t, pe, pr, ti, i, j, count, tti, aux;
	int inGame[110];
	res res[110];
	char op;
	info score[110][15];
	string line;
	cin >> t;
	cin.ignore();
	getline(cin, line);
	while(t--){
		// Clean
		for(i = 0; i <= 100; i++){
			for(j = 0; j < 10; j++){
				score[i][j].status = 'E';
				score[i][j].time = 0;
				score[i][j].WA = 0;
			}
			res[i].player = res[i].n_problems = res[i].tti = 0;
			inGame[i] = 0;
		}
		
		getline(cin, line);
		while(line.size() != 0){
			// Read
			istringstream iss (line);
			iss >> pe >> pr >> ti >> op;
			//cout <<  pe << " " << pr << " " << ti << " " << op << "\n";
			
			// Execute here
			if(score[pe][pr].status  == 'E'){
				score[pe][pr].status  = op;
				score[pe][pr].time = ti;
			}
			else if(score[pe][pr].status  == 'I'){
				score[pe][pr].status  = op;
				score[pe][pr].WA++;
				score[pe][pr].time = ti;
			}
			else if(score[pe][pr].status  != 'C'){
				score[pe][pr].status  = op;
				score[pe][pr].time = ti;
			}
			
			// Correct submission
			inGame[pe] = 1;
			
			if(cin.eof()){
				break;
			}
			getline(cin, line);
		}
		
		// Evaluate
		for(i = 1; i <= 100; i++){
			if(inGame[i]){
				count = 0;
				tti = 0;
				for(j = 0; j < 10; j++){
					if(score[i][j].status == 'C'){
						count++;
						tti += score[i][j].WA * 20 + score[i][j].time;
					}
				}
				res[i].player = i;
				res[i].n_problems = count;
				res[i].tti = tti;
				//cout << i << " " << count << " " << tti << "\n";
			}
		}
		
		// Sort
		qsort((void *) &res, 101, sizeof(struct res), (compfn)compare);  
		
		// Evaluate
		for(i = 0; i <= 100; i++){
			aux = res[i].player;
			//cout << aux << "\n";
			if(inGame[aux]){
				cout << res[i].player << " " << res[i].n_problems << " " << res[i].tti << "\n";
			}
		}
		
		if(t){
			cout << "\n";
		}
	}
	return 0;
}