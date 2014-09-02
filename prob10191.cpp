//
//  prob10191.cpp
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 8/18/14.
//  Copyright (c) 2014 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool myfunctiosn (int i,int j) { return (i<j); }

int main(){
	vector<int> t_start, t_end;
	int k, h, m, i, diff, max, j, s_gap, f_gap, d, res_time, res_gap, l;
	char aux;
	d = 1;
	while(!cin.eof()){
		cin >> k;
		if(cin.fail()){
			break;
		}
		t_start.clear();
		t_end.clear();
		l = k;
		while(l--){
			cin >> h >> aux >> m;
			t_start.push_back(60*h+m);
						
			cin >> h >> aux >> m;
			cin.ignore(10000, '\n');
			t_end.push_back(60*h+m);
		}
		
		// Sort both!
		sort (t_start.begin(), t_start.begin()+t_start.size());
		sort (t_end.begin(), t_end.begin()+t_end.size());

		max = 0;
		j = 0;
		for(i = 1; i < t_start.size(); i++){
			diff = t_start[i] - t_end[i-1];
			if(diff > max){
				max = diff;
				j = i;
			}
		}
		
		if(k){
			s_gap = t_start[0] - 60*10;
			f_gap = 60*18 - t_end[t_end.size()-1];
			
			if(s_gap >= max && s_gap >= f_gap){
				res_time = 10*60;
				res_gap = s_gap;
			}
			else if(max > s_gap && max >= f_gap){
				res_time = t_end[j-1];
				res_gap = max;
			}
			else if(f_gap > s_gap && f_gap > max){
				res_time = t_end[t_end.size()-1];
				res_gap = f_gap;
			}
		}
		else{
			res_time = 60*10;
			res_gap = 8*60;
		}
		
		// No final
		cout << "Day #" << d++ << ": the longest nap starts at ";
		cout << res_time/60 << ":";
		
		if(res_time%60 < 10){
			cout << "0";
		}
		cout << res_time%60 << " and will last for ";
		
		if(res_gap/60){
			cout << res_gap/60 << " hours and ";
		}
		cout << res_gap%60 << " minutes.\n";
	}
}