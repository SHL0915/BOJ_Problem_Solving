#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int A, B;

void solve() {
	cin >> A >> B;
	if (A >= 3 && B <= 4) cout << "TroyMartian\n";
	if (A <= 6 && B >= 2) cout << "VladSaturnian\n";
	if (A <= 2 && B <= 3) cout << "GraemeMercurian\n";

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