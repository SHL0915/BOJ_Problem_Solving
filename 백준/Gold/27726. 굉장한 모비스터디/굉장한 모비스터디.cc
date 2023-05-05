#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M1, M2, M3;
int parent[100005];
int key[100005];
vector <int> ans[100005], arr[100005];

void Union(int a, int b);
int Find(int a);

void solve() {
	cin >> N >> M1 >> M2 >> M3;
	for (int i = 1; i <= N; i++) parent[i] = i;

	for (int i = 0; i < M1; i++) {
		int a, b;
		cin >> a >> b;
		Union(a, b);
	}

	for (int i = 1; i <= N; i++) key[i] = Find(i);
	for (int i = 1; i <= N; i++) parent[i] = i;
	
	for (int i = 0; i < M2; i++) {
		int a, b;
		cin >> a >> b;
		Union(a, b);
	}

	for (int i = 1; i <= N; i++) arr[Find(i)].push_back(i);
	for (int i = 1; i <= N; i++) {
		map <int, int> m;
		for (int j = 0; j < arr[i].size(); j++) {
			int now = arr[i][j];
			if (m[key[now]] == 0) {
				m[key[now]] = now;
				parent[now] = now;
			}
			else parent[now] = m[key[now]];
		}
	}

	for (int i = 1; i <= N; i++) key[i] = Find(i);
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
		arr[i].clear();
	}

	for (int i = 0; i < M3; i++) {
		int a, b;
		cin >> a >> b;
		Union(a, b);
	}

	for (int i = 1; i <= N; i++) arr[Find(i)].push_back(i);
	for (int i = 1; i <= N; i++) {
		map <int, int> m;
		for (int j = 0; j < arr[i].size(); j++) {
			int now = arr[i][j];
			if (m[key[now]] == 0) {
				m[key[now]] = now;
				parent[now] = now;
			}
			else parent[now] = m[key[now]];
		}
	}

	for (int i = 1; i <= N; i++) ans[parent[i]].push_back(i);
	
	int cnt = 0;
	for (int i = 1; i <= N; i++) if (ans[i].size() >= 2) cnt++;

	cout << cnt << '\n';
	for (int i = 1; i <= N; i++) {
		if (ans[i].size() >= 2) {
			for (int j = 0; j < ans[i].size(); j++) cout << ans[i][j] << " ";
			cout << '\n';
		}
	}

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
	if (a == parent[a]) return parent[a];
	else return parent[a] = Find(parent[a]);
}