#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;

int N, M, H, ans = INF;
int mark[31][11];

int check();
int go(int idx);
void BackTracking(int x, int y, int k);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M >> H;
	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;
		mark[A][B] = 1;
	}
	if (check() == 1) ans = min(ans, 0);
	BackTracking(1, 1, 0);
	if (ans == INF) cout << -1;
	else cout << ans;
	return 0;
}

int check() {
	for (int i = 1; i <= N; i++) {
		if (go(i) != i) break;
		if (i == N) return 1;
	}
	return 0;
}

int go(int idx) {
	int now = idx;
	for (int i = 1; i <= H; i++) {
		if (mark[i][now] == 1) now = now + 1;
		else if (mark[i][now - 1] == 1) now = now - 1;
	}
	return now;
}

void BackTracking(int x, int y, int k) {
	if (k == 3) return;
	else {
		for (int i = 1; i <= H; i++) {
			for (int j = 1; j < N; j++) {
				if (i < y) continue;
				else if (i == y && j < x) continue;
				if (mark[i][j - 1] == 0 && mark[i][j] == 0 && mark[i][j + 1] == 0) {
					mark[i][j] = 1;
					BackTracking(j, i, k + 1);
					if (check() == 1) ans = min(ans, k + 1);
					mark[i][j] = 0;
				}
			}
		}
	}
}