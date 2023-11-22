#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, Q;
int A[100005], B[100005];
int R[100005][2], C[100005][2];

void solve() {
	cin >> N >> Q;
	for (int i = 1; i <= N; i++) {
		int a; cin >> a;
		A[i] = a;
		R[i][a % 2]++;
		R[i][0] += R[i - 1][0];
		R[i][1] += R[i - 1][1];
	}
	for (int i = 1; i <= N; i++) {
		int a; cin >> a;
		B[i] = a;
		C[i][a % 2]++;
		C[i][0] += C[i - 1][0];
		C[i][1] += C[i - 1][1];
	}

	while (Q--) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;

		if ((A[a] + B[b]) % 2 || (A[c] + B[d]) % 2) {
			cout << "NO\n";
			continue;
		}

		if (a > c) swap(a, c);
		if (b > d) swap(b, d);

		if (R[c][(A[a] % 2) ^ 1] == R[a - 1][(A[a] % 2) ^ 1] && C[d][(B[b] % 2) ^ 1] == C[b - 1][(B[b] % 2) ^ 1]) cout << "YES\n";
		else cout << "NO\n";
	}	

	return;
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}