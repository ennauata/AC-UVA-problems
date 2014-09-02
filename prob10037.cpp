//
//  prob10037.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 8/15/14.
//  Copyright (c) 2014 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

bool myfunction (int i,int j) { return (i<j); }

int main(){
	int t, sp, i, n, time, max, inc, aux, j;
	vector<int> sideA;
	vector<int> buffer_go, buffer_go_back;
	string buffer;
	cin >> t;
	cin.ignore();
	getline(cin, buffer);
	
	while(t--){
		cin >> n;
		sideA.clear();
		buffer_go_back.clear();
		buffer_go.clear();
		while(n--){
			cin >> sp;
			sideA.push_back(sp);
		}
		time = 0;
		while(1){
			sort (sideA.begin(), sideA.begin()+sideA.size());
			if(sideA.size() >= 4){
				if(sideA[0] + sideA[sideA.size()-2] < 2*sideA[1]){
					// Estrategia 1
					time += 2*sideA[0] + sideA[sideA.size()-2] + sideA[sideA.size()-1];
					
					// A, A
					buffer_go_back.push_back(sideA[0]);
					buffer_go_back.push_back(sideA[0]);
					
					// A, C
					buffer_go.push_back(sideA[0]);
					buffer_go.push_back(sideA[sideA.size()-2]);
					
					// A, D
					buffer_go.push_back(sideA[0]);
					buffer_go.push_back(sideA[sideA.size()-1]);
				}
				else{
					// Estrategia 2
					time += sideA[0] + 2*sideA[1] + sideA[sideA.size()-1];
					
					// A, B
					buffer_go_back.push_back(sideA[0]);
					buffer_go_back.push_back(sideA[1]);
					
					// A, B
					buffer_go.push_back(sideA[0]);
					buffer_go.push_back(sideA[1]);
					
					// C, D
					buffer_go.push_back(sideA[sideA.size()-2]);
					buffer_go.push_back(sideA[sideA.size()-1]);
				}
				// Atualiza sideB
	
				sideA.pop_back();
				sideA.pop_back();
			}
			else{
				// Resolve para n <= 3
				max = sideA[0];
				inc = 0;
				for(i = 0; i < sideA.size(); i++){
					inc += sideA[i];
					if(sideA[i] > max){
						max = sideA[i];
					}
				}
				if(sideA.size() >= 2){
					for(i = 1; i < sideA.size(); i++){
						// A, n(i)
						buffer_go.push_back(sideA[0]);
						buffer_go.push_back(sideA[i]);
					}
				}
				else{
					// A
					buffer_go.push_back(sideA[0]);
				}
				if(sideA.size() == 3){
					// A
					buffer_go_back.push_back(sideA[0]);
				}
				if(sideA.size() == 2){
					inc = max;
				}
				time += inc;
				sideA.clear();
			}
			
			// Todos do outro lado pare!
			if(!sideA.size()){
				break;
			}
		}
		cout << time << "\n";
		i = 0;
		j = 0;
		while(i < buffer_go.size()){
			cout << buffer_go[i++];
			if(i < buffer_go.size()){
				cout << " " << buffer_go[i++];
			}
			cout << "\n";
			if(j < buffer_go_back.size()){
				cout << buffer_go_back[j++] << "\n";
			}
		}
		if(t){
			cout << "\n";
		}
	}
	return 0;
}