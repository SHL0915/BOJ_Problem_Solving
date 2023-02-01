#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

ll N, K;
ll arr[200001];
ll cmp[100001];
pii temp[100001];
ll pi[100001];
vector <ll> arr_val, cmp_val, ans, tree;

void update(int node, int start, int end, int idx, ll val);
ll query(int node, int start, int end, int left, int right);
void makePi();
void kmp();
bool check(int i, int j, int type);

void solve() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		arr_val.push_back(arr[i]);
	}
	sort(arr_val.begin(), arr_val.end());
	arr_val.erase(unique(arr_val.begin(), arr_val.end()), arr_val.end());
	for (int i = 0; i < N; i++) arr[i] = lower_bound(arr_val.begin(), arr_val.end(), arr[i]) - arr_val.begin() + 1;
	for (int i = 0; i < N; i++) arr[N + i] = arr[i];

	for (int i = 0; i < K; i++) {
		cin >> cmp[i];
		cmp_val.push_back(cmp[i]);
	}
	sort(cmp_val.begin(), cmp_val.end());
	cmp_val.erase(unique(cmp_val.begin(), cmp_val.end()), cmp_val.end());
	for (int i = 0; i < K; i++) cmp[i] = lower_bound(cmp_val.begin(), cmp_val.end(), cmp[i]) - cmp_val.begin() + 1;
	tree.resize(4 * K, 0);
	for (int i = 0; i < K; i++) {
		update(1, 1, K, cmp[i], 1);
		temp[i] = { query(1,1,K,1,cmp[i] - 1), query(1,1,K,cmp[i] + 1,K) };
	}
	
	makePi();
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
	return query(node * 2, start, mid, left, right) + query(node * 2 + 1, mid + 1, end, left, right);
}

void makePi() {
	tree.clear();
	tree.resize(4 * K, 0);
	ll n = K, pos = 1, k = 0;
	while (pos + k < n) {
		if (check(pos + k, k, 0)) {
			update(1, 1, K, cmp[pos + k], 1);
			k++;
			pi[pos + k - 1] = k;
		}
		else {
			if (k == 0) pos++;
			else {
				for (int i = pos; i < pos + k - pi[k - 1]; i++) update(1, 1, K, cmp[i], -1);
				pos += (k - pi[k - 1]);
				k = pi[k - 1];
			}
		}
	}
	return;
}

void kmp() {
	tree.clear();
	tree.resize(4 * N, 0);
	ll n = 2 * N, m = K, pos = 0, k = 0;
	while (pos < N) {
		if (k < m && check(pos + k, k, 1)) {
			update(1, 1, N, arr[pos + k], 1);
			k++;
			if (k == m) ans.push_back(pos);
		}
		else {
			if (k == 0) pos++;			
			else {
				for (int i = pos; i < pos + k - pi[k - 1]; i++) {
					if (i >= N) break;
					update(1, 1, N, arr[i], -1);
				}
				pos += k - pi[k - 1];
				k = pi[k - 1];
			}
		}
	}
	return;
}

bool check(int i, int j, int type) {
	bool a, b;
	if (type) {
		a = (query(1, 1, N, 1, arr[i] - 1) == temp[j].first);
		b = (query(1, 1, N, arr[i] + 1, N) == temp[j].second);
	}
	else {
		a = (query(1, 1, K, 1, cmp[i] - 1) == temp[j].first);
		b = (query(1, 1, K, cmp[i] + 1, K) == temp[j].second);
	}
	if (a == true && b == true) return true;
	else return false;
}