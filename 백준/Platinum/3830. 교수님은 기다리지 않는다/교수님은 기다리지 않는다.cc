#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M;
int parent[100001];
ll diff[100001];

int Find(int node);
void Union(int a, int b, ll delt);

void solve() {
	for (int i = 0; i < M; i++) {
		char type;
		int a, b, c;
		cin >> type;
		if (type == '!') {
			cin >> a >> b >> c;
			Union(a, b, c);
		}
		else {
			cin >> a >> b;
			if (Find(a) != Find(b)) cout << "UNKNOWN\n";
			else cout << diff[b] - diff[a] << '\n';
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
	while (1) {
		cin >> N >> M;
		if (N == 0 && M == 0) break;
		for (int i = 1; i <= N; i++) {
			parent[i] = i;
			diff[i] = 0;
		}
		solve();
	}
	return 0;
}

int Find(int node) {
	if (parent[node] == node) return parent[node];
	else {
		int par = parent[node];
		parent[node] = Find(parent[node]);
		diff[node] += diff[par];
		return parent[node];
	}
}

void Union(int a, int b, ll delt) {
	if (Find(a) == Find(b)) return;
	ll a_val = diff[a], b_val = diff[b];
	a = Find(a);
	b = Find(b);
	if (a > b) {
		parent[a] = b;
		diff[a] = b_val - a_val - delt;
	}
	else {
		parent[b] = a;
		diff[b] = delt + a_val - b_val;
	}
	return;
}