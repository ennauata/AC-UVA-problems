//
//  prob579.c
//  SPOJEMC
//
//  Created by Nelson Isao Nauata Junior on 1/4/14.
//  Copyright (c) 2014 Nelson Isao Nauata Junior. All rights reserved.
//

#include <stdio.h>
#include <math.h>

double min(double a, double b){
	if(a > b){
		return b;
	}
	else{
		return a;
	}
}

double my_abs(double a){
	if(a >= 0){
		return a;
	}
	else{
		return -a;
	}
}

int main(){
	int h, m;
	double m_angle, h_angle, diff;
	while(scanf("%d:%d\n", &h, &m)){
		if(h == 0 && m == 0){
			break;
		}
		else{
			//printf("%d:%d\n", h, m);
			m_angle = m*6;
			h_angle = (h*60 + m)*0.5;
			diff = min(my_abs(h_angle - m_angle), my_abs(360-my_abs(h_angle - m_angle)));
			printf("%.3f\n", diff);
		}
	}
	return 0;
}