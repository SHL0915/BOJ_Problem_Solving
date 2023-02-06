#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

int W, H, cnt;
int arr[101][101];
pii pos[2];
int mark[101][101][4];
queue <pair<pii, pii>> q, temp;

void BFS();

void solve() {
	cin >> W >> H;
	for (int i = 0; i < H; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < W; j++) {
			if (s[j] == '*') arr[i][j] = 1;
			else if (s[j] == 'C') pos[cnt++] = { j,i };
		}
	}
	memset(mark, -1, sizeof(mark));
	q.push({ {pos[0].first - 1, pos[0].second}, {0, 0} });
	q.push({ {pos[0].first, pos[0].second + 1}, {0, 1} });
	q.push({ {pos[0].first + 1, pos[0].second}, {0, 2} });
	q.push({ {pos[0].first, pos[0].second - 1}, {0, 3} });
	while (temp.size() || q.size()) {
		while (temp.size()) {
			q.push(temp.front());
			temp.pop();
		}
		while (q.size()) BFS();
	}
	int ans = INF;
	for (int i = 0; i < 4; i++) {
		int x = pos[1].first, y = pos[1].second;
		if (mark[y][x][i] == -1) continue;
		ans = min(ans, mark[y][x][i]);
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
	pair<pii, pii> f = q.front();
	q.pop();
	int x = f.first.first;
	int y = f.first.second;
	int d = f.second.first;
	int dir = f.second.second;
	if (x < 0 || x >= W || y < 0 || y >= H) return;
	if (arr[y][x] == 1) return;
	if (mark[y][x][dir] != -1) return;
	mark[y][x][dir] = d;
	if (dir == 0) {
		q.push({ {x - 1, y}, {d, dir} });
		temp.push({ {x, y + 1}, {d + 1, 1} });
		temp.push({ {x, y - 1}, {d + 1, 3} });
	}
	else if (dir == 1) {
		q.push({ {x, y + 1}, {d, dir} });
		temp.push({ {x - 1, y}, {d + 1, 0} });
		temp.push({ {x + 1, y}, {d + 1, 2} });
	}
	else if (dir == 2) {
		q.push({ {x + 1, y}, {d, dir} });
		temp.push({ {x, y + 1}, {d + 1, 1} });
		temp.push({ {x, y - 1}, {d + 1, 3} });
	}
	else {
		q.push({ {x, y - 1}, {d, dir} });
		temp.push({ {x - 1, y}, {d + 1, 0} });
		temp.push({ {x + 1, y}, {d + 1, 2} });
	}
}