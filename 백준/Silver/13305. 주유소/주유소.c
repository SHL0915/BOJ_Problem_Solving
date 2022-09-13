#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int N, i,j, sum = 0, start;
	int* distance, * price;
	scanf("%d", &N);
	distance = (int*)malloc(sizeof(int) * N);
	price = (int*)malloc(sizeof(int) * N);
	for (i = 0; i < N - 1; i++) 
		scanf("%d", &distance[i]);	
	for (i = 0; i < N; i++)
		scanf("%d", &price[i]);
	start = 0;
	while (1) {
		i = start;
		while (i < N) {
			if (price[start] <= price[i])
				i++;
			else
				break;
		}
		if (i == N) {
			for (j = start; j < N-1; j++) {
				sum += price[start] * distance[j];				
			}
			break;
		}
		else {
			for (j = start; j < i; j++) {
				sum += price[start] * distance[j];
			}
		}
		start = i;		
	}
	printf("%d", sum);
	return 0;
}
