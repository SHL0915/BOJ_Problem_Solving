#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M;
set <int> s;

void solve() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a; cin >> a;
		s.insert(a);
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		int a; cin >> a;
		cout << s.count(a) << " ";
	}
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