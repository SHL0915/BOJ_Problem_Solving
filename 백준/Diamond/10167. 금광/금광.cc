#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;

struct seg_node {
	ll f, b, max_val, sum;

	seg_node() {
		f = -INF;
		b = -INF;
		max_val = -INF;
		sum = 0;
	}
};

int N;
pair<pii, ll> arr[3001];
vector <int> x_val, y_val;
vector <seg_node> seg;

void update(int node, int start, int end, int idx, ll val);
seg_node query(int node, int start, int end, int left, int right);

void solve() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i].first.first >> arr[i].first.second >> arr[i].second;
		x_val.push_back(arr[i].first.first);
		y_val.push_back(arr[i].first.second);
	}

	sort(arr + 1, arr + 1 + N);

	sort(x_val.begin(), x_val.end()); 
	x_val.erase(unique(x_val.begin(), x_val.end()), x_val.end());
	sort(y_val.begin(), y_val.end());
	y_val.erase(unique(y_val.begin(), y_val.end()), y_val.end());

	for (int i = 1; i <= N; i++) {
		arr[i].first.first = lower_bound(x_val.begin(), x_val.end(), arr[i].first.first) - x_val.begin() + 1;
		arr[i].first.second = lower_bound(y_val.begin(), y_val.end(), arr[i].first.second) - y_val.begin() + 1;
	}

	ll ans = -INF;

	for (int i = 1; i <= N; i++) {
		if (arr[i].first.first == arr[i - 1].first.first) continue;
		seg.clear();
		seg.resize(4 * N);
		for (int j = i; j <= N; j++) {
			update(1, 1, N, arr[j].first.second, arr[j].second);
			if (j == N || arr[j].first.first != arr[j + 1].first.first) ans = max(ans, query(1, 1, N, 1, N).max_val);			
		}
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

void update(int node, int start, int end, int idx, ll val) {
	if (idx > end || idx < start) return;
	if (start == end) {
		if (seg[node].max_val == -INF) {
			seg[node].f = val;
			seg[node].b = val;
			seg[node].max_val = val;
			seg[node].sum = val;
		}
		else {
			seg[node].f += val;
			seg[node].b += val;
			seg[node].max_val += val;
			seg[node].sum += val;
		}
		return;
	}

	int mid = (start + end) / 2;
	update(node * 2, start, mid, idx, val);
	update(node * 2 + 1, mid + 1, end, idx, val);

	seg_node& l = seg[node * 2], & r = seg[node * 2 + 1];

	seg[node].f = max(l.f, l.sum + r.f);
	seg[node].b = max(r.b, r.sum + l.b);
	seg[node].sum = l.sum + r.sum;
	seg[node].max_val = max({ l.max_val, r.max_val, l.b + r.f });

	return;
}

seg_node query(int node, int start, int end, int left, int right) {
	if (left > end || right < start) {
		seg_node empty;
		return empty;
	}
	if (left <= start && end <= right) return seg[node];
	int mid = (start + end) / 2;

	seg_node ret;
	seg_node l = query(node * 2, start, mid, left, right);
	seg_node r = query(node * 2 + 1, mid + 1, end, left, right);

	ret.f = max(l.f, l.sum + r.f);
	ret.b = max(r.b, r.sum + l.b);
	ret.sum = l.sum + r.sum;
	ret.max_val = max({ l.max_val, r.max_val, l.b + r.f });

	return ret;
}