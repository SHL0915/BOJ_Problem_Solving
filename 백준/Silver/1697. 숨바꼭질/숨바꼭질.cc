#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, K;
int mark[200001];
queue <pii> q;

void BFS();

void solve() {
	cin >> N >> K;
	q.push({ N, 1 });
	while (q.size()) BFS();
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}

void BFS() {
	pii f = q.front();
	q.pop();
	int now = f.first;
	int d = f.second;
	if (now > 200000 || now < 0) return;
	if (mark[now]) return;
	mark[now] = d;
	if (now == K) {
		cout << d - 1;
		exit(0);
	}
	if (now) q.push({ now * 2, d + 1 });
	q.push({ now - 1, d + 1 });
	q.push({ now + 1, d + 1 });
}