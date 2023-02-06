#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M;
int arr[100001];
ll ans[100001];
pii update_query[100001];
pair<pii, pii> output_query[100001];
vector<ll> tree;

void update(int node, int start, int end, int idx, ll val);
ll query(int node, int start, int end, int left, int right);

void solve() {
	cin >> N;
	tree.resize(4 * N);
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		update(1, 1, N, i, arr[i]);
	}
	cin >> M;
	int cnt = 1, Q = 0;
	for (int i = 0; i < M; i++) {
		int a, b, c, d;
		cin >> a;
		if (a == 1) {
			cin >> b >> c;
			update_query[cnt] = { b,c };
			cnt++;
		}
		else {
			cin >> b >> c >> d;
			output_query[Q] = { {b,Q}, {c,d} };
			Q++;
		}
	}
	sort(output_query, output_query + Q);
	int idx = 1;
	for (int i = 0; i < Q; i++) {
		int k = output_query[i].first.first, l = output_query[i].second.first, r = output_query[i].second.second;
		while (idx <= k) {
			int id = update_query[idx].first;
			ll val = update_query[idx].second;
			update(1, 1, N, id, val);
			idx++;
		}
		ans[output_query[i].first.second] = query(1, 1, N, l, r);
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

void update(int node, int start, int end, int idx, ll val) {
	if (idx > end || idx < start) return;
	if (start == end) {
		tree[node] = val;
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
	return query(node * 2, start, mid, left, right) + query(node * 2 + 1, mid + 1, end, left, right);
}