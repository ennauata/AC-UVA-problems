//
//  prob10138.cpp
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 8/20/14.
//  Copyright (c) 2014 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <algorithm>

using namespace std;

typedef struct position{
	int date[4];
	int pos;
} position;

typedef struct par{
	position enter, exit;
} par;

typedef struct node{
	string license;
	vector<position> mult_exits, mult_enters;
	vector<par> pairs;
	int in, out;
} node;

bool myfunctiosn (node const& a,node const& b) { 
	if(a.license.compare(b.license) > 0){
		return 0;
	}
	else{
		return 1;
	}
}


bool compare (position const& a,position const& b) { 
	int i, flag;
	flag = 1;
	for(i = 0; i < 4; i++){
		if(a.date[i] > b.date[i]){
			flag = 0;
			break;
		}
		else if(a.date[i] < b.date[i]){
			flag = 1;
			break;
		}
	}
	return flag;
}

int main(){
	int t, i, val, month, day, hour, min, pos, k, isValid, j, l, m;
	float sum, cost;
	map<string, int> hashtable;
	string buffer, license, action;
	node vehicle;
	position aux_pos;
	par par;
	vector<int> tolls;
	vector<node> vehicles;
	char c;
	
	scanf("%d", &t);
	while(t--){
		// clear variables
		tolls.clear();
		vehicles.clear();
		hashtable.clear();
		
		for(i = 0; i < 24; i++){
			scanf("%d", &val);
			tolls.push_back(val);
		}
		cin.ignore();
		getline(cin, buffer);
		while(buffer.size()){
			istringstream iss (buffer);
			iss >> license >> month >> c >> day >> c >> hour >> c >> min >> action >> pos;
			
			aux_pos.date[0] = month;
			aux_pos.date[1] = day;
			aux_pos.date[2] = hour;
			aux_pos.date[3] = min;
			aux_pos.pos = pos;
			vehicle.mult_exits.clear();
			vehicle.mult_enters.clear();
			if(hashtable.find(license) == hashtable.end()){
			
				// Not found!
				vehicle.license = license;
				if((action.compare("exit") == 0)){
					vehicle.out = 1;
					vehicle.in = 0;
					vehicle.mult_exits.push_back(aux_pos);
				}
				else{
					vehicle.in = 1;
					vehicle.out = 0;
					vehicle.mult_enters.push_back(aux_pos);
				}
				hashtable.insert(pair<string, int>(license, vehicles.size()));
				vehicles.push_back(vehicle);
			}
			else{
				// Found
				k = hashtable.find(license)->second;
				
				if((action.compare("exit") == 0)){
					vehicles[k].out = 1;
					vehicles[k].mult_exits.push_back(aux_pos);
				}
				else{
					vehicles[k].in = 1;
					vehicles[k].mult_enters.push_back(aux_pos);
				}	
			}
			if(cin.eof()){
				break;
			}
			getline(cin, buffer);
		}
		
		// Sort
		sort(vehicles.begin(), vehicles.end(), &myfunctiosn);
		
		// Print res
		for(i = 0; i < vehicles.size(); i++){
			
			// Find pairs
			// sort both
			sort(vehicles[i].mult_exits.begin(), vehicles[i].mult_exits.end(), &compare);
			sort(vehicles[i].mult_enters.begin(), vehicles[i].mult_enters.end(), &compare);
			//for(j = 0; j < vehicles[i].mult_exits.size(); j++){
			//	cout << vehicles[i].mult_exits[j].pos << " ";
			//}
			//cout << "\n";
			
			while(vehicles[i].mult_exits.size() && vehicles[i].mult_enters.size()){
				for(j = 0; j < vehicles[i].mult_exits.size(); j++){
					for(l = 0; l < vehicles[i].mult_enters.size(); l++){
						isValid = 0;
						for(m = 0; m < 4; m++){
							if(vehicles[i].mult_exits[j].date[m] > vehicles[i].mult_enters[l].date[m]){
								isValid = 1;
								break;
							}
							else if (vehicles[i].mult_exits[j].date[m] < vehicles[i].mult_enters[l].date[m]){
								isValid = 0;
								break;
							}
						}
						if(isValid){
							par.enter = vehicles[i].mult_enters[l];
							par.exit = vehicles[i].mult_exits[j];
							
							cout << "enter_pos: " << par.enter.date[3] <<"\n";
							cout << "exit_pos: " << par.exit.date[3] <<"\n";
							
							vehicles[i].pairs.push_back(par);
							vehicles[i].mult_enters.erase(vehicles[i].mult_enters.begin() + l);
							vehicles[i].mult_exits.erase(vehicles[i].mult_exits.begin() + j);
							break;
						}
					}
					if(isValid){
						break;
					}
				}
				if(j == vehicles[i].mult_exits.size() && l == vehicles[i].mult_enters.size()){
					break;
				}
			}
			
			if(vehicles[i].pairs.size()){
				cout << "number of pairs: " << vehicles[i].pairs.size() << "\n";
				sum = 300;
				for(j = 0; j < vehicles[i].pairs.size(); j++){
					cost = tolls[vehicles[i].pairs[j].enter.date[2]]*(abs(vehicles[i].pairs[j].exit.pos - vehicles[i].pairs[j].enter.pos));
					sum += cost;
				}
				cout << fixed;
				cout << setprecision(2);
				cout << vehicles[i].license << " $" << sum/100 << "\n";
			}
		}
		if(t){
			cout << "\n";
		}
	}
	return 0;
}