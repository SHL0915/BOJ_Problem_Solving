#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, Q;
int arr[500005], ans[500005];
int seg[1000005];
vector <int> cnt[500005], val;
vector <pair<pii, int>> q;

void update(int pos, int val);
int query(int l, int r);

void solve() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		val.push_back(arr[i]);
	}
	sort(val.begin(), val.end());
	val.erase(unique(val.begin(), val.end()), val.end());

	for (int i = 1; i <= N; i++) {
		arr[i] = lower_bound(val.begin(), val.end(), arr[i]) - val.begin() + 1;
		cnt[arr[i]].push_back(i);
	}

	cin >> Q;
	for (int i = 0; i < Q; i++) {
		int a, b;
		cin >> a >> b;
		q.push_back({ {a,b}, i });
	}

	sort(q.begin(), q.end(), [&](pair<pii, int> a, pair<pii, int> b) {
		if (a.first.first == b.first.first) return a.first.second < b.first.second;
		return a.first.first > b.first.first;
		});

	int now = N;
	
	for (int i = 0; i < Q; i++) {
		int l = q[i].first.first, r = q[i].first.second, idx = q[i].second;
		for (int j = now - 1; j >= l; j--) {
			int a = arr[j];
			int ptr = lower_bound(cnt[a].begin(), cnt[a].end(), j) - cnt[a].begin();
			if (ptr != cnt[a].size() - 1) update(cnt[a][ptr + 1], cnt[a][ptr + 1] - cnt[a][ptr] + 1);
		}

		ans[idx] = query(l, r);
	}

	for (int i = 0; i < Q; i++) cout << ans[i] << '\n';

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

void update(int pos, int val) {
	for (seg[pos += N] = val; pos > 0; pos >>= 1) seg[pos >> 1] = max(seg[pos], seg[pos ^ 1]);
	return;
}

int query(int l, int r) {
	r++;
	int ret = 0;
	for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
		if (l & 1) ret = max(ret, seg[l++]);
		if (r & 1) ret = max(ret, seg[--r]);
	}
	return ret;
}