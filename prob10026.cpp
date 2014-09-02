//
//  prob10026.cpp
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 8/20/14.
//  Copyright (c) 2014 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>
#include <iostream> 
#include <vector> 
#include <algorithm>

using namespace std;

typedef struct task{
	long long int day, fine; 
	long long int tag;
} task;

bool myfunctiosn (task const& a,task const& b) { 
	if((a.day * b.fine) == (b.day * a.fine)){
		return a.tag <= b.tag;
	}
	return ((a.day * b.fine) < (b.day * a.fine)); 
}

int main(){
	vector<task> jobs;
	task job;
	long long int t, n, k, i, flag;
	
	scanf("%lld", &t);
	flag = scanf("%lld", &n);
	while(flag != EOF){
		k = n;
		jobs.clear();
		while(k--){
			scanf("%lld %lld", &job.day, &job.fine);
			job.tag = n-k;
			jobs.push_back(job);
		}
		
		sort(jobs.begin(), jobs.end(), &myfunctiosn);
		for(i = 0; i < jobs.size(); i++){
			cout << jobs[i].tag;
			if(i == jobs.size() - 1){
				cout << "\n";
			}
			else{
				cout << " ";
			}
		}
		flag = scanf("%lld", &n);
		if(flag != EOF){
			cout << "\n";
		}
	}
}