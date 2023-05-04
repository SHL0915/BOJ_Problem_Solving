#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, cnt = 1;
map <string, int> name;
int parent[2005];

void Union(int a, int b);
int Find(int a);

void solve() {
	cin >> N;

	for (int i = 1; i <= 2000; i++) parent[i] = i;
	name["ChongChong"] = 1;

	for (int i = 0; i < N; i++) {
		string a, b;
		cin >> a >> b;
		if (name[a] == 0) {
			cnt++;
			name[a] = cnt;
		}
		if (name[b] == 0) {
			cnt++;
			name[b] = cnt;
		}

		if (Find(name[a]) == 1) Union(name[a], name[b]);
		if (Find(name[b]) == 1) Union(name[a], name[b]);
	}

	int ans = 0;
	for (int i = 1; i <= cnt; i++) {
		if (Find(i) == 1) ans++;
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
	if (a == parent[a]) return parent[a];
	else return parent[a] = Find(parent[a]);
}