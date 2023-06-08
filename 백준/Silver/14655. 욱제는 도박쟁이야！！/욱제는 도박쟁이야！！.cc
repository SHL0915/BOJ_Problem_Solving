#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
int A[10005], B[10005];

void solve() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];
	for (int i = 0; i < N; i++) cin >> B[i];
		
	ll sum = 0;
	for (int i = 0; i < N; i++) {
		sum += abs(A[i]);
		sum += abs(B[i]);
	}

	cout << sum;
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