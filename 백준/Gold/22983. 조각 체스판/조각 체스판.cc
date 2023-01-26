#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M;
int arr[3001][3001];
int table[3001][3001];
int A[3001][3001], B[3001][3001];

void solve() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		string s;
		cin >> s;
		for (int j = 1; j <= M; j++) {
			if (s[j - 1] == 'B') arr[i][j] = 0;
			else arr[i][j] = 1;
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			A[i][j] = 1;
			if (j == 1) continue;
			if (arr[i][j] == (arr[i][j - 1] ^ 1)) A[i][j] = max(A[i][j], 1 + A[i][j - 1]);			
		}
	}
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			B[j][i] = 1;
			if (j == 1) continue;
			if (arr[j][i] == (arr[j - 1][i] ^ 1)) B[j][i] = max(B[j][i], 1 + B[j - 1][i]);
		}
	}
	ll ans = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			table[i][j] = 1;
			if (i == 1 || j == 1) continue;
			if (arr[i][j] == arr[i - 1][j - 1]) table[i][j] = max(table[i][j], min({ table[i - 1][j - 1] + 1, A[i][j], B[i][j] }));		
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) ans += table[i][j];
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