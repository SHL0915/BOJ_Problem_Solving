#include <bits/stdc++.h>
using namespace std;

int R, C, ans;
int arr[750][750];
int lu[750][750];
int ru[750][750];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < C; j++) arr[i][j] = s[j] - '0';
	}
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (arr[i][j] == 1) {
				lu[i][j] = 1;
				ru[i][j] = 1;
				if (i > 0 && j > 0) lu[i][j] = max(lu[i][j], lu[i - 1][j - 1] + 1);
				if (i > 0 && j < C - 1) ru[i][j] = max(ru[i][j], ru[i - 1][j + 1] + 1);
			}
		}
	}
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			for (int k = 1; ; k++) {
				int nx1 = j - (k - 1);
				int nx2 = j + (k - 1);
				int ny = i + (k - 1);
				if (nx1 < 0 || nx2 > C - 1 || ny > R - 1) break;
				if (lu[i][nx2] >= k && ru[i][nx1] >= k && lu[ny][j] >= k && ru[ny][j] >= k) ans = max(ans, k);
			}
		}
	}
	cout << ans;
	return 0;
}