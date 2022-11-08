#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int board[5][5];
vector <int> nums;

void BackTracking(int x, int y, int k, int n);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) cin >> board[i][j];
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			BackTracking(j, i, 1, board[i][j]);
		}
	}
	sort(nums.begin(), nums.end());
	nums.erase(unique(nums.begin(), nums.end()), nums.end());
	cout << nums.size();
	return 0;
}

void BackTracking(int x, int y, int k, int n) {
	if (k == 6) {
		nums.push_back(n);
		return;
	}
	else {
		int temp = 1;
		for (int i = 0; i < k; i++) temp *= 10;
		if (x > 0) BackTracking(x - 1, y, k + 1, n + temp * board[y][x - 1]);
		if (x < 4) BackTracking(x + 1, y, k + 1, n + temp * board[y][x + 1]);
		if (y > 0) BackTracking(x, y - 1, k + 1, n + temp * board[y - 1][x]);
		if (y < 4) BackTracking(x, y + 1, k + 1, n + temp * board[y + 1][x]);

	}
}