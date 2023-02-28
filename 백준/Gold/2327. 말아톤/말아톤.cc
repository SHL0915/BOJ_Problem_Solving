#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

int H, N;
pii arr[351];
int table[100001];

void solve() {
	cin >> H >> N;
	for (int i = 1; i <= N; i++) cin >> arr[i].first >> arr[i].second;

	for (int i = 1; i <= N; i++) {
		for (int j = H; j >= 0; j--) {
			if (j == arr[i].first) {
				table[j] = max(table[j], arr[i].second);
				continue;
			}
			if (j < arr[i].first) continue;
			if (table[j - arr[i].first] == 0) continue;
			table[j] = max(table[j], min(table[j - arr[i].first], arr[i].second));
		}
	}

	cout << table[H];
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