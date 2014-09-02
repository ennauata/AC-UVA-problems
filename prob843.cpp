//
//  prob843.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 6/6/14.
//  Copyright (c) 2014 Nelson Isao Nauata Junior. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string>
#include <set>
#include <map>
#include <vector>

using namespace std;

typedef set<string> dic;
typedef map<char, char> cryp;

dic dictionary[20];
vector<string> list;

int pass(cryp map, cryp reverse_map, string word, string sentence){
	int i;
	for(i = 0; i < sentence.length(); i++){
		if(map.find(sentence[i]) == map.end() && reverse_map.find(word[i]) == reverse_map.end()){
			map.insert(pair<char, char>(sentence[i], word[i]));
			reverse_map.insert(pair<char, char>(word[i], sentence[i]));
		}
		else{
			if(map.find(sentence[i])->second != word[i] || reverse_map.find(word[i])->second != sentence[i]){
				//cout << sentence[i] << "\n";
				//cout << word[i] << "\n";
				return 0;
			}
		}
	}
	return 1;
}

int updateMap(cryp *map, cryp *reverse_map, string word, string sentence){
	int i;
	for(i = 0; i < sentence.length(); i++){
		if(map->find(sentence[i]) == map->end() && reverse_map->find(word[i]) == reverse_map->end()){
			map->insert(pair<char, char>(sentence[i], word[i]));
			reverse_map->insert(pair<char, char>(word[i], sentence[i]));
		}
	}
	return 0;
}
cryp final_map;
int check(int rec_lev, cryp map, cryp reverse_map){
	int tam;
	cryp copy_map, copy_reverse_map;
	if(rec_lev < list.size()){
		// testa todas as palavras
		tam = (int)list[rec_lev].length();
		for (set<string>::iterator it_d=dictionary[tam].begin(); it_d!=dictionary[tam].end(); ++it_d){
			//cout << "dic:" << *it_d << " sent:" << list[rec_lev] << "\n";
			//cout << "map\n";
			// print map
			//for(cryp::iterator it_m = map.begin(); it_m!= map.end(); ++it_m){
			//	cout <<it_m->first << "->" << it_m ->second << "\n";
			//}
			//cout << "reverse map\n";
			// print map
			//for(cryp::iterator it_m = reverse_map.begin(); it_m!= reverse_map.end(); ++it_m){
			//	cout << it_m->first << "->" << it_m ->second << "\n";
			//}
			if(pass(map, reverse_map, *it_d, list[rec_lev])){
				copy_map = map;
				copy_reverse_map = reverse_map;
				updateMap(&copy_map, &copy_reverse_map, *it_d, list[rec_lev]);
				if(check(rec_lev+1, copy_map, copy_reverse_map) != 0){
					return 1;
				}
			}
		}
		return 0;
	}
	final_map = map;
	return 1;
}

int main(){
	int n, i, k, j, flag = 0, flag2;
	string word, ref;
	cryp map, reverse_map;
	char buffer[90];
	cin >> n;
	for(i = 0; i < n; i++){
		cin >> word;
		dictionary[word.length()].insert(word);
	}
	while(getline(cin, ref, '\n')){
		// Execute
		//cout << ref.length() << '\n';
		if(ref.length() > 0){
			flag = 1;
		 	k = 0;
			i = 0;
			flag2 = 0;
			while(i <= ref.length()){
				if((ref[i] <= 'Z' && ref[i] >= 'A') || (ref[i] <= 'z' && ref[i] >= 'a')){
					buffer[k] = ref[i];
					flag2 = 1;
					k++;
				}
				else{
					if(flag2){
						buffer[k] = '\0';
						list.push_back(buffer);
						k = 0;
						flag2 = 0;
					}
				}
				i++;
			}
			map.clear();
			reverse_map.clear();
			if(check(0, map, reverse_map) != 0){
				// imprime
				for(i = 0; i < list.size(); i++){
					for(j = 0; j < list[i].size(); j++){
						cout << final_map.find(list[i][j])->second;
					}
					if(i != list.size()-1){
						cout << " ";
					}
				}
				cout << "\n";
			}
			else{
				for(i = 0; i < list.size(); i++){
					for(j = 0; j < list[i].size(); j++){
						cout <<"*";
					}
					if(i != list.size()-1){
						cout << " ";
					}
				}
				cout << "\n";
			}
			for(i = 0; i < 20; i++){
				list.clear();
			}	
		}
		else if(ref.length() == 0 && flag){
			cout << '\n';
		}
	}
	return 0;
}