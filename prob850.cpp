//
//  prob850.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 7/1/14.
//  Copyright (c) 2014 Nelson Isao Nauata Junior. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

int main(){
	string line, word;
	map<char,char> map;
	vector<string> text, words_line, ref;
	int t, i, j, no_solution, stop;
	ref.push_back("the");
	ref.push_back("quick");
	ref.push_back("brown");
	ref.push_back("fox");
	ref.push_back("jumps");
	ref.push_back("over");
	ref.push_back("the");
	ref.push_back("lazy");
	ref.push_back("dog");
	cin >> t;
	getline(cin, line, '\n');
	cin.ignore();
	while(t--){
		getline(cin, line, '\n');
		no_solution = 1;
		text.clear();
		while(line.length() > 0){
			
			// Clear variables
			if(no_solution){	
				map.clear();
				words_line.clear();
			}
			
			// Execute here
			//cout << line << "\n";
			text.push_back(line);
			
			// Get words in line
			istringstream iss(line);
			
			iss >> word;
			while(iss){
				words_line.push_back(word);
				iss >> word;
			}
			
			// Debug
			//for(i = 0; i < words_line.size(); i++){
			//	cout << words_line[i] << " ";
			//}
			//cout << "ref:\n";
			//for(i = 0; i < ref.size(); i++){
			//	cout << ref[i] << "\n";
			//}
			//cout << "words_line:\n";
			//for(i = 0; i < words_line.size(); i++){
			//	cout << words_line[i] << "\n";
			//}
			
			// Check
			if(no_solution){
				if(ref.size() == words_line.size()){
					for(i = 0; i < ref.size(); i++){
						if(ref[i].size() == words_line[i].size()){
							stop = 0;
							for(j = 0; j < ref[i].size(); j++){
								if(map.find(words_line[i][j]) == map.end()){
									map.insert(pair<char, char>(words_line[i][j], ref[i][j]));
								}
								else if(map.find(words_line[i][j])->second != ref[i][j]){
									stop = 1;
									break;
								}
							}
							if(stop){
								no_solution = 1;
								break;
							}
							no_solution = 0;
						}
						else{
							no_solution = 1;
							break;
						}
					}
				}
			}
					
			// Check end
			if(cin.eof()){
				break;
			}else{
				getline(cin, line, '\n');
			}
		}
		
		// Print solution
		if(no_solution){
			cout << "No solution.\n";
		}
		else{
			for(i = 0; i < text.size(); i++){
				for(j = 0; j < text[i].size(); j++){
					if(text[i][j] <= 'z' && text[i][j] >= 'a'){
						cout << map.find(text[i][j])->second;
					}
					else{
						cout << text[i][j];
					}
				}
				cout << "\n";
			}
		}
		if(t){
			cout << "\n";
		}
	}
	return 0;
}