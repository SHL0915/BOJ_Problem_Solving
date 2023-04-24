#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

ll N, K, mod;
ll res[105][105];
ll arr[105][105];

void mul();
void pow();

void solve() {
	cin >> N >> K;
	for (int i = 0; i < K; i++) cin >> res[0][i];
	cin >> mod;
	for (int i = 1; i < K; i++) arr[i][i - 1] = 1;
	for (int i = 0; i < K; i++) arr[i][K - 1] = 1;

	N -= K;
	while (N) {
		if (N % 2) mul();
		pow();
		N /= 2;
	}

	cout << res[0][K - 1];
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
	ll temp[105][105] = { 0 };
	for (int i = 0; i < K; i++) {
		for (int j = 0; j < K; j++) {
			for (int k = 0; k < K; k++) {
				temp[i][j] += (res[i][k] * arr[k][j]) % mod;
				temp[i][j] %= mod;
			}
		}
	}

	for (int i = 0; i < K; i++) {
		for (int j = 0; j < K; j++) res[i][j] = temp[i][j];
	}
	return;
}

void pow() {
	ll temp[105][105] = { 0 };
	for (int i = 0; i < K; i++) {
		for (int j = 0; j < K; j++) {
			for (int k = 0; k < K; k++) {
				temp[i][j] += (arr[i][k] * arr[k][j]) % mod;
				temp[i][j] %= mod;
			}
		}
	}

	for (int i = 0; i < K; i++) {
		for (int j = 0; j < K; j++) arr[i][j] = temp[i][j];
	}
	return;
}