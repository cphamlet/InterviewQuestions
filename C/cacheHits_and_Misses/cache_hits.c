/*
Author: Connor Hamlet. 

	gcc name.c -o name -fopenmp -O3


*/

#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
int main(){
	int n = 32000;
	int *g[n]; 

	int counter = 0;
	for(int i = 0; i<n; i++) g[i] = malloc(n*sizeof(int));
	puts("Filling array with 1s");
	for (int i = 0; i<n; i++){
		for(int j = 0; j<n; j++){
			g[i][j] = 1;
		}
	}
	puts("End of writing array, summing values in array:");
	const double time_start = omp_get_wtime();
	int sol = 0;

	//Here is the critcal line where if you switch [j][i] you'll find the performance increases to
	//10% of the previous value
	for(int i = 0; i<n; i++){
		for(int j = 0; j<n; j++){
		sol = sol + g[i][j];
		}
	}
	double diff = omp_get_wtime() - time_start;
	//feels 2D array
	for(int i = 0; i<n;i++) free(g[i]);

	printf("Sum of 2D array: %i\n", sol);
	printf("Time in seconds to complete: %f\n", diff);

	return 0;
}
