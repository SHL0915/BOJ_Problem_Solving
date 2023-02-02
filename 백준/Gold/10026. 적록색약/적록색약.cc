#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int N, cnt1, cnt2;
int arr[101][101];
int mark1[101][101];
int mark2[101][101];

void DFS1(int x, int y, int type);
void DFS2(int x, int y, int type);

void solve() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < N; j++) {
			if (s[j] == 'G') arr[i][j] = 1;
			else if (s[j] == 'R') arr[i][j] = 2;
			else arr[i][j] = 0;
		}
	}	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (mark1[i][j] == 0) {
				cnt1++;
				DFS1(j, i, arr[i][j]);
			}
			if (mark2[i][j] == 0) {
				cnt2++;
				if (arr[i][j] > 0) DFS2(j, i, 1);
				else DFS2(j, i, 0);
			}
		}
	}
	cout << cnt1 << " " << cnt2;
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

void DFS1(int x, int y, int type) {
	if (x < 0 || x >= N || y < 0 || y >= N) return;
	if (arr[y][x] != type) return;
	if (mark1[y][x]) return;
	mark1[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		DFS1(nx, ny, type);
	}
	return;
}

void DFS2(int x, int y, int type) {
	if (x < 0 || x >= N || y < 0 || y >= N) return;
	if (type && arr[y][x] == 0) return;
	if (type == 0 && (arr[y][x] > 0)) return;
	if (mark2[y][x]) return;
	mark2[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		DFS2(nx, ny, type);
	}
	return;
}