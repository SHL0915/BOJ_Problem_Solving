#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
int A[100005], B[100005], C[100005];

void solve() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		char c; cin >> c;
		if (c == 'H') A[i]++;
		if (c == 'P') B[i]++;
		if (c == 'S') C[i]++;
		A[i] += A[i - 1];
		B[i] += B[i - 1];
		C[i] += C[i - 1];
	}

	int ans = 0;
	for (int i = 1; i <= N; i++) ans = max(ans, max({A[i],B[i],C[i]}) + max({A[N] - A[i], B[N] - B[i], C[N] - C[i]}));
	
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