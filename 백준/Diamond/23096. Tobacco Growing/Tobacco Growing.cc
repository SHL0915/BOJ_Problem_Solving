#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

ll N;
ll arr[64][64];

void solve() {
	cin >> N;

	arr[0][0] = 1;
	for (int i = 1; i < 64; i++) {
		for (int j = 0; j < 64; j++) {
			if (j == 0) arr[i][j] = arr[i - 1][0] + arr[i - 1][1];
			else if (j == 63) arr[i][j] = arr[i - 1][62] + arr[i - 1][63];
			else arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j] + arr[i - 1][j + 1];
		}
	}

	priority_queue<pair<ll, pii>> pq;
	vector<pair<pii, int>> in;

	for (int i = 0; i < 40; i++) {
		for (int j = 0; j < 10; j++) {
			if (i == 0) in.push_back({ { i, j * 2 }, 1 });
			else in.push_back({ { i, j * 2 }, 0 });
			pq.push({ arr[39][i],{ i, j * 2 } });
		}
	}

	vector<pii> ans;
	while (pq.size()) {
		pair<ll, pii> t = pq.top();
		pq.pop();
		if (t.first > N) continue;
		ans.push_back(t.second);
		N -= t.first;
	}

	for (int i = 0; i < N; i++) {
		in.push_back({ { 50, i * 2 }, 1 });
		ans.push_back({ 50, i * 2 });
	}

	assert(in.size() <= 200000);
	assert(ans.size() <= 10000);

	cout << in.size() << '\n';
	for (auto a : in) cout << a.first.first << " " << a.first.second << " " << a.second << '\n';

	cout << ans.size() << " " << 39 << '\n';
	for (auto a : ans) cout << a.first << " " << a.second << '\n';

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