#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, tot;
pii arr[301];
int table[301][50001];
bool path[301][50001];

int DP(int pos, int k);

void solve() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i].first;
		tot += arr[i].first;
		arr[i].second = i;
	}
	sort(arr + 1, arr + N + 1, greater<>());

	memset(table, -1, sizeof(table));
	DP(1, 0);

	vector <int> ans;
	int now = 0;
	for (int i = 1; i <= N; i++) {
		if (now * 2 > tot) break;
		if (path[i][now]) {
			ans.push_back(i);
			now += arr[i].first;
		}
	}

	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++) cout << arr[ans[i]].second << ' ';
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

int DP(int pos, int k) {
	if (pos == N + 1) return 0;
	if (k * 2 > tot) return 0;
	int& ret = table[pos][k];
	if (ret != -1) return ret;
	ret = 0;

	if (DP(pos + 1, k) > arr[pos].first + DP(pos + 1, k + arr[pos].first)) ret = DP(pos + 1, k);
	else {
		path[pos][k] = 1;
		ret = arr[pos].first + DP(pos + 1, k + arr[pos].first);
	}
	return ret;
}