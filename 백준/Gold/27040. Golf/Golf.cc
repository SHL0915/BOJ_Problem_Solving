#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int D, C;
int arr[33];
map <int, int> mark;
queue <pii> q;

void BFS();

void solve() {
	cin >> D >> C;
	for (int i = 0; i < C; i++) cin >> arr[i];
	q.push({ 0,0 });
	while (q.size()) BFS();
	cout << 0;
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
	int d = f.second;
	if (now > 40000 || now < -40000) return;
	if (mark[now] != 0) return;
	mark[now] = 1;
	if (now == D) {
		cout << d;
		exit(0);
	}
	for (int i = 0; i < C; i++) {
		q.push({ now - arr[i], d + 1 });
		q.push({ now + arr[i], d + 1 });
	}
	return;
}