#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

int N;
vector <pair<pii, pii>> arr;
vector <ll> x_val, y_val;
vector <ll> seg, cnt;

void update(int node, int start, int end, int left, int right, ll val);

void solve() {
	cin >> N;

	seg.resize(8 * N);
	cnt.resize(8 * N);

	for (int i = 0; i < N; i++) {
		ll x1, x2, y1, y2;
		cin >> x1 >> x2 >> y1 >> y2;
		x_val.push_back(x1); x_val.push_back(x2);
		y_val.push_back(y1); y_val.push_back(y2);
		arr.push_back({ {x1, 1}, {y1, y2} });
		arr.push_back({ {x2, -1}, {y1,y2} });
	}

	sort(x_val.begin(), x_val.end());
	x_val.erase(unique(x_val.begin(), x_val.end()), x_val.end());

	sort(y_val.begin(), y_val.end());
	y_val.erase(unique(y_val.begin(), y_val.end()), y_val.end());

	for (int i = 0; i < arr.size(); i++) {
		arr[i].first.first = lower_bound(x_val.begin(), x_val.end(), arr[i].first.first) - x_val.begin();
		arr[i].second.first = lower_bound(y_val.begin(), y_val.end(), arr[i].second.first) - y_val.begin();
		arr[i].second.second = lower_bound(y_val.begin(), y_val.end(), arr[i].second.second) - y_val.begin();
	}

	sort(arr.begin(), arr.end());
	update(1, 0, 2 * N, arr[0].second.first, arr[0].second.second - 1, arr[0].first.second);

	ll ans = 0;
	for (int i = 1; i < arr.size(); i++) {
		ans += seg[1] * (x_val[arr[i].first.first] - x_val[arr[i - 1].first.first]);
		update(1, 0, 2 * N, arr[i].second.first, arr[i].second.second - 1, arr[i].first.second);
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

void update(int node, int start, int end, int left, int right, ll val) {
	if (left > end || right < start) return;
	if (left <= start && end <= right) cnt[node] += val;
	else {
		int mid = (start + end) / 2;
		update(node * 2, start, mid, left, right, val);
		update(node * 2 + 1, mid + 1, end, left, right, val);
	}
	if (cnt[node]) seg[node] = y_val[end + 1] - y_val[start];
	else {
		if (start == end) seg[node] = 0;
		else seg[node] = seg[node * 2] + seg[node * 2 + 1];
	}
	return;
}