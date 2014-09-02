//
//  prob10132.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 7/5/14.
//  Copyright (c) 2014 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;


int tree[3000];
int size_res = 0, n;
vector<string> files_fragments[3000];
int mark[3000][1000];
string res;
int found = 0;

void find(int rec_lev, string buffer){
	int i, j, k;
	string ref;
	//cout << n << "\n";
	//  Executa
	if(!found){
		if(rec_lev < n){
			for(i = 1; i <= size_res; i++){
				for(j = 0; j < files_fragments[i].size(); j++){
					for(k = 0; k < files_fragments[size_res-i].size(); k++){
						//cout << files_fragments[i][j] + files_fragments[size_res-i][k] << "\n";
						ref = files_fragments[i][j] + files_fragments[size_res-i][k];
						if(!(size_res == 2*i && j == k)){
								if(!mark[i][j] && !mark[size_res-i][k]){
								mark[i][j] = 1;
								mark[size_res-i][k] = 1;
								if(buffer.size() == 0){
									buffer = ref;
									find(rec_lev+1, buffer);
									buffer = "";
								}
								else{
									if(ref.compare(buffer) == 0){
										find(rec_lev+1, buffer);
									}
								}
								mark[i][j] = 0;
								mark[size_res-i][k] = 0;
							}
						}
					}
				}
			}
		}
		else{
			res = buffer;
			//cout << buffer << "\n";
			found = 1;
		}
	}
}

int main(){
	int t, size, i , j;
	string line;
	cin >> t;
	cin.ignore();
	getline(cin, line);
	while(t--){
		n = 0;
		size = 0;
		getline(cin, line);
		
		// init tree
		for(i = 0; i < 3000; i++){
			tree[i] = 0;
		}
		while(line.size() > 0){
			
			files_fragments[line.size()].push_back(line);
			size += line.size();
			n++;
			if(cin.eof()){
				break;
			}
			getline(cin, line);
		}

		n /= 2;
		size_res = size/n;
		
		// Reset
		for(i = 0; i < 2*n; i++){
			for(j = 0; j < files_fragments[i].size(); j++){
				mark[i][j] = 0;
			}
		}
		res = "";
		found = 0;
		
		// Find element
		find(0, "");
		cout << res << "\n";
		if(t){
			cout << "\n";
		}
	}
	return 0;
}