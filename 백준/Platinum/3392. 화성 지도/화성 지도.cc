#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int SZ = 30000;

int N;
vector<pair<pii, pii>> arr;
vector <int> seg, cnt;

void update(int node, int start, int end, int left, int right, int val);

void solve() {
	cin >> N;
	seg.resize(4 * SZ);
	cnt.resize(4 * SZ);
	for (int i = 0; i < N; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		arr.push_back({ {x1,1 }, {y1,y2 - 1} });
		arr.push_back({ {x2,-1}, {y1,y2 - 1} });
	}

	sort(arr.begin(), arr.end());

	update(1, 0, SZ, arr[0].second.first, arr[0].second.second, arr[0].first.second);
	int ans = 0;
	for (int i = 1; i < arr.size(); i++) {
		ans += seg[1] * (arr[i].first.first - arr[i - 1].first.first);
		update(1, 0, SZ, arr[i].second.first, arr[i].second.second, arr[i].first.second);
	}
	
	cout << ans;
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

void update(int node, int start, int end, int left, int right, int val) {
	if (left > end || right < start) return;
	if (left <= start && end <= right) cnt[node] += val;
	else {
		int mid = (start + end) / 2;
		update(node * 2, start, mid, left, right, val);
		update(node * 2 + 1, mid + 1, end, left, right, val);
	}
	if (cnt[node]) seg[node] = end - start + 1;
	else {
		if (start == end) seg[node] = 0;
		else seg[node] = seg[node * 2] + seg[node * 2 + 1];
	}
	return;
}