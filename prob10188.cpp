//
//  prob10188.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 7/2/14.
//  Copyright (c) 2014 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int main(){
	int n, m, i, j;
	int c1, c2, t = 1;
	cin >> n;
	string line;
	vector<string> input1, input2;
	string in1, in2;
	
	while(n){
		input1.clear();
		input2.clear();
		cin.ignore();
		while(n--){
			getline(cin, line);
			input1.push_back(line);
			//cout << line << "\n";
		}
		
		cin >> m;
		cin.ignore();
		
		while(m--){
			getline(cin, line);
			input2.push_back(line);
			//cout << line << "\n";
		}
		
		// Execute
		in1.clear();
		in2.clear();
		
		// For input1
		for(i = 0; i < input1.size(); i++){
			for(j = 0; j < input1[i].size(); j++){
				if(isdigit(input1[i][j])){
					in1.push_back(input1[i][j]);
				}
			}
		}
		
		// For input2
		for(i = 0; i < input2.size(); i++){
			for(j = 0; j < input2[i].size(); j++){
				if(isdigit(input2[i][j])){
					in2.push_back(input2[i][j]);
				}
			}
		}
		
		c1 = 0;
		c2 = 0;
		if(input1.size() == input2.size()){
			for(i = 0; i < input1.size() && i < input2.size(); i++){
				if(input1[i].compare(input2[i]) != 0){
					c1 = 1;
					break;
				}
			}
		}
		else{
			c1 = 1;
		}
		
		//cout << in1 << "\n";
		//cout << in2 << "\n";
		if(in1.compare(in2) == 0){
			c2 = 1;
		}
		
		if(c1 && c2){
			cout << "Run #" << t << ": Presentation Error\n";
		}
		else if(c1  && !c2){
			cout << "Run #" << t << ": Wrong Answer\n";
		}
		else{
			cout << "Run #" << t << ": Accepted\n";
		}
		t++;
		cin >> n;
	}
	return 0;
}