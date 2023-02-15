#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
pii arr[10001];
int parent[10001];

int Find(int a);
void Union(int a, int b);

void solve() {
	cin >> N;
	int ans = 0;
	for (int i = 1; i <= N; i++) cin >> arr[i].first >> arr[i].second;
	for (int i = 1; i <= 10000; i++) parent[i] = i;
	sort(arr + 1, arr + N + 1);
	for (int i = N; i >= 1; i--) {
		int p = arr[i].first, d = arr[i].second;
		d = Find(d);
		if (d == 0) continue;
		ans += p;
		Union(d, d - 1);
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

int Find(int a) {
	if (a == parent[a]) return parent[a];
	else return parent[a] = Find(parent[a]);
}

void Union(int a, int b) {
	a = Find(a);
	b = Find(b);
	if (a == b) return;
	if (a > b) parent[a] = b;
	else parent[b] = a;
	return;
}