#include <bits/stdc++.h>
using namespace std;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int t;
int H, W, ans, cnt;
char arr[105][105];
int mark[105][105];
vector <pair<int, int>> door[26];
vector <int> k;

void DFS(int x, int y);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> H >> W;
		ans = 0;
		for (int i = 0; i < 105; i++) {
			for (int j = 0; j < 105; j++) arr[i][j] = '.';
		}
		for (int i = 0; i < 26; i++) door[i].clear();
		for (int i = 1; i <= H; i++) {
			string s;
			cin >> s;
			for (int j = 1; j <= W; j++) {
				if (s[j - 1] >= 'A' && s[j - 1] <= 'Z') {
					arr[i][j] = '*';
					door[s[j - 1] - 'A'].push_back({ j,i });
				}
				else arr[i][j] = s[j - 1];
			}
		}
		string key;
		cin >> key;
		if (key != "0") {
			for (int i = 0; i < key.size(); i++) {
				for (int j = 0; j < door[key[i] - 'a'].size(); j++) {
					pair<int, int> now = door[key[i] - 'a'][j];
					arr[now.second][now.first] = '.';
				}
			}
		}
		while (1) {
			cnt = 0;
			memset(mark, 0, sizeof(mark));
			DFS(0, 0);
			if (cnt == 0) break;
			for (int i = 0; i < k.size(); i++) {
				for (int j = 0; j < door[k[i]].size(); j++) {
					pair<int, int> now = door[k[i]][j];
					arr[now.second][now.first] = '.';
				}
			}
			k.clear();
		}
		cout << ans << '\n';
	}
	return 0;
}

void DFS(int x, int y) {
	if (x < 0 || x > W + 1 || y < 0 || y > H + 1) return;
	if (arr[y][x] == '*') return;
	if (mark[y][x] == 1) return;
	mark[y][x] = 1;
	if (arr[y][x] == '$') {
		ans++;
		arr[y][x] = '.';
	}
	else if (arr[y][x] >= 'a' && arr[y][x] <= 'z') {
		k.push_back(arr[y][x] - 'a');
		arr[y][x] = '.';
		cnt++;
	}
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		DFS(nx, ny);
	}
	return;
}