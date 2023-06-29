#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
int arr[505][505];
int basis[505];
int ans[505][505];
int mark[505];

void solve() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			if(i == j) ans[i][j] = 1;
		}
	}

	for (int i = 0; i < N; i++) {
		int idx = -1;
		for (int j = 0; j < N; j++) {
            if(mark[j]) continue;
			if (arr[j][i] == 1) {
				idx = j;
				break;
			}
		}

		if (idx == -1) {
			cout << -1;
			return;
		}
		basis[i] = idx;
        mark[idx] = 1;

		for (int j = 0; j < N; j++) {
            if(mark[j]) continue;
			if (arr[j][i] == 0) continue;
			for (int k = 0; k < N; k++) arr[j][k] ^= arr[idx][k];
			for (int k = 0; k < N; k++) ans[j][k] ^= ans[idx][k];
		}
	}

	for (int i = 0; i < N; i++) {
		int idx = basis[i];
		for (int j = i + 1; j < N; j++) {
			if (arr[idx][j] == 0) continue;
			int next = basis[j];

			for (int k = 0; k < N; k++) ans[idx][k] ^= ans[next][k];
			for (int k = 0; k < N; k++) arr[idx][k] ^= arr[next][k];
		}
	}

	for (int i = 0; i < N; i++) {
		int idx = basis[i];
		for (int j = 0; j < N; j++) {
			if (ans[idx][j] == 1) cout << j + 1 << " ";
		}
		cout << '\n';
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