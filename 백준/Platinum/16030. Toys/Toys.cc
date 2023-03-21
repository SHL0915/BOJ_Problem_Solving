#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
set <int> ans;

void f(int a, int sum);

void solve() {
	cin >> N;
	f(N, 0);

	cout << ans.size() << '\n';
	for (auto i = ans.begin(); i != ans.end(); i++) cout << (*i) << " ";
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

void f(int a, int sum) {
	for (ll i = 2; i * i <= a; i++) {
		if (a % i == 0) {
			f(i, sum + a / i - 1);
			if (i * i != a) f(a / i, sum + i - 1);
		}
	}
	ans.insert(sum + a - 1);
	return;
}