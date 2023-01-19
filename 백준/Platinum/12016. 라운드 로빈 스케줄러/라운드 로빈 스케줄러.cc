#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

int N;
pii arr[100001];
ll ans[100001];
vector <ll> tree;

void update(int node, int start, int end, int idx, ll val);
ll query(int node, int start, int end, int left, int right);
bool cmp(pii A, pii B) {
	if (A.first == B.first) return A.second > B.second;
	return A.first < B.first;
}

void solve() {
	cin >> N;
	tree.resize(4 * N);
	for (int i = 1; i <= N; i++) {
		cin >> arr[i].first;
		arr[i].second = i;
	}
	sort(arr + 1, arr + N + 1, cmp);
	for (int i = N; i >= 1; i--) {
		ll val = arr[i].first, idx = arr[i].second;
		update(1, 1, N, idx, 1);
		ans[idx] += query(1, 1, N, 1, idx);
	}	
	ll cnt = N, prev_val = arr[1].first, add = N * (arr[1].first - 1);
	for (int i = 1; i <= N; i++) {
		ll val = arr[i].first, idx = arr[i].second;
		if (val != prev_val) {
			add += cnt;
			cnt = query(1, 1, N, 1, N);
			add += cnt * (val - prev_val - 1);
			prev_val = val;
		}
		ans[idx] += add;
		update(1, 1, N, idx, -1);
	}
	for (int i = 1; i <= N; i++) cout << ans[i] << '\n';
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

void update(int node, int start, int end, int idx, ll val) {
	if (idx > end || idx < start) return;
	if (start == end) {
		tree[node] += val;
		return;
	}
	int mid = (start + end) / 2;
	update(node * 2, start, mid, idx, val);
	update(node * 2 + 1, mid + 1, end, idx, val);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
	return;
}

ll query(int node, int start, int end, int left, int right) {
	if (left > end || right < start) return 0;
	if (left <= start && end <= right) return tree[node];
	int mid = (start + end) / 2;
	return (query(node * 2, start, mid, left, right) + query(node * 2 + 1, mid + 1, end, left, right));
}