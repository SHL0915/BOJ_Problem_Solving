#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int A, B, C, D;

void solve() {
	cin >> A >> B >> C >> D;
	if (A > B && B > C && C > D) cout << "Fish Diving";
	else if (A < B && B < C && C < D) cout << "Fish Rising";
	else if (A == B && B == C && C == D) cout << "Fish At Constant Depth";
	else cout << "No Fish";

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