#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int a, b, c, d;
queue <pair<pii, int>> q;
map <pii, int> mark;

void BFS();

void solve() {
	cin >> a >> b >> c >> d;
	q.push({ {0,0},1 });
	while (q.size()) BFS();
	cout << -1;
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
	int x = f.first.first;
	int y = f.first.second;
	int dd = f.second;
	if (mark[f.first] != 0) return;
	mark[f.first] = dd;
	if (x == c && y == d) {
		cout << dd - 1;
		exit(0);
	}

	q.push({ {a,y}, dd + 1 });
	q.push({ {x,b}, dd + 1 });
	q.push({ {0,y}, dd + 1 });
	q.push({ {x,0}, dd + 1 });

	int temp1 = b - y;
	q.push({ {x - min(x, temp1), y + min(x, temp1)}, dd + 1 });

	int temp2 = a - x;
	q.push({ {x + min(y, temp2), y - min(y, temp2)}, dd + 1 });
	return;

}