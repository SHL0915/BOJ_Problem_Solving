#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M, check, B;
int arr[100001];
int tree[200005];
pair<pii, int> query[100001];
int ans[100001];

bool cmp(pair<pii, int> a, pair<pii, int> b);
void push(int a);
void pop(int a);
void update(int idx, int val);
int qq(int left, int right);

void solve() {
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> arr[i];
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> query[i].first.first >> query[i].first.second;
		query[i].second = i;
	}
	while (B * B <= N) B++;
	B--;
	sort(query, query + M, cmp);
	int l = query[0].first.first, r = query[0].first.second;
	for (int i = l; i <= r; i++) push(i);
	ans[query[0].second] = qq(1, 100001);
	for (int i = 1; i < M; i++) {
		int nl = query[i].first.first, nr = query[i].first.second, id = query[i].second;
		while (l < nl) pop(l++);
		while (l > nl) push(--l);
		while (r < nr) push(++r);
		while (nr < r) pop(r--);
		ans[id] = qq(1, 100001);
	}
	for (int i = 0; i < M; i++) cout << ans[i] << '\n';
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

bool cmp(pair<pii, int> a, pair<pii, int> b) {
	if (a.first.first / B == b.first.first / B) return a.first.second < b.first.second;
	return a.first.first / B < b.first.first / B;
}

void push(int a) {
	int now = arr[a];
	update(now, 1);
	return;
}

void pop(int a) {
	int now = arr[a];
	update(now, -1);
	return;
}

void update(int idx, int val) {
	for (tree[idx += 100000] += val; idx > 1; idx >>= 1) tree[idx >> 1] = max(tree[idx], tree[idx ^ 1]);
	return;
}

int qq(int left, int right) {
	int ret = 0;
	for (left += 100000, right += 100000; left < right; left >>= 1, right >>= 1) {
		if (left & 1) ret = max(ret, tree[left++]);
		if (right & 1) ret = max(ret, tree[--right]);
	}
	return ret;
}