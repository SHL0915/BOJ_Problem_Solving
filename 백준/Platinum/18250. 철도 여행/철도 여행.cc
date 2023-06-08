#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M;
int degree[200005], parent[200005], mark[200005];
int cnt[200005];

void Union(int a, int b);
int Find(int a);

void solve() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) parent[i] = i;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		degree[a]++;
		degree[b]++;
		Union(a, b);
	}

	int ans = 0;

	for (int i = 1; i <= N; i++) {
		if (degree[i] % 2) cnt[Find(i)]++;
	}

	for (int i = 1; i <= N; i++) {
		if (!degree[i] || mark[Find(i)]) continue;
		mark[Find(i)] = 1;
		ans++;
		ans += max(0, (cnt[Find(i)] - 2) / 2);
	}

	cout << ans;
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

void Union(int a, int b) {
	a = Find(a);
	b = Find(b);
	if (a == b) return;
	if (a > b) parent[a] = b;
	else parent[b] = a;
	return;
}

int Find(int a) {
	if (parent[a] == a) return parent[a];
	else return parent[a] = Find(parent[a]);
}