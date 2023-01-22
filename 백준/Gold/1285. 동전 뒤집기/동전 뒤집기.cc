#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

int N, ans = INF;
int org[21][21];
int mark[21];

void BF();

void solve() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		string s; cin >> s;
		for (int j = 0; j < N; j++) {
			if (s[j] == 'H') org[i][j] = 1;
			else org[i][j] = 0;
		}
	}
	for (int i = 0; i < (1 << N); i++) {
		int bit = 1, idx = 0;
		memset(mark, 0, sizeof(mark));
		while (bit <= i) {
			if (bit & i) mark[idx] = 1;
			idx++;
			bit <<= 1;
		}
		BF();
	}
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

void BF() {
	int sum = 0;
	for (int i = 0; i < N; i++) { // 행
		int cnt = 0;
		for (int j = 0; j < N; j++) { // 열
			if (mark[j]) cnt += org[j][i] ^ 1;
			else cnt += org[j][i];
		}
		sum += min(cnt, N - cnt);
	}
	ans = min(ans, sum);
	return;
}