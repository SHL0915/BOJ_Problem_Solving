#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M, K;
int arr[30001];
int parent[30001], sz[30001], mark[30001];
vector <pii> new_arr;
ll table[30001];

int Find(int a);
void Union(int a, int b);

void solve() {
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		parent[i] = i;
		sz[i] = 1;
	}
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		Union(a, b);
	}

	for (int i = 1; i <= N; i++) {
		if (mark[Find(i)] == 0) {
			new_arr.push_back({ sz[Find(i)], arr[Find(i)] });
			mark[Find(i)] = 1;
		}
	}

	ll ans = 0;

	for (int i = 0; i < new_arr.size(); i++) {
		for (int j = K - 1; j >= 0; j--) {
			if (j < new_arr[i].first) continue;
			table[j] = max(table[j], table[j - new_arr[i].first] + new_arr[i].second);
			ans = max(ans, table[j]);
		}
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
	if (parent[a] == a) return parent[a];
	else return parent[a] = Find(parent[a]);
}

void Union(int a, int b) {
	a = Find(a);
	b = Find(b);
	if (a == b) return;
	if (a > b) {
		parent[a] = b;
		sz[b] += sz[a];
		arr[b] += arr[a];
	}
	else {
		parent[b] = a;
		sz[a] += sz[b];
		arr[a] += arr[b];
	}
	return;
}