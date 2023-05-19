#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int L, A, B, C, D;

void solve() {
	cin >> L >> A >> B >> C >> D;
	int a = A / C;
	if (A % C) a++;
	int b = B / D;
	if (B % D) b++;

	cout << L - max(a, b);
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