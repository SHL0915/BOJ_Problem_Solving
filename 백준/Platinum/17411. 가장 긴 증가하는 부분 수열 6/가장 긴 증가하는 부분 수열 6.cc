#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int mod = 1000000007;

int N;
int arr[1000001];
pii ans;
vector <int> val;
vector <pii> tree;

pii add(pii a, pii b);
void update(int node, int start, int end, int idx, pii val);
pii query(int node, int start, int end, int left, int right);

void solve() {
	cin >> N;
	tree.resize(4 * N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		val.push_back(arr[i]);
	}
	sort(val.begin(), val.end());
	val.erase(unique(val.begin(), val.end()), val.end());
	for (int i = 0; i < N; i++) arr[i] = lower_bound(val.begin(), val.end(), arr[i]) - val.begin() + 1;
	for (int i = 0; i < N; i++) {
		pii q = query(1, 1, N, 1, arr[i] - 1);
		q.first++;
		q.second = max(q.second, 1);
		update(1, 1, N, arr[i], q);
	}
	ans = query(1, 1, N, 1, N);
	cout << ans.first << " " << ans.second;
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

pii add(pii a, pii b) {
	if (a.first > b.first) return a;
	else if (a.first == b.first) return { a.first, (a.second + b.second) % mod };
	else return b;
}

void update(int node, int start, int end, int idx, pii val) {
	if (idx > end || idx < start) return;
	if (start == end) {
		tree[node] = add(tree[node], val);
		return;
	}
	int mid = (start + end) / 2;
	update(node * 2, start, mid, idx, val);
	update(node * 2 + 1, mid + 1, end, idx, val);
	tree[node] = add(tree[node * 2], tree[node * 2 + 1]);
	return;
}

pii query(int node, int start, int end, int left, int right) {
	if (left > end || right < start) return { 0,0 };
	if (left <= start && end <= right) return tree[node];
	int mid = (start + end) / 2;
	return add(query(node * 2, start, mid, left, right), query(node * 2 + 1, mid + 1, end, left, right));
}