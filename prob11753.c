//
//  prob11755.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 8/30/13.
//  Copyright (c) 2013 Nelson Isao Nauata Junior. All rights reserved.
//
#include <stdio.h>

int divide(int n, int k, int res){
    int ceil, floor;
    if (n > k){
        floor = n/2;
        ceil = n-floor;
        res += divide(floor, k, 0);
        res += divide(ceil, k, 0);
        return  res;
    }
    else{
        return 1;
    }
}

int main(){
    while(1){
        int n , k, result;
        scanf("%d %d", &n, &k);
        if (n == 0 && k == 0) {
            break;
        }
        result = divide(n, k, 0);
        printf("%d\n", result);
    }
}