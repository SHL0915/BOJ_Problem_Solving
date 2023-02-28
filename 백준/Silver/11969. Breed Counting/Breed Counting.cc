#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, Q;
int A[100001], B[100001], C[100001];

void solve() {
	cin >> N >> Q;
	for (int i = 1; i <= N; i++) {
		int a; cin >> a;
		if (a == 1) A[i] = 1;
		else if (a == 2) B[i] = 1;
		else C[i] = 1;
	}

	for (int i = 1; i <= N; i++) {
		A[i] += A[i - 1];
		B[i] += B[i - 1];
		C[i] += C[i - 1];
	}

	for (int i = 0; i < Q; i++) {
		int a, b;
		cin >> a >> b;
		cout << A[b] - A[a - 1] << " " << B[b] - B[a - 1] << " " << C[b] - C[a - 1] << '\n';
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