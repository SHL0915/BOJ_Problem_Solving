#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll mod = 1000000007;

int N, K;
ll arr[101][101];
ll res[101][101];

void mul();
void sqr();

void solve() {
	cin >> N >> K;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			res[i][j] = arr[i][j];
		}
	}

	K--;

	ll bit = 1;
	while (bit <= K) {
		if (bit & K) mul();
		sqr();
		bit <<= 1;
	}

	ll ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			ans += res[i][j];
			ans %= mod;
		}
	}

	cout << ans;
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

void mul() {
	ll ret[101][101] = { 0 };

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				ret[i][j] += res[i][k] * arr[k][j];
				ret[i][j] %= mod;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) res[i][j] = ret[i][j];
	}

	return;
}

void sqr() {
	ll ret[101][101] = { 0 };

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				ret[i][j] += arr[i][k] * arr[k][j];
				ret[i][j] %= mod;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) arr[i][j] = ret[i][j];
	}

	return;
}