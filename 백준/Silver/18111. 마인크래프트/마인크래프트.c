#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void) {
	int N, M, B;
	int i, j;
	int min_level = 256, max_level = 0, temp;
	int time, min_time, level;
	int Arr[257];
	int data, block = 0;

	scanf("%d %d %d", &N, &M, &B);

	for (i = 0; i < 257; i++) {
		Arr[i] = 0;
	}

	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			scanf("%d", &data);
			if (data <= min_level)
				min_level = data;
			if (data >= max_level)
				max_level = data;
			Arr[data] += 1;
			block += data;
		}
	}

	for (i = 255; i >= 0; i--) {
		Arr[i] = Arr[i] + Arr[i + 1];
	}

	temp = max_level;

	if (max_level >= (block + B) / (N * M)){
		max_level = (block + B) / (N * M);	
	}

	for (i = min_level; i <= max_level; i++) {
		time = 0;
		for (j = min_level; j <= temp; j++) {
			if (j <= i)
				time += N * M - Arr[j];
			else
				time += 2 * Arr[j];
		}
		
		if (i == min_level) {
			min_time = time;
			level = i;
		}
		else {
			if (time <= min_time) {
				min_time = time;
				level = i;
			}
		}
	}
	printf("%d %d", min_time, level);
}
