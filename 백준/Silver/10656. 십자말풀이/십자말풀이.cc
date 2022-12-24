#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[55][55];
vector <pair<int, int>> ans;

bool hor(int x, int y);
bool ver(int x, int y);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		string s;
		cin >> s;
		for (int j = 1; j <= M; j++) {
			if (s[j - 1] == '#') arr[i][j] = 1;
			else arr[i][j] = 0;
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (hor(j, i) || ver(j, i)) ans.push_back({ i,j });
		}
	}
	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++) cout << ans[i].first << " " << ans[i].second << '\n';
	return 0;
}

bool hor(int x, int y) {
	if (x - 1 >= 1 && arr[y][x - 1] == 0) return false;
	for (int i = 0; i < 3; i++) {
		int nx = x + i;
		if (nx > M || arr[y][nx] == 1) return false;
	}
	return true;
}

bool ver(int x, int y) {
	if (y - 1 >= 1 && arr[y - 1][x] == 0) return false;
	for (int i = 0; i < 3; i++) {
		int ny = y + i;
		if (ny > N || arr[ny][x] == 1) return false;
	}
	return true;
}