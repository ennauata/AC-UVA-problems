// Complexity O(n)
#include <stdio.h>
#include <stdlib.h>

int sequence(int *numbers, int size, int *i_max, int *j_max)
{

        int max_so_far  = numbers[0];
		int max_ending_here = numbers[0];
 		int i;
        int begin = 0;
        int begin_temp = 0;
        int end = 0;
 
     
        for(i = 1; i < size; i++)
        {
    
                if(max_ending_here < 0)
                {
                        max_ending_here = numbers[i];
 
                        begin_temp = i;
                }
                else
                {
                        max_ending_here += numbers[i];
                }
 
         
                if(max_ending_here >= max_so_far )
                {
                        max_so_far  = max_ending_here;
 
                        begin = begin_temp;
                        end = i;
                }
        }
		*i_max = begin;
		*j_max = end;
        return max_so_far ;
}

int main(){
	int i, n, j, x, y, max_i, max_j, max_value, l = 0;
	int *numbers;
	scanf("%d", &n);
	while(n){
		l++;
		numbers = malloc(n*sizeof(int));
		j = 0;
		for (i = 0; i < n; i++) {
			scanf("%d %d", &x, &y);
			numbers[i] = x-y;

		}
		
		max_value = sequence(numbers, n, &max_i, &max_j);
		printf("Teste %d\n", l);
		if(max_value>0){
			printf("%d %d\n", max_i+1, max_j+1);
		}
		else{
			printf("nenhum\n");
		}
		scanf("%d", &n);
		if(n){
			printf("\n");
		}
		free(numbers);
	}
}