#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int Arr[9][9];

typedef struct {
	int x, y;
}pos;

pos Blank[81];

int canPutNumInSudoku(int N, int x, int y) {
	int i, j;
	int pseudo_x = x % 3;
	int pseudo_y = y % 3;

	for (i = 0; i < 9; i++) {
		if (Arr[i][x] == N)
			return 0;
		if (Arr[y][i] == N)
			return 0;
	}

	for (i = y - pseudo_y; i < y - pseudo_y + 3; i++) {
		for (j = x - pseudo_x; j < x - pseudo_x + 3; j++) {
			if (Arr[i][j] == N)
				return 0;
		}
	}

	return 1;
}

void backTracking(pos * Blank, int count, int M) {
	int i, j, k;
	if (M == 0) {
		for (i = 0; i < 9; i++) {
			for (j = 0; j < 9; j++)
				printf("%d ", Arr[i][j]);
			printf("\n");
		}
		exit(0);		
	}
	else {		
		for (k = 1; k <= 9; k++) {
			if(canPutNumInSudoku(k,Blank[count-M].x,Blank[count - M].y) == 1){
				Arr[Blank[count - M].y][Blank[count - M].x] = k;
				backTracking(Blank, count, M-1);
				Arr[Blank[count - M].y][Blank[count - M].x] = 0;
			}
		}
	}		
}

int main(void) {
	int i, j;	
	int count = 0;	

	for (i = 0; i < 9; i++) {		
		for (j = 0; j < 9; j++) {
			scanf("%d", &Arr[i][j]);
			if (Arr[i][j] == 0) {
				Blank[count].x = j;
				Blank[count].y = i;
				count++;
			}
		}
	}

	backTracking(Blank, count, count);

	return 0;
}