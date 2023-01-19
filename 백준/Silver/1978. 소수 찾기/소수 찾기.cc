#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
int table[1001];

void solve() {
	cin >> N;
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		int a; cin >> a;
		cnt += (table[a] == 0);
	}
	cout << cnt << '\n';
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	table[1] = 1;
	for (int i = 2; i <= 1000; i++) {
		if (table[i] == 0) {
			for (int j = i * i; j <= 1000; j += i) table[j] = 1;
		}
	}
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}