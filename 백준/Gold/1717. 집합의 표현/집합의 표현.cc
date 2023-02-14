#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M;
int parent[1000001];

int Find(int a);
void Union(int a, int b);

void solve() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) parent[i] = i;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a) {
			if (Find(b) == Find(c)) cout << "YES\n";
			else cout << "NO\n";
		}
		else Union(b, c);
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