#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int x, y, val;
}arrdata;

void Merge(arrdata* Arr, arrdata* temp, int left, int right, int right_end) {
	int i, j, pos;
	i = left;
	j = right;
	pos = left;
	while (i < right && j <= right_end) {
		if (Arr[i].val <= Arr[j].val) {
			temp[pos].x = Arr[i].x;
			temp[pos].y = Arr[i].y;
			temp[pos].val = Arr[i].val;
			i++;
			pos++;
		}
		else {
			temp[pos].x = Arr[j].x;
			temp[pos].y = Arr[j].y;
			temp[pos].val = Arr[j].val;
			j++;
			pos++;
		}
	}
	while (i < right) {
		temp[pos].x = Arr[i].x;
		temp[pos].y = Arr[i].y;
		temp[pos].val = Arr[i].val;
		i++;
		pos++;
	}
	while (j <= right_end) {
		temp[pos].x = Arr[j].x;
		temp[pos].y = Arr[j].y;
		temp[pos].val = Arr[j].val;
		j++;
		pos++;
	}
	for (i = left; i <= right_end; i++) {
		Arr[i].x = temp[i].x;
		Arr[i].y = temp[i].y;
		Arr[i].val = temp[i].val;
	}	
}

void MergeSort(arrdata* Arr, arrdata* temp, int left, int right_end) {
	int mid = (left + right_end) / 2;
	if (left < right_end) {
		MergeSort(Arr, temp, left, mid);
		MergeSort(Arr, temp, mid + 1, right_end);
		Merge(Arr, temp, left, mid + 1, right_end);
	}
}

int main(void) {
	int R, C, ** Arr, i, j, k, min_x, min_y, flag = 0; // 크기가 R*C인 배열 Arr, 방문하지 않을 칸의 좌표 (min_x,min_y)
	arrdata* sort, * temp; // 행복의 크기에 대하여 오름차순으로 정렬할 배열 sort
	scanf("%d %d", &R, &C);
	Arr = (int**)malloc(sizeof(int*) * R);
	sort = (arrdata*)malloc(sizeof(arrdata) * R * C);
	temp = (arrdata*)malloc(sizeof(arrdata) * R * C);
	k = 0; // sort의 index k
	for (i = 0; i < R; i++) {
		Arr[i] = (int*)malloc(sizeof(int) * C);
		for (j = 0; j < C; j++) {
			scanf("%d", &Arr[i][j]);
			sort[k].x = j;
			sort[k].y = i;
			sort[k].val = Arr[i][j];
			k++;
		}
	}	
	if ((R % 2 == 1) || (C % 2 == 1)) { // 행이나 열의 개수가 홀수인 경우, 모든 칸을 방문할 수 있다.
		if (R % 2 == 1) { // 행의 개수가 홀수인 경우
			for (i = 0; i < C - 1; i++)
				printf("R");
			for (i = 0; i < R - 1; i++) {
				printf("D");
				for (j = 0; j < C - 1; j++) {
					if (i % 2 == 0)
						printf("L");
					else
						printf("R");
				}
			}
		}
		else { // 열의 개수가 홀수인 경우
			for (i = 0; i < R - 1; i++)
				printf("D");
			for (i = 0; i < C - 1; i++) {
				printf("R");
				for (j = 0; j < R - 1; j++) {
					if (i % 2 == 0)
						printf("U");
					else
						printf("D");
				}
			}
		}
	}
	else { // 행과 열의 개수가 모두 짝수인 경우, 방문하지 않을 칸을 한 개 골라야 한다.
		MergeSort(sort, temp, 0, k - 1); // 행복의 크기에 대하여 오름차순으로 정렬
		k = 0;
		while (1) { // min_x와 min_y가 모두 짝수거나 모두 홀수라면, 오직 한 칸만을 미방문하는 것이 불가능하다.
			min_x = sort[k].x;
			min_y = sort[k].y;
			k++;
			if ((min_x + min_y) % 2 == 1)
				break;			
		}
		if (min_x % 2 == 1) { // min_x가 홀수인 경우
			for (i = 0; i < min_y; i++) {
				for (j = 0; j < C - 1; j++) {
					if (i % 2 == 0)
						printf("R");
					else
						printf("L");
				}				
				printf("D");				
			}			
			for (i = 0; i < min_x - 1; i++) {
				for (j = 0; j < R - min_y - 1; j++) {
					if (i % 2 == 0)
						printf("D");
					else
						printf("U");				
				}				
				printf("R");				
			}			
			for (i = 0; i < R - min_y - 1; i++) {
				printf("D");
				if (i % 2 == 0)
					printf("R");
				else
					printf("L");
			}
			for (i = 0; i < C - min_x - 1; i++) {
				printf("R");
				for (j = 0; j < R - min_y - 1; j++) {
					if (i % 2 == 0)
						printf("U");
					else
						printf("D");
				}
			}
		}
		else { // min_y가 홀수인 경우
			for (i = 0; i < min_y - 1; i++) {
				for (j = 0; j < C - 1; j++) {
					if (i % 2 == 0)
						printf("R");
					else
						printf("L");
				}				
				printf("D");				
			}			
			for (i = 0; i < min_x; i++) {
				for (j = 0; j < R - min_y; j++) {
					if (i % 2 == 0)
						printf("D");
					else
						printf("U");
				}				
				printf("R");				
			}			
			printf("RD");
			for (i = 0; i < R - min_y - 1; i++) {
				printf("D");
				if (i % 2 == 0)
					printf("L");
				else
					printf("R");
			}
			for (i = 0; i < C - min_x - 2; i++) {
				printf("R");
				for (j = 0; j < R - min_y; j++) {
					if (i % 2 == 0)
						printf("U");
					else
						printf("D");
				}
			}		
		}
	}
}