#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, Q, B, now;
int arr[100001];
vector <int> val;
int cnt[100001];
int cntcnt[100001];
pair<pii, int> q[100001];
int ans[100001];

bool cmp(pair<pii, int> a, pair<pii, int> b);
void push(int a);
void pop(int a);

void solve() {
	cin >> N >> Q;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		val.push_back(arr[i]);
	}

	sort(val.begin(), val.end());
	val.erase(unique(val.begin(), val.end()), val.end());
	for (int i = 1; i <= N; i++) arr[i] = lower_bound(val.begin(), val.end(), arr[i]) - val.begin();

	for (int i = 0; i < Q; i++) {
		int a, b;
		cin >> a >> b;
		q[i] = { {a,b},i };
	}

	while (B * B <= N) B++;
	B--;

	sort(q, q + Q, cmp);

	cntcnt[0] = N;

	int l = q[0].first.first, r = q[0].first.second, idx = q[0].second;

	for (int i = l; i <= r; i++) push(i);
	ans[idx] = now;
	
	for (int i = 1; i < Q; i++) {
		int nl = q[i].first.first, nr = q[i].first.second;
		idx = q[i].second;
		while (l < nl) pop(l++);
		while (l > nl) push(--l);
		while (r < nr) push(++r);
		while (r > nr) pop(r--);
		ans[idx] = now;
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

bool cmp(pair<pii, int> a, pair<pii, int> b) {
	if (a.first.first / B == b.first.first / B) return a.first.second < b.first.second;
	return a.first.first / B < b.first.first / B;
}

void push(int a) {
	cntcnt[cnt[arr[a]]]--;
	cnt[arr[a]]++;
	cntcnt[cnt[arr[a]]]++;
	now = max(now, cnt[arr[a]]);
	return;
}

void pop(int a) {
	cntcnt[cnt[arr[a]]]--;
	if (cntcnt[now] == 0) now--;
	cnt[arr[a]]--;
	cntcnt[cnt[arr[a]]]++;
	return;
}