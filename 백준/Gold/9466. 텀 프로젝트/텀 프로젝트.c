#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int count = 0;

void DFS(int * Arr, int vertex, int start, int** mark, int depth) {	
	if (mark[vertex][1] != 0) {
		return;
	}
	mark[vertex][0] = start;
	mark[vertex][1] = depth;	
		
	if (mark[Arr[vertex]][1] != 0) {
		if (mark[Arr[vertex]][0] == start) {
			count += depth - mark[Arr[vertex]][1] + 1;
		}
	}
	else
		DFS(Arr, Arr[vertex], start, mark, depth + 1);
	
	return;
}


int main(void) {
	int T, n, i, j;
	int* Arr;
	int** mark;
	scanf("%d", &T);
	for (i = 0; i < T; i++) {
		count = 0;
		scanf("%d", &n);
		Arr = malloc(sizeof(int) * n);
		mark = (int**)malloc(sizeof(int *) * n);
		for (j = 0; j < n; j++) {
			scanf("%d", &Arr[j]);
			Arr[j] -= 1;
			mark[j] = (int*)malloc(sizeof(int) * 2);
			mark[j][0] = -1;
			mark[j][1] = 0;
		}
		for (j = 0; j < n; j++) {
			if (mark[j][1] == 0)
				DFS(Arr, j, j, mark, 1);
		}
				
		printf("%d\n", n - count);
		free(mark);		
		free(Arr);
	}
}