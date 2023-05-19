#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int A, B, C, D;

void solve() {
	cin >> A >> B >> C >> D;
	C += D;
	B += C / 60;
	C %= 60;
	A += B / 60;
	B %= 60;
	A %= 24;

	cout << A << " " << B << " " << C;
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