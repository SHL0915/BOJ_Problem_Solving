#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, Q, ans, B;
int arr[1000001];
int cnt[1000001];
vector <int> val;
pair<pii, int> query[1000001];
int output[1000001];

bool cmp(pair<pii, int> a, pair<pii, int> b);
void push(int a);
void pop(int a);

void solve() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		val.push_back(arr[i]);
	}
	sort(val.begin(), val.end());
	val.erase(unique(val.begin(), val.end()), val.end());
	for (int i = 1; i <= N; i++) arr[i] = lower_bound(val.begin(), val.end(), arr[i]) - val.begin();
	cin >> Q;
	for (int i = 0; i < Q; i++) {
		int a, b;
		cin >> a >> b;
		query[i] = { {a,b},i };
	}
	while (B * B <= N) B++;
	B--;
	sort(query, query + Q, cmp);
	int l = query[0].first.first, r = query[0].first.second;
	for (int i = l; i <= r; i++) push(i);
	output[query[0].second] = ans;
	for (int i = 1; i < Q; i++) {
		int nl = query[i].first.first, nr = query[i].first.second, idx = query[i].second;
		while (l < nl) pop(l++);
		while (l > nl) push(--l);
		while (r < nr) push(++r);
		while (r > nr) pop(r--);
		output[idx] = ans;
	}
	for (int i = 0; i < Q; i++) cout << output[i] << '\n';
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
	if (cnt[now] == 0) ans++;
	cnt[now]++;
	return;
}

void pop(int a) {
	int now = arr[a];
	if (cnt[now] == 1) ans--;
	cnt[now]--;
	return;
}