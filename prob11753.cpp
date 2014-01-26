//
//  prob11753.cpp
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 8/30/13.
//  Copyright (c) 2013 Nelson Isao Nauata Junior. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <math.h>

int read(std::vector<int>& X){
    int i, n, x;
    scanf("%d ", &n);
    if( n == 0){
        return 1;
    }
    for(i=0; i < n; i++){
        scanf("%d ", &x);
        X.push_back(x);
    }
    return 0;
}

int print(std::vector<int>& X){
    int i;
    for (i = 0; i<X.size(); i++)
        std::cout << X[i];
    std::cout << "\n";
    return 0;
}
int BSearch (int x, std::vector<int>& A,int e,int d)
{
    int m;
    while (e <= d) {
        m = (e + d)/2;
        if (A[m] == x) return m;
        if (A[m] < x) e = m + 1;
        else d = m - 1;
    }
    return d+1;
}
std::vector<int> calculateM(std::vector<int>& X){
    std::vector<int> A;
    std::vector<int> M;
    int i, j, c;
    for (i=0; i < X.size(); i++){
        if (A.size() == 0) {
            A.push_back(X[i]);
        }
        else{
            j = BSearch(X[i], A, 0, A.size()-1);
            if (j == A.size()) {
                A.push_back(X[i]);
            }
            else{
                A.insert(A.begin()+j, X[i]);
            }
        }
        c = ceil(i/2);
        M.push_back(A[c]);
    }
    return M;
}

/* Utility function to get max of 2 integers */
int max(int a, int b)
{
    return (a > b)? a : b;
}

/* Returns length of LCS for X[0..m-1], Y[0..n-1] */
int lcs( std::vector<int>& X, std::vector<int>& Y, long int m, long int n )
{
    int L[m+1][n+1];
    int i, j;
    
    /* Following steps build L[m+1][n+1] in bottom up fashion. Note
     that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
    for (i=0; i<=m; i++)
    {
        for (j=0; j<=n; j++)
        {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            
            else if (X[i-1] == Y[j-1])
                L[i][j] = L[i-1][j-1] + 1;
            
            else
                L[i][j] = max(L[i-1][j], L[i][j-1]);
        }
    }
    
    /* L[m][n] contains length of LCS for X[0..n-1] and Y[0..m-1] */
    return L[m][n];
}

int main(){
    int result, stop = 0;
    std::vector<int> P;
    std::vector<int> R;
    std::vector<int> M;
    while(1){
        P.clear();
        R.clear();
        M.clear();
        result = 0;
        stop = read(P);
        if(stop == 1){
            break;
        }
        read(R);
        M = calculateM(P);
        std::cout << lcs(R, M, R.size(), M.size());
        std::cout << "\n";
    }
    return 0;
}