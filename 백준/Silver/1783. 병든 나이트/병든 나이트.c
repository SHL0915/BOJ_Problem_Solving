#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int N, M, count = 1; // 세로의 길이가 N, 가로의 길이가 M인 체스판, 방문한 칸의 수 count
	scanf("%d %d", &N, &M);
	if (M < 7 || (N < 3)) { // 이동 횟수가 4번보다 적은 경우, 가로의 길이가 7보다 작거나 세로의 길이가 3보다 작은 경우에는 4회 이상 이동할 수 없다.
		if (N >= 3) { // 세로의 길이가 3 이상인 경우
			if (M >= 4) // 최대 3번까지 이동 가능
				count += 3;
			else
				count += M - 1;			
		}
		else { // 세로의 길이가 3보다 작은 경우
			if (N == 1); // 세로의 길이가 1인 경우 움직일 수 없다.
			else if ((M - 1) / 2 >= 4) // 최대 3번까지 이동 가능
				count += 3;
			else
				count += (M - 1) / 2;
		}
	}
	else { // 이동 횟수가 4번 이상인 경우
		M -= 7; // 4회 이동
		count += 4;
		count += M; // M번 동안 가로로 1칸씩 이동	
	}
	printf("%d", count);
	return 0;
}

