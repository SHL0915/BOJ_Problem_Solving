#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int N, M, cnt, ans;
int arr[305][305];
int mark[305][305];

void countNum();
void DFS(int x, int y);
int check(int x, int y);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) cin >> arr[i][j];
	}
	countNum();
	if (cnt >= 2) {
		cout << 0;
		return 0;
	}
	while (1) {
		ans++;
		vector <pair<pii, int>> v;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (arr[i][j] > 0) {
					int val = 0;
					for (int k = 0; k < 4; k++) {
						int nx = j + dx[k];
						int ny = i + dy[k];
						val += check(nx, ny);
					}
					v.push_back({ {j,i}, val });
				}
			}
		}
		for (int i = 0; i < v.size(); i++) {
			int x = v[i].first.first;
			int y = v[i].first.second;
			int val = v[i].second;
			arr[y][x] -= val;
			if (arr[y][x] < 0) arr[y][x] = 0;
		}
		countNum();
		if (cnt >= 2) {
			cout << ans;
			return 0;
		}
		if (cnt == 0) {
			cout << 0;
			return 0;
		}
	}
	return 0;
}

void countNum() {
	memset(mark, 0, sizeof(mark));
	cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] > 0 && mark[i][j] == 0) {
				DFS(j, i);
				cnt++;
			}
		}
	}
}

void DFS(int x, int y) {
	if (x < 0 || x > M - 1 || y < 0 || y > N - 1) return;	
	if (arr[y][x] == 0) return;
	if (mark[y][x] != 0) return;	
	mark[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		DFS(nx, ny);
	}
}

int check(int x, int y) {
	if (x < 0 || x > M - 1 || y < 0 || y > N - 1) return 0;
	if (arr[y][x] == 0) return 1;
	else return 0;
}