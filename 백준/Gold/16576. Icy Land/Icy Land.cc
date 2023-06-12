#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

int R, C;
int arr[505][505];

void solve() {
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		string s; cin >> s;
		for (int j = 0; j < C; j++) {
			if (s[j] == '.') arr[i][j] = 0;
			else arr[i][j] = 1;
		}
	}

	if (R <= 2) {
		int cnt = 0;
		for (int i = 1; i < C - 1; i++) {
			int flag = 0;
			for (int j = 0; j < R; j++) flag |= arr[j][i];
			if (flag == 0) cnt++;
		}
		cout << cnt;
	}
	else if (C <= 2) {
		int cnt = 0;
		for (int i = 1; i < R - 1; i++) {
			int flag = 0;
			for (int j = 0; j < C; j++) flag |= arr[i][j];
			if (flag == 0) cnt++;
		}
		cout << cnt;
	}
	else {
		int cnt = 0;
		for (int i = 1; i < R - 1; i++) {
			for (int j = 1; j < C - 1; j++) {
				if (arr[i][j] == 0) cnt++;
			}
		}

		int flag = 0;

		for (int i = 1; i < R - 1; i++) if (arr[i][0] == 1 || arr[i][C - 1]) flag = 1;
		for (int i = 1; i < C - 1; i++) if (arr[0][i] == 1 || arr[R - 1][i]) flag = 1;

		if (flag == 0) cnt++;

		cout << cnt;
	}
	
	return;
}

int main(void) {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}