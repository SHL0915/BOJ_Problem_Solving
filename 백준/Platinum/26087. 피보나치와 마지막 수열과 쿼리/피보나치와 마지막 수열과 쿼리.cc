#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll mod = 1000000007;

int N, Q;
int arr[1000001];
int parent[1000001];
int mark[1000001];
pii query[1000001];
ll fibo[1000001];

int Find(int a);
void Union(int a, int b);

void solve() {
	cin >> N >> Q;
	for (int i = 1; i <= N; i++) parent[i] = i;
	for (int i = 0; i < Q; i++) {
		int l, r;
		cin >> l >> r;
		query[i] = { l,r };
	}
	for (int i = Q - 1; i >= 0; i--) {
		int l = query[i].first, r = query[i].second;
		for (int j = l; j <= r; j++) {
			int now = j;
			if (Find(j) == j) {
				if (mark[j] == 0) {
					arr[j] = fibo[j - l + 1];
					mark[j] = 1;
				}
			}
			else j = Find(j);
			if (now != l) Union(now, now - 1);
		}
	}
	for (int i = 1; i <= N; i++) cout << arr[i] << " ";
	return;
}

int main(void) {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);

	fibo[0] = 1;
	fibo[1] = 1;
	for (int i = 2; i <= 1000000; i++) fibo[i] = (fibo[i - 1] + fibo[i - 2]) % mod;

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
	if (a > b) parent[b] = a;
	else parent[a] = b;
	return;
}