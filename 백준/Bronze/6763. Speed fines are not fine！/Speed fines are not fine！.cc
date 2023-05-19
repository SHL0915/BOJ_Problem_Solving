#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int A, B;

void solve() {
	cin >> A >> B;
	B -= A;

	if (B <= 0) cout << "Congratulations, you are within the speed limit!";
	else if (B <= 20) cout << "You are speeding and your fine is $100.";
	else if (B <= 30) cout << "You are speeding and your fine is $270.";
	else cout << "You are speeding and your fine is $500.";
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