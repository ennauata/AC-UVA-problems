//
//  File.cpp
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 11/12/13.
//  Copyright (c) 2013 Nelson Isao Nauata Junior. All rights reserved.
//

#include "prob810.h"

class edge
{
   public:
      int x;  
	  int y;
      int z; 
};

void sift(int pai, int n, vector<edge>& v)
{
    int filho = 2 * pai;   
	edge aux;                                 
    while (filho <= n) {                                                
        if (filho > n && v[filho].z > v[filho + 1].z)                       
            ++filho;
        if (v[filho / 2].z <= v[filho].z)                                 
            break;                                                   
        aux = v[filho / 2], v[filho / 2] = v[filho], v[filho] = aux;  
        filho *= 2;                                                 
    }
}


void heapify(int n, vector<edge>& myvector)
{
    int p;
    for (p = n / 2; p >= 1; --p)                                         
        sift(p, n, myvector);
}

int main(){
	int m, n, i, x, y, z, tam, exist;
	vector<edge> myvector;
	vector<int> stack;
	edge edge1, aux, element;
	while(1){
		scanf("%d %d", &n, &m);
		if(n == 0 && m == 0){
			break;
		}
		myvector.push_back(edge1);
		for(i = 0; i < m; i++){
			scanf("%d %d %d", &x, &y, &z);
			edge1.x = x;
			edge1.y = y;
			edge1.z = z;
			myvector.push_back(edge1);
		}
		tam = myvector.size();
		heapify(tam-1, myvector);
		stack.push_back(1);
		while(tam-1){
			element = myvector[0];
			
			exist = 0;
			for(i = 0; i < tam-1; i++){
				if(myvector[i].x == stack[i]){
					exist = 1;
					break;
				}
			}
			if(exist == 0){
				stack.push_back(myvector[i].x);
			}
			exist = 0;
			for(i = 0; i < tam-1; i++){
				if(myvector[i].y == stack[i]){
					exist = 1;
					break;
				}
			}
			if(exist == 0){
				stack.push_back(myvector[i].y);
			}
			myvector[0] = myvector[tam-1];
			myvector.pop_back();
			tam = myvector.size();
			sift(1, tam-1, myvector);
		}
		for(i = 0; i < m; i++){
			cout << myvector[i].x;
			cout << myvector[i].y;
			cout << myvector[i].z;
		}
	}	
}