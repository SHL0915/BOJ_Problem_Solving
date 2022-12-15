#include <bits/stdc++.h>
using namespace std;

int ans = 1234567890;
int arr[3][3];
int bt[3][3];
int mark[10];

void BackTracking(int x, int y);
bool check();

int absol(int A) {
	if (A >= 0) return A;
	else return -A;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) cin >> arr[i][j];
	}
	BackTracking(0, 0);
	cout << ans;
	return 0;
}

void BackTracking(int x, int y) {
	if (y == 3) {
		if (check() == true) {
			int cnt = 0;
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) cnt += absol(bt[i][j] - arr[i][j]);
			}
			ans = min(ans, cnt);
		}
		return;
	}
	else {
		for (int i = 1; i <= 9; i++) {
			if (mark[i] == 0) {
				mark[i] = 1;
				bt[y][x] = i;
				BackTracking((x + 1) % 3, y + (x + 1) / 3);
				mark[i] = 0;
			}
		}
	}
}

bool check() {
	int org = 0;
	for (int i = 0; i < 3; i++) org += bt[i][0];
	for (int i = 0; i < 3; i++) {
		int cmp = 0;
		for (int j = 0; j < 3; j++) cmp += bt[i][j];
		if (cmp != org) return false;
		cmp = 0;
		for (int j = 0; j < 3; j++) cmp += bt[j][i];
		if (cmp != org) return false;
	}
	if (bt[0][0] + bt[1][1] + bt[2][2] != org) return false;
	if (bt[0][2] + bt[1][1] + bt[2][0] != org) return false;
	return true;
}