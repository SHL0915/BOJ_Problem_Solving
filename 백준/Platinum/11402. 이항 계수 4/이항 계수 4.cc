#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

ll N, K, M, ans = 1;
int table[2001][2001];
pii arr[100];

int nCr(int n, int r);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> K >> M;
	ll idx = 0;
	while (N) {
		arr[idx++] = { N % M, K % M };
		N /= M; K /= M;
	}
	for (int i = 0; i < idx; i++) ans = (ans * nCr(arr[i].first, arr[i].second) % M) % M;	
	cout << ans;
	return 0;
}

int nCr(int n, int r) {
	if (r > n) return 0;
	if (r == 0 || r == n) return 1;
	if (table[n][r] == 0) table[n][r] = (nCr(n - 1, r) + nCr(n - 1, r - 1)) % M;
	return table[n][r];
}