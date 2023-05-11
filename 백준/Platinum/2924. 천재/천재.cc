#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

ll N, A, B, C, D;
ll parent[500005], mark[500005], sz[500005];
vector <int> graph[500005];

void Union(int a, int b);
int Find(int a);
void DFS(int a);
ll LCM(ll a, ll b);
ll GCD(ll a, ll b);

void solve() {
	cin >> N >> A >> B >> C >> D;
	A--; B--;
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
		sz[i] = 1;
	}

	for (int i = 1; i <= N; i++) {
		int a; cin >> a;
		graph[i].push_back(a);
	}

	for (int i = C + 1; i <= N - D; i++) {
		if (mark[i] == 0) DFS(i);
	}

	ll lcm = 0;
	for (int i = C + 1; i <= N - D; i++) {
		if (lcm == 0) lcm = sz[Find(i)];
		else {
			if (lcm % sz[Find(i)]) lcm = LCM(lcm, sz[Find(i)]);
			else continue;
		}	
	}

	ll ans = (A == 0);
	ans += B / lcm - max(0LL, A - 1) / lcm;

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
	if (a > b) {
		parent[a] = b;
		sz[b] += sz[a];
	}
	else {
		parent[b] = a;
		sz[a] += sz[b];
	}
	return;
}

int Find(int a) {
	if (parent[a] == a) return parent[a];
	else return parent[a] = Find(parent[a]);
}

void DFS(int a) {
	if (mark[a]) return;
	mark[a] = 1;
	for (int i = 0; i < graph[a].size(); i++) {
		int next = graph[a][i];
		Union(a, next);
		if (mark[next]) continue;
		DFS(next);
	}
	return;
}

ll LCM(ll a, ll b) {
	return a * b / GCD(a, b);
}

ll GCD(ll a, ll b) {
	if (!b) return a;
	else return GCD(b, a % b);
}