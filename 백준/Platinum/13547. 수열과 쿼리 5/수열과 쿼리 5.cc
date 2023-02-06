#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M, B, cnt;
int arr[100001];
int mark[1000001];
int ans[100001];
pair<pii, int> query[100001];

bool cmp(pair<pii, int> a, pair<pii, int> b);
void push(int a);
void pop(int a);

void solve() {
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> arr[i];
	cin >> M;
	for (int i = 0; i < M; i++) {
		int l, r;
		cin >> l >> r;
		query[i] = { {l,r},i };
	}
	while (B * B <= N) B++;
	B--;
	sort(query, query + M, cmp);
	int l = query[0].first.first, r = query[0].first.second;
	for (int i = l; i <= r; i++) push(i);
	ans[query[0].second] = cnt;
	
	for (int i = 1; i < M; i++) {
		int nl = query[i].first.first, nr = query[i].first.second, id = query[i].second;
		while (l < nl) pop(l++);
		while (l > nl) push(--l);
		while (r < nr) push(++r);
		while (r > nr) pop(r--);
		ans[id] = cnt;
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
	if (mark[arr[a]] == 0) cnt++;
	mark[arr[a]] ++;
}

void pop(int a) {
	if (mark[arr[a]] == 1) cnt--;
	mark[arr[a]] --;
}