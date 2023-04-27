#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int H1, W1, H2, W2;
int A[100][100];
int B[100][100];

int cmp(int x1, int y1, int x2, int y2);

void solve() {
	cin >> H1 >> W1;
	int cnt = 0, ans = 0;
	for (int i = 0; i < H1; i++) {
		string s; cin >> s;
		for (int j = 0; j < W1; j++) {
			if (s[j] == 'O') {
				A[i][j] = 1;
				cnt++;
			}
		}
	}

	cin >> H2 >> W2;

	for (int i = 0; i < H2; i++) {
		string s; cin >> s;
		for (int j = 0; j < W2; j++) {
			if (s[j] == 'O') B[i][j] = 1;
		}
	}

	for (int x1 = 0; x1 < 10; x1++) {
		for (int y1 = 0; y1 < 10; y1++) {
			for (int x2 = 0; x2 < 10; x2++) {
				for (int y2 = 0; y2 < 10; y2++) {
					ans = max(ans, cmp(x1, y1, x2, y2));
				}
			}
		}
	}


	cout << cnt - ans;
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

int cmp(int x1, int y1, int x2, int y2) {
	int cnt = 0;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (A[i + y1][j + x1] == 1 && B[i + y2][j + x2] == 1) cnt++;
		}
	}

	return cnt;
}