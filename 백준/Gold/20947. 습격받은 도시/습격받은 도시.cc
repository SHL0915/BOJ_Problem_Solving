#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int N;
int arr[2001][2001];
int mark[2001][2001];
queue <pair<pii, int>> q;

void BFS();

void solve() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < N; j++) {
			if (s[j] == '.') arr[i][j] = 0;
			else if (s[j] == 'O') {
				arr[i][j] = 1;
				mark[i][j] = 1;
			}
			else {
				arr[i][j] = 2;
				mark[i][j] = 2;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] == 1) {
				for (int k = 0; k < 4; k++) {
					int x = j + dx[k];
					int y = i + dy[k];
					q.push({ {x,y},k });
				}
			}
		}
	}
	while (q.size()) BFS();

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (mark[i][j] == 0) cout << "B";
			else {
				if (arr[i][j] == 0) cout << ".";
				else if (arr[i][j] == 1) cout << "O";
				else cout << "X";
			}
		}
		cout << '\n';
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
	while (t--) solve();
	return 0;
}

void BFS() {
	pair<pii, int> f = q.front();
	q.pop();
	int x = f.first.first;
	int y = f.first.second;
	int dir = f.second;
	if (x < 0 || x >= N || y < 0 || y >= N) return;
	if (arr[y][x] != 0) return;
	mark[y][x] = 1;
	if (dir == 0) q.push({ {x + 1, y}, dir });
	else if (dir == 1) q.push({ {x - 1, y}, dir });
	else if (dir == 2) q.push({ {x, y + 1}, dir });
	else q.push({ {x, y - 1}, dir });
}