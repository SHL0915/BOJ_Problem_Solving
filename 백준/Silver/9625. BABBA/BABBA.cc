#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

int N;

pii f(int k, ll a, ll b);

void solve() {
	cin >> N;
	pii ans = f(0, 1, 0);
	cout << ans.first << " " << ans.second;
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}

pii f(int k, ll a, ll b) {
	if (k == N) return { a,b };
	else return f(k + 1, b, a + b);
}