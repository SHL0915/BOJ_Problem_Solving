#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
int parent[20001];
ll arr[20001];


int Find(int a);
void Union(int a, int b);

void solve() {
	cin >> N;
	for (int i = 0; i <= N; i++) {
		parent[i] = i;
		arr[i] = 0;
	}
	while (1) {
		char c; cin >> c;
		if (c == 'O') break;
		else if (c == 'E') {
			int a; cin >> a;
			Find(a);
			cout << arr[a] << '\n';
		}
		else {
			int a, b; cin >> a >> b;
			Union(a, b);
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
	cin >> t;
	while (t--) solve();
	return 0;
}

int Find(int a) {
	if (a == parent[a]) return parent[a];
	else {
		ll temp = parent[a];
		parent[a] = Find(parent[a]);
		arr[a] += arr[temp];
		return parent[a];
	}	
}

void Union(int a, int b) {
	ll val = abs(b - a) % 1000;
	parent[a] = b;
	arr[a] += val;
	return;
}