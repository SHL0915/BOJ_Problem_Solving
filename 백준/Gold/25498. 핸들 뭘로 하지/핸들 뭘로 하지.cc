#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
string arr, ans;
char M;
vector <int> tree[500001];
int mark[500001];
queue <pii> q, cand;

void BFS();

void solve() {
	cin >> N;
	cin >> arr;
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	q.push({ 1,1 });
	while (q.size()) {
		M = 0;
		while (q.size()) BFS();		
		if (M == 0) break;
		ans += M;
		while (cand.size()) {
			pii f = cand.front(); cand.pop();
			if (arr[f.second - 1] == M) q.push(f);
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

void BFS() {
	pii f = q.front(); q.pop();
	int now = f.first;
	int par = f.second;
	if (mark[now]) return;	
	mark[now] = 1;
	M = max(M, arr[now - 1]);
	for (int i = 0; i < tree[now].size(); i++) {
		int next = tree[now][i];
		if (next == par) continue;
		cand.push({ next, now });
	}
	return;
}