#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, ans = -101;

void BackTracking(int arr[6][6], int height, int width, int row, int column);

int main(void) {
	cin >> N >> M;
	int org[6][6];
	for (int i = 0; i < N; i++) {		
		for (int j = 0; j < M; j++) {
			cin >> org[i][j];
		}
	}
	BackTracking(org, N, M, 0, 0);
	cout << ans;	
	return 0;
}

void BackTracking(int arr[6][6], int prev_height, int prev_width, int row, int column) {
	int height = max(prev_height - row, row);
	int width = max(prev_width - column, column);
	int temp[6][6];
	if (row == 0) { // 가로로 접은 경우
		if (width > column) {
			for (int i = 0; i < height; i++) {
				for (int j = 0; j < width; j++) {
					if (j < column) temp[i][j] = arr[i][column + j] + arr[i][column - j - 1];
					else temp[i][j] = arr[i][column + j];					
				}
			}
		}
		else {
			for (int i = 0; i < height; i++) {
				for (int j = 0; j < width; j++) {
					if (j < prev_width - column) temp[i][width - 1 - j] = arr[i][width - 1 - j] + arr[i][width + j];
					else temp[i][width - 1 - j] = arr[i][width - 1 - j];					
				}
			}
		}
	} // 세로로 접은 경우
	else {
		if (height > row) {
			for (int i = 0; i < height; i++) {
				for (int j = 0; j < width; j++) {
					if (i < row) temp[i][j] = arr[i + row][j] + arr[row - 1 - i][j];
					else temp[i][j] = arr[i + row][j];					
				}
			}
		}
		else {
			for (int i = 0; i < height; i++) {
				for (int j = 0; j < width; j++) {
					if (i < prev_height - row) temp[height - 1 - i][j] = arr[height - 1 - i][j] + arr[height + i][j];
					else temp[height - 1 - i][j] = arr[height - 1 - i][j];					
				}
			}
		}
	}
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++)
			ans = max(ans, temp[i][j]);
	}
	if (height == 1 && width == 1) {		
		return;
	}
	else {
		for (int i = 0; i < height; i++) {
			if (i == 0) {
				for (int j = 1; j < width; j++) 
					BackTracking(temp, height, width, 0, j);				
			}
			else {
				BackTracking(temp, height, width, i, 0);
			}
		}		
		return;
	}
}