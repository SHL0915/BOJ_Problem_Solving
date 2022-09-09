#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

flag = -1;

char min[11]; // 최소 정수를 저장하는 문자열
char max[11]; // 최대 정수를 저장하는 문자열

void BackTracking(char* Arr, int* mark, char* inequality, int N, int k);

int main(void) {
	int k, i, * mark; // 부등호 문자의 개수 k, 중복 여부를 저장할 배열 mark
	char* inequality, * Arr, c; // 부등호를 저장할 배열 inequality, 수열을 주장할 배열 Arr
	scanf("%d", &k);
	inequality = (char*)malloc(sizeof(char) * k);
	Arr = (char*)malloc(sizeof(char) * (k + 2));
	mark = (int*)malloc(sizeof(int) * 10);
	for (i = 0; i < 10; i++)
		mark[i] = 0;
	for (i = 0; i < k; i++) { // 부등호를 입력받아 inequality에 저장
		while (1) {
			c = getchar();
			if (c != ' ' && c != '\n')
				break;
		}
		inequality[i] = c;
	}
	for (i = 0; i < 10; i++) {
		Arr[0] = i + '0';
		mark[i] = 1;
		BackTracking(Arr, mark, inequality, k, 0); // Backtracking을 통해 만족하는 수열을 출력
		mark[i] = 0;
	}
	printf("%s\n%s", max, min); 
	return 0;
}

void BackTracking(char* Arr, int* mark, char* inequality, int N, int k) {
	int i;
	if (k == N) { // 모든 수열이 채워진 경우
		Arr[N + 1] = '\0';
		if (flag == -1) { // 최소 정수인 경우
			for (i = 0; i <= N; i++) {
				min[i] = Arr[i];
			}
			min[N + 1] = '\0';
			flag = 0;
		}
		for (i = 0; i <= N; i++) {
			max[i] = Arr[i];
		}
		max[N + 1] = '\0';
		return;
	}
	else {
		for (i = 0; i < 10; i++) {
			if (mark[i] != 0)
				continue;
			else {
				if (inequality[k] == '<') { // 왼쪽 수보다 큰 수가 와야 한다
					if (i > Arr[k] - '0') {
						Arr[k + 1] = i +'0';						
						mark[i] = 1;
						BackTracking(Arr, mark, inequality, N, k + 1);
						mark[i] = 0;
					}
				}
				else { // 왼쪽 수보다 작은 수가 와야 한다
					if (i < Arr[k] - '0') {
						Arr[k + 1] = i + '0';
						mark[i] = 1;
						BackTracking(Arr, mark, inequality, N, k + 1);
						mark[i] = 0;
					}
				}
			}
		}
	}
}