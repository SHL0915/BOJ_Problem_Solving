#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll mod = 1000000007;

ll D;
ll adj[8][8];
ll res[8][8];

void pre();
void mul();
void pow();

void solve() {
	cin >> D;
	pre();

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) res[i][j] = adj[i][j];
	}

	D--;
	while (D) {
		if (D & 1) mul();
		pow();
		D >>= 1;
	}

	cout << res[0][0];
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

void pre() {
	adj[0][1] = 1;
	adj[0][2] = 1;

	adj[1][0] = 1;
	adj[1][2] = 1;
	adj[1][3] = 1;

	adj[2][0] = 1;
	adj[2][1] = 1;
	adj[2][3] = 1;
	adj[2][4] = 1;

	adj[3][1] = 1;
	adj[3][2] = 1;
	adj[3][4] = 1;
	adj[3][5] = 1;

	adj[4][2] = 1;
	adj[4][3] = 1;
	adj[4][5] = 1;
	adj[4][6] = 1;

	adj[5][3] = 1;
	adj[5][4] = 1;
	adj[5][7] = 1;

	adj[6][4] = 1;
	adj[6][7] = 1;

	adj[7][5] = 1;
	adj[7][6] = 1;
}

void mul() {
	int ret[8][8] = { 0 };
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			for (int k = 0; k < 8; k++) {
				ret[i][j] += (res[i][k] * adj[k][j]) % mod;
				ret[i][j] %= mod;
			}
		}
	}

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) res[i][j] = ret[i][j];
	}

	return;
}

void pow() {
	int ret[8][8] = { 0 };
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			for (int k = 0; k < 8; k++) {
				ret[i][j] += (adj[i][k] * adj[k][j]) % mod;
				ret[i][j] %= mod;
			}
		}
	}

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) adj[i][j] = ret[i][j];
	}

	return;
}