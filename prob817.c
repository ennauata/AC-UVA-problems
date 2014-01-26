#include <stdio.h>

int main(){
	int n, l=0, total, k, i, value;
	scanf("%d", &n);
	while(n != -1){
		l++;
		value = 1;
		for(i = 0; i < n; i++){
			value = 2*value;
		}
		k = value - 1;
		total = k*k + 4*(k+1); 
		printf("Teste %d\n", l);
		printf("%d\n", total);
		scanf("%d",&n);
		if(n){
			printf("\n");
		}
	}
	return 0;
}