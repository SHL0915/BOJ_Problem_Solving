#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int N, M, cnt;
int arr[21][21];
pii pos[2];
map <pair<pii, pii>, int> mark;
queue <pair<pair<pii, pii>, int>> q;

void BFS();

void solve() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < M; j++) {
			if (s[j] == 'o') pos[cnt++] = { j,i };
			else if (s[j] == '#') arr[i][j] = 1;
		}
	}
	q.push({ {pos[0],pos[1]}, 0 });
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
	pair<pair<pii, pii>, int> f = q.front();
	q.pop();
	pii a = f.first.first;
	pii b = f.first.second;
	int d = f.second;
	int flag = 0;
	if (a.first < 0 || a.first >= M || a.second < 0 || a.second >= N) flag++;
	if (b.first < 0 || b.first >= M || b.second < 0 || b.second >= N) flag++;
	if (flag == 2) return;
	if (flag == 1) {
		cout << d;
		exit(0);
	}
	if (mark[{a, b}] != 0) return;
	mark[{a, b}] = 1;
	for (int i = 0; i < 4; i++) {
		pii aa = a, bb = b;
		aa.first += dx[i];
		aa.second += dy[i];
		if (arr[aa.second][aa.first] == 1) {
			aa.first -= dx[i];
			aa.second -= dy[i];
		}
		bb.first += dx[i];
		bb.second += dy[i];
		if (arr[bb.second][bb.first] == 1) {
			bb.first -= dx[i];
			bb.second -= dy[i];
		}
		q.push({ {aa,bb},d + 1 });
	}
	return;
}