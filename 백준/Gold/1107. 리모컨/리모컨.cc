#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

int N, M, ans = INF;
int mark[10];
int bt[7];

void BackTracking(int k);
int absol(int a);

void solve() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a;
		cin >> a;
		mark[a] = 1;
	}
	BackTracking(0);
	cout << ans;
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}

void BackTracking(int k) {
	int now = 0;
	for (int i = 0; i < k; i++) {
		now *= 10;
		now += bt[i];
	}
	if (k == 0) now = 100;
	ans = min(ans, k + absol(now - N));
	if (k == 7) return;
	else {
		for (int i = 0; i <= 9; i++) {
			if (mark[i] == 0) {
				bt[k] = i;
				BackTracking(k + 1);
			}
		}
	}
}

int absol(int a) {
	if (a < 0) return -a;
	else return a;
}