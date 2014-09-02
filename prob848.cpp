//
//  prob848.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 8/7/14.
//  Copyright (c) 2014 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string> 

using namespace std;


string removeSpacing(int pos, string s){
	int i, flag_start;
	string buffer;
	
	// Remove spacing
	flag_start = 0;
	buffer.clear();
	for(i = pos; i < s.size(); i++){
		if(s[i] != ' '){
			flag_start = 1;
		}
		
		if(flag_start){
			buffer += s[i];
		}
	}
	//cout << buffer;
	return buffer;
}

string splitString(string s){
	int i, ptr_pre, ptr_pos;
	char prev, curr;
	
	prev = curr = s[0];
	ptr_pre = ptr_pos = 0;
	for(i = 1; i < s.size(); i++){
		curr = s[i];
		if((prev != ' ' || prev != '\n') && (curr == ' ' || curr == '\n')){
			ptr_pos = i-1;
			if(ptr_pos < 72){
				ptr_pre = ptr_pos;
			}
			else{
				break;
			}
		}
		prev = curr;
	}
	if(i == s.size()){
		if(s.size() <= 72){
			ptr_pre = i-1;
		}
		else if(s.size() > 72 && ptr_pos == 0){
			ptr_pre = i-1;
		}
	}
	if(!ptr_pre){
		ptr_pre = ptr_pos;
	}
	
	//Print
	for(i = 0; i <= ptr_pre; i++){
		//cout << s[i];
	}
	//cout << "\n";
	
	//cout << ptr_pre << "----TESTE-----\n";
	if(ptr_pre+1 <= s.size()){
		return removeSpacing(ptr_pre + 1, s);
	}
	else{
		return "";
	}
}


int main(){
	string accBuffer;
	string currBuffer;
	string aux;

	accBuffer.clear();
	while(!cin.eof()){
		getline(cin, currBuffer);
		
		aux = removeSpacing(0, currBuffer);
		if(aux.size()){
		
			// Remove initial spacing!
			if(accBuffer.size()){
				//currBuffer = removeSpacing(0, currBuffer);
				aux = removeSpacing(0, currBuffer);
				if(aux.size() == currBuffer.size()){
					accBuffer += " " + currBuffer;
				}
				else{
					//cout << "TESTE!!\n";
					accBuffer += "\n" + currBuffer;
				}
			}
			else{
				accBuffer = currBuffer;
			}
			
			if(accBuffer.size() >= 72){
			// imprime e reseta string
				accBuffer = splitString(accBuffer);
			}
		}
		else{
			// Imprime
			while(accBuffer.size()){
				accBuffer = splitString(accBuffer);
			}
			cout << "\n";
		}
	}
	//cout << "teste2\n";
	while(accBuffer.size()){	
		accBuffer = splitString(accBuffer);
	}
	//cout << "\n";
	return 0;
}