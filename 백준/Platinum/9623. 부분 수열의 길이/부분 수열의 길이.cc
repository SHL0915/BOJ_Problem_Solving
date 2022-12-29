#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pli;
const int INF = 0x3f3f3f3f;

int t, N, X;
ll arr[500000];
ll psum[500000];
vector <ll> val;
vector <int> tree;

void insert(int node, int start, int end, int idx, int val);
int query(int node, int start, int end, int left, int right);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> N >> X;
		int ans = INF;
		int sz = 2 * N;
		val.clear();
		tree.clear();
		tree.resize(4 * sz, -1);
		val.push_back(0);
		val.push_back(-X);
		for (int i = 1; i <= N; i++) {
			cin >> arr[i];
			psum[i] = psum[i - 1] + arr[i];
			val.push_back(psum[i]);
			val.push_back(psum[i] - X);
		}
		sort(val.begin(), val.end());
		val.erase(unique(val.begin(), val.end()), val.end());
		int idx = lower_bound(val.begin(), val.end(), 0) - val.begin() + 1;
		insert(1, 1, sz, idx, 0);
		for (int i = 1; i <= N; i++) {
			idx = lower_bound(val.begin(), val.end(), psum[i] - X) - val.begin() + 1;
			int cand = query(1, 1, sz, 1, idx);
			if (cand != -1) ans = min(ans, i - cand);
			int pos = lower_bound(val.begin(), val.end(), psum[i]) - val.begin() + 1;
			insert(1, 1, sz, pos, i);
		}
		if (ans == INF) cout << -1 << '\n';
		else cout << ans << '\n';
	}
	return 0;
}

void insert(int node, int start, int end, int idx, int val) {
	if (idx > end || idx < start) return;
	if (start == end) {
		tree[node] = val;
		return;
	}
	int mid = (start + end) / 2;
	insert(node * 2, start, mid, idx, val);
	insert(node * 2 + 1, mid + 1, end, idx, val);
	tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
	return;
}

int query(int node, int start, int end, int left, int right) {
	if (left > end || right < start) return -1;
	if (left <= start && end <= right) return tree[node];
	int mid = (start + end) / 2;
	return max(query(node * 2, start, mid, left, right), query(node * 2 + 1, mid + 1, end, left, right));
}