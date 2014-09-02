//
//  prob10150.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 8/5/14.
//  Copyright (c) 2014 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <sstream> 

using namespace std;

int checkDoublet(string a, string b){	
	int i, diff;
	if(a.size() != b.size()){
		return 0;
	}
	else{
		diff = 0;
		for(i = 0; i < a.size(); i++){
			if(a[i] != b[i]){
				diff++;
			}
			if(diff > 1){
				return 0;
			}
		}
	}
	return 1;
}

vector<string> dic[16];
string path[3000];
int tam;
int found = 0;
int mark[16][3000];
void bfs(string w1, string w2, int recLev){
	int i;
	if(!found){
		path[recLev] = w1;
		if(!checkDoublet(w1, w2)){
			for(i = 0; i < dic[w1.size()].size(); i++){
				if(checkDoublet(w1, dic[w1.size()][i]) && !mark[w1.size()][i]){
					mark[w1.size()][i] = 1;
					bfs(dic[w1.size()][i], w2, recLev+1);
				}
			}
		}
		else{
			found = 1;
			tam = recLev+1;
			path[tam++] = w2;
		}
	}
}

int main(){
	int i, j;
	string buff;
	string w1, w2;
	
	getline(cin, buff);
	while(buff.size() > 0){
		dic[buff.size()].push_back(buff);
		getline(cin, buff);
	}
	
	getline(cin, buff);
	while(buff.size() > 0){
		istringstream iss (buff);
		iss >> w1;
		iss >> w2;
		
		//cout << w1 << "\n";
		//cout << w2 << "\n";
		// reset and mark first
		for(i = 0; i < 16; i++){
			for(j = 0; j < dic[i].size(); j++){
				if(dic[i][j] == w1){
					mark[i][j] = 1;
				}
				else{
					mark[i][j] = 0;
				}
			}
		}
		found = 0;
		if(w1.size() == w2.size()){
			bfs(w1, w2, 0);
		}
		if(found){
			for(i = 0; i < tam; i++){
				cout << path[i] << "\n";
			}
		}
		else{
			cout << "No Solution.\n";
		}
		
		if(cin.eof()){
			break;
		}
		else{
			cout << "\n";
		}
		
		getline(cin, buff);
	}
}