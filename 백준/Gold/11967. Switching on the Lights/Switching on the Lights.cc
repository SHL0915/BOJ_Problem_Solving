#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int N, M;
set <pii> cand, l;
int mark[101][101];
int mm[101][101];
vector <pii> arr[101][101];

void solve() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		arr[b][a].push_back({ c,d });
	}

	for (int i = 0; i < arr[1][1].size(); i++) {
		cand.insert({ arr[1][1][i] });
		mark[arr[1][1][i].second][arr[1][1][i].first] = 1;
	}
	mark[1][1] = 1;
	mm[1][1] = 1;
	l.insert({ 1,1 });

	while (1) {
		int flag = 0;
		if (cand.size() == 0) break;
		set <pii> s, del;

		for (auto i = cand.begin(); i != cand.end(); i++) {
			int x = (*i).first, y = (*i).second;

			for (int j = 0; j < 4; j++) {
				int nx = x + dx[j], ny = y + dy[j];

				if (nx < 1 || nx > N || ny < 1 || ny > N) continue;
				if (mm[ny][nx] == 0) continue;
				mm[y][x] = 1;

				flag = 1;
				for (int k = 0; k < arr[y][x].size(); k++) {
					if (l.count(arr[y][x][k])) continue;
					mark[arr[y][x][k].second][arr[y][x][k].first] = 1;
					s.insert(arr[y][x][k]);
				}

				del.insert({ x,y });
			}
		}

		for (auto i = del.begin(); i != del.end(); i++) {
			cand.erase((*i));
			l.insert((*i));
		}

		for (auto i = s.begin(); i != s.end(); i++) {
			if (l.count((*i))) continue;
			cand.insert((*i));
		}
		
		if (flag == 0) break;
	}

	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) cnt += mark[i][j];	
	}

	cout << cnt;
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