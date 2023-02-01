#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, K;
int arr[200001], B[100001], pi[100001];
pii cmp[100001];
vector <int> a, b, ans, tree;

void update(int node, int start, int end, int idx, int val);
int query(int node, int start, int end, int left, int right);
void kmp();
void makePi();
bool check(int i, int j, int type);

void solve() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		a.push_back(arr[i]);
	}
	for (int i = 0; i < K; i++) {
		cin >> B[i];
		b.push_back(B[i]);
	}
	
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	a.erase(unique(a.begin(), a.end()), a.end());
	b.erase(unique(b.begin(), b.end()), b.end());

	for (int i = 0; i < N; i++) {
		arr[i] = lower_bound(a.begin(), a.end(), arr[i]) - a.begin() + 1;
		arr[N + i] = arr[i];
	}
	for (int i = 0; i < K; i++) B[i] = lower_bound(b.begin(), b.end(), B[i]) - b.begin() + 1;
	
	kmp();

	cout << ans.size();
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

void update(int node, int start, int end, int idx, int val) {
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

int query(int node, int start, int end, int left, int right) {
	if (left > end || right < start) return 0;
	if (left <= start && end <= right) return tree[node];
	int mid = (start + end) / 2;
	return query(node * 2, start, mid, left, right) + query(node * 2 + 1, mid + 1, end, left, right);
}

void kmp() {
	makePi();
	tree.clear();
	tree.resize(4 * N, 0);
	int m = K, pos = 0, k = 0;
	while (pos < N) {
		if (k < m && check(pos + k, k, 1)) {
			update(1, 1, N, arr[pos + k], 1);
			k++;
			if (k == m) ans.push_back(pos);
		}
		else {
			if (k == 0) pos++;
			else {
				for (int i = pos; i < pos + k - pi[k - 1]; i++) update(1, 1, N, arr[i], -1);
				pos += k - pi[k - 1];
				k = pi[k - 1];
			}
		}
	}
	return;
}

void makePi() {
	tree.clear();
	tree.resize(4 * K, 0);
	for (int i = 0; i < K; i++) {
		update(1, 1, K, B[i], 1);
		cmp[i] = { query(1,1,K,1,B[i] - 1), query(1,1,K,B[i] + 1, K) };
	}
	tree.clear();
	tree.resize(4 * K, 0);
	
	int n = K, pos = 1, k = 0;
	while (pos + k < n) {
		if (check(pos + k, k, 0)) {
			update(1, 1, K, B[pos + k], 1);
			k++;
			pi[pos + k - 1] = k;
		}
		else {
			if (k == 0) pos++;
			else {
				for (int i = pos; i < pos + k - pi[k - 1]; i++) update(1, 1, K, B[i], -1);
				pos += k - pi[k - 1];
				k = pi[k - 1];
			}
		}
	}
	return;
}

bool check(int i, int j, int type) {
	bool l, r;
	if (type) {
		l = (query(1, 1, N, 1, arr[i] - 1) == cmp[j].first);
		r = (query(1, 1, N, arr[i] + 1, N) == cmp[j].second);
	}
	else {
		l = (query(1, 1, K, 1, B[i] - 1) == cmp[j].first);
		r = (query(1, 1, K, B[i] + 1, K) == cmp[j].second);
	}
	if (l == true && r == true) return true;
	else return false;
}