#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, K;
pii arr[100001];
int table[100001];

void solve() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> arr[i].first >> arr[i].second;
	for (int i = 0; i < N; i++) {
		for (int j = K; j >= 0; j--) {
			if (arr[i].first > j) continue;
			table[j] = max(table[j], arr[i].second + table[j - arr[i].first]);
		}
	}
	cout << table[K];
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