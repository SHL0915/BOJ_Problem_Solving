#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>


long long cal(long long N) {
	return (N * (N + 1) / 2);
}

int main(void) {
	int N, M, i;
	int* Arr;
	long long* count;
	long long result = 0;

	scanf("%d %d", &N, &M);
	Arr = (int*)malloc(sizeof(int) * N);
	count = (long long*)malloc(sizeof(long long) * M);

	for (i = 0; i < N; i++) {
		scanf("%d", &Arr[i]);
	}


	for (i = 0; i < M; i++) {
		count[i] = 0;
	}


	Arr[0] = Arr[0] % M;
	count[Arr[0]] += 1;

	for (i = 1; i < N; i++) {
		Arr[i] += Arr[i - 1];
		Arr[i] = Arr[i] % M;
		count[Arr[i]] += 1;
	}

	for (i = 0; i < M; i++) {	
		if (count[i] == 0)
			continue;
		else {
			if (i == 0)
				result += cal(count[0]);
			else {
				if (count[i] == 1)
					continue;
				else
					result += cal(count[i] - 1);
			}
		}
	}

	printf("%lld", result);

}
