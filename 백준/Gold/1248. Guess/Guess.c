#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

/*
	정수로 이루어진 수열 a1, a2, ... an이 주어졌을 때, 행렬 S의 부호는 다음과 같이 판단한다.
	1 <= i <= j <= n, ai + ... + aj 가 양수이면 양수, 음수이면 음수, 0이면 0이다.
	여러 수열이 같은 부호 행렬을 생성할 수 있다.
	가능한 부호 행렬이 주어졌을 때, 수열의 모든 정수가 -10과 10 사이인 수열을 찾는다.
*/

int flag = 0;

void BackTracking(int* Arr, char** S, int N, int k);

int main(void) {
	int n, * Arr, i, j; // 길이가 n인 수열 Arr
	char** S, c;
	scanf("%d", &n);
	Arr = (int*)malloc(sizeof(int) * n);
	S = (char**)malloc(sizeof(char*) * n);
	c = getchar();
	for (i = 0; i < n; i++) {		
		S[i] = (char*)malloc(sizeof(char) * n);
		for (j = 0; j < n; j++) {			
			if (j >= i)
				S[i][j] = getchar();
		}
	}
	BackTracking(Arr, S, n, n - 1);
}

void BackTracking(int* Arr, char** S, int N, int k) {
	int i, j, sum = 0;	
	if (flag == 1)
		return;
	if (k == -1) {
		if (flag == 0) {			
			for (i = 0; i < N; i++)
				printf("%d ", Arr[i]);
			flag = 1;
		}
		return;
	}
	else {		
		if (S[k][k] == '+') { // Arr[k] > 0
			for (i = 1; i <= 10; i++) {
				sum = i;
				for (j = k + 1; j < N; j++) {
					sum += Arr[j];
					if ((S[k][j] == '+') && (sum <= 0)) // 누적합 > 0
						break;
					else if ((S[k][j] == '-') && (sum >= 0)) // 누적합 < 0
						break;
					else if ((S[k][j] == '0') && (sum != 0)) // 누적합 = 0
						break;
				}
				if (j == N) { // 누적합 조건을 모두 통과한 경우
					Arr[k] = i;				
					BackTracking(Arr, S, N, k - 1);
				}
			}
		}
		else if (S[k][k] == '-') { // Arr[k] < 0
			for (i = -1; i >= -10; i--) {
				sum = i;
				for (j = k + 1; j < N; j++) {
					sum += Arr[j];
					if ((S[k][j] == '+') && (sum <= 0)) // 누적합 > 0
						break;
					else if ((S[k][j] == '-') && (sum >= 0)) // 누적합 < 0
						break;
					else if ((S[k][j] == '0') && (sum != 0)) // 누적합 = 0
						break;
				}
				if (j == N) { // 누적합 조건을 모두 통과한 경우
					Arr[k] = i;
					BackTracking(Arr, S, N, k - 1);
				}
			}
		}
		else if (S[k][k] == '0') { // Arr[k] = 0
			for (j = k + 1; j < N; j++) {
				sum += Arr[j];
				if ((S[k][j] == '+') && (sum <= 0)) // 누적합 > 0
					break;
				else if ((S[k][j] == '-') && (sum >= 0)) // 누적합 < 0
					break;
				else if ((S[k][j] == '0') && (sum != 0)) // 누적합 = 0
					break;
			}
			if (j == N) { // 누적합 조건을 모두 통과한 경우
				Arr[k] = 0;
				BackTracking(Arr, S, N, k - 1);
			}
		}
	}
}