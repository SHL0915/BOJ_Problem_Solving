#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, K;
priority_queue <ll> A, B, C;

void solve() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		A.push(a + b);
		B.push(a + c);
		C.push(b + c);
	}

	ll a = 0, b = 0, c = 0;
	for (int i = 0; i < K; i++) {
		a += A.top(); A.pop();
		b += B.top(); B.pop();
		c += C.top(); C.pop();
	}

	cout << max({ a,b,c });
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