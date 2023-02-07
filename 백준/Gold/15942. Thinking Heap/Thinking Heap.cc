#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, k, p, ch, now;
int ans[200001];
set <int> cand;

void construct(int node);

void solve() {
	cin >> N >> k >> p;
	int par = 0;
	int temp = p / 2;	
	for (int i = 1; i <= N; i++) cand.insert(i);
	par = p / 2;
	now = k - 1;
	while (par) {
		if (cand.count(now) == 0) {
			cout << -1;
			return;
		}
		ans[par] = now;
		cand.erase(now);
		now--;
		par /= 2;
	}
	now = k;
	construct(p);
	for (int i = 1; i <= N; i++) {
		if (ans[i] == 0) {
			ans[i] = *(cand.begin());
			cand.erase(cand.begin());
		}
	}
	for (int i = 1; i <= N; i++) cout << ans[i] << '\n';
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

void f(int node) {
	if (node > N) return;
	ch++;
	f(node * 2);
	f(node * 2 + 1);
	return;
}

void construct(int node) {
	if (node > N) return;
	if (cand.count(now) == 0) {
		cout << -1;
		exit(0);
	}
	ans[node] = now;
	cand.erase(now);
	now++;
	construct(node * 2);
	construct(node * 2 + 1);
	return;
}