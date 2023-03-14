#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int M, X, Y, K, ans;
int mark[101][101];
queue <pair<pii, int>> q;

void BFS();

void solve() {
	cin >> X >> Y >> K >> M;
	q.push({ { 0,0 } , 0 });
	ans = 0x3f3f3f3f;
	while (q.size()) BFS();
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
	pair<pii, int> f = q.front(); q.pop();
	int a = f.first.first;
	int b = f.first.second;
	int d = f.second;
	if (d > K) return;
	if (mark[a][b]) return;
	mark[a][b] = 1;
	ans = min(ans, abs(a + b - M));

	q.push({ {a,0},d + 1 });
	q.push({ {0,b},d + 1 });

	q.push({ {X,b},d + 1 });
	q.push({ {a,Y},d + 1 });

	int pour_a = min(a, Y - b);
	int pour_b = min(b, X - a);
	q.push({ {a - pour_a, b + pour_a}, d + 1 });
	q.push({ {a + pour_b, b - pour_b}, d + 1 });
	return;
}