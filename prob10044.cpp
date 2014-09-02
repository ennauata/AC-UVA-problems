//
//  prob10044.cpp
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 6/14/14.
//  Copyright (c) 2014 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <algorithm>
#define MAX 9999

using namespace std;
int results[MAX];
int mark[MAX];
vector<string> names;
vector<string> papers;
map<string, int> table;
string line, name;
vector<string> paper;
int mSet[MAX];

int graph[MAX][MAX];

void bfs(int recLev, int i){
	int j;
	results[i] = recLev;
	for(j = 0; j < names.size(); j++){
		if(graph[i][j] && !mark[j]){
			mark[j] = 1;
			bfs(recLev+1, j);
		}
	}
}

int main(){
	int t, p, n, i, j, k, l, s;
	cin >> t;
	cin.clear();
	cin.ignore(10000,'\n');
	s = 0;
	while(t--){
		cin >> p >> n;
		cin.clear();
		cin.ignore(10000,'\n');
		
		// Clean
		names.clear();
		table.clear();
		papers.clear();
		
		//cout << p << " " << n << "\n";
		while(p--){
			getline(cin, line);
			//cout << line << "\n";
			line.erase(std::remove(line.begin(),line.end(),' '),line.end());
			papers.push_back(line);
		}

		names.push_back(string("Erdos,P."));
		table.insert(pair<string, int>(string("Erdos,P."), 0));
		for(i = 1; i <= n; i++){
			getline(cin, line);
			line.erase(std::remove(line.begin(),line.end(),' '),line.end());
			names.push_back(line);
			table.insert(pair<string, int>(line, i));
		}
		
		// Clean graph
		for(i = 0; i < names.size(); i++){
			for(j = 0; j < names.size(); j++){
				graph[i][j] = 0;
			}
		}
		
		// build matrix
		for(k = 0; k < papers.size(); k++){
		
			// Clean set
			for(i = 0; i < names.size(); i++){
				mSet[i] = 0;
			}
			
			//cout << papers[k] << "\n";
			for(j = 0; j < names.size(); j++){
				//cout << names[j] << " ";
				if(papers[k].find(names[j]) != string::npos){
					//cout << papers[k]<< "contains "<<names[j] << "\n";
					l = table.find(names[j])->second;
					mSet[l] = 1;
				}
			}
			
			for(j = 0; j < names.size(); j++){
				//cout << mSet[j] << "\n";
				for(l = 0; l < names.size(); l++){
					if(mSet[l] && mSet[j]){
						graph[j][l] = 1;
						graph[l][j] = 1;	
					}
				}
			}
			//cout << "Stopu\n";
		}
		
		for(i = 0; i < names.size(); i++){
			results[i] = 0;
			mark[i] = 0;
		}
		
		//for(i = 0; i < names.size(); i++){
		//	for(j = 0; j < names.size(); j++){
		//		cout << graph[i][j];
		//	}
		//	cout << "\n";
		//}
		//cout << "\n";
			
		// bfs
		bfs(0, 0);
		
		cout << "Scenario " << ++s << "\n";
		for(i = 1; i < names.size(); i++){
			if(results[i]){
				for(j = 0; j < names[i].size(); j++){
					if(names[i][j] != ','){
						cout << names[i][j];
					}
					else{
						cout << ", ";
					}
				}
				cout << " " << results[i] - 1 << "\n";
			}
			else{
				for(j = 0; j < names[i].size(); j++){
					if(names[i][j] != ','){
						cout << names[i][j];
					}
					else{
						cout << ", ";
					}
				}				
				cout << " infinity\n";
			}
		}
	}
	return 0;
}