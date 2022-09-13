#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int N, M;
	int i, j, start, k, sum = 0;
	char* S;
	int* Arr, * final;
	scanf("%d %d", &N, &M);
	S = (char*)malloc(sizeof(char) * (M + 1));
	Arr = (int*)malloc(sizeof(int) * M);
	final = (int*)malloc(sizeof(int) * M);
	scanf("%s", S);

	for (i = 0; i < M; i++) {
		Arr[i] = 0;
		final[i] = 0;
	}

	j = 0;
	for (i = 0; i < M - 2; i++) {
		if (S[i] == 'I') {
			if ((S[i + 1] == 'O') && (S[i+2] == 'I')) {
				Arr[j] = 1;
				i++;
				j++;				
			}
			else {
				Arr[j] = 0;
				j++;
			}
		}
		else {
			Arr[j] = 0;
			j++;
		}
	}

	start = 0;
	while (1) {
		if (Arr[start] == 0)
			start++;
		else
			break;
	}

	k = 0;	

	for (i = start; i < j; i++) {
		if (Arr[i] == 0) {
			final[k] = i - start;
			start = i;
			while (1) {
				if (Arr[start] == 0)
					start++;
				else
					break;
			}
			i = start;
			k++;
		}
		if (i == j - 1) {
			final[k] = i - start + 1;
			start = i;
			k++;
		}
	}

	for (i = 0; i < k; i++) {
		if (final[i] >= N) {
			sum += final[i] - N + 1;
		}
	}

	printf("%d", sum);

	return 0;
}