#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M, B;
int arr[100001];
vector <int> val;
int tree[400005];
pair<pii, pii> query[5001];
int ans[5001];

bool cmp(pair<pii, pii> a, pair<pii, pii> b);
void push(int a);
void pop(int a);
int Binary_Search(int left, int right, int k);
void update(int pos, int val);
int qq(int left, int right);

void solve() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		val.push_back(arr[i]);
	}
	sort(val.begin(), val.end());
	val.erase(unique(val.begin(), val.end()), val.end());
	for (int i = 1; i <= N; i++) arr[i] = lower_bound(val.begin(), val.end(), arr[i]) - val.begin() + 1;

	while (B * B <= N) B++;
	B--;

	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		query[i] = { {a,b}, {c,i} };
	}

	sort(query, query + M, cmp);

	int l = query[0].first.first, r = query[0].first.second;
	for (int i = l; i <= r; i++) push(arr[i]);	

	int a = Binary_Search(1, N, query[0].second.first);
	if (qq(1, a + 1) < query[0].second.first) a++;
	ans[query[0].second.second] = val[a - 1];

	for (int i = 1; i < M; i++) {
		int nl = query[i].first.first, nr = query[i].first.second, k = query[i].second.first, idx = query[i].second.second;

		while (nl < l) push(arr[--l]);
		while (nl > l) pop(arr[l++]);
		while (nr < r) pop(arr[r--]);
		while (nr > r) push(arr[++r]);

		int a = Binary_Search(1, N, k);

		if (qq(1, a + 1) < k) a++;
		ans[idx] = val[a - 1];
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

bool cmp(pair<pii, pii> a, pair<pii, pii> b) {
	if (a.first.first / B == b.first.first / B) return a.first.second < b.first.second;
	return a.first.first / B < b.first.first / B;
}

void push(int a) {
	update(a, 1);
	return;
}

void pop(int a) {
	update(a, -1);
	return;
}

int Binary_Search(int left, int right, int k) {
	if (left < right) {
		int mid = (left + right) / 2;
		if (qq(1, mid + 1) >= k) return Binary_Search(left, mid - 1, k);
		else return Binary_Search(mid + 1, right, k);
	}
	else return left;
}

void update(int pos, int val) {
	for (tree[pos += N] += val; pos > 1; pos >>= 1) tree[pos >> 1] = tree[pos] + tree[pos ^ 1];
	return;
}

int qq(int left, int right) {
	int ret = 0;
	for (left += N, right += N; left < right; left >>= 1, right >>= 1) {
		if (left & 1) ret += tree[left++];
		if (right & 1) ret += tree[--right];
	}
	return ret;
}