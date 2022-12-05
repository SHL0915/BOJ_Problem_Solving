#include <bits/stdc++.h>
using namespace std;
typedef pair<pair<int, int>, int> piii;

int N, M;
int arr[100][100];
int temp[100][100];
vector <piii> cross;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < M; j++) if (s[j] == '*') arr[i][j] = 1;
	}
	for (int i = 1; i < N - 1; i++) {
		for (int j = 1; j < M - 1; j++) {
			if (arr[i][j] == 0) continue;
			for (int k = 1; ; k++) {
				int u = i - k;
				int d = i + k;
				int l = j - k;
				int r = j + k;
				if (u < 0 || u > N - 1 || d < 0 || d > N - 1 || l < 0 || l > M - 1 || r < 0 || r > M - 1) break;
				if (arr[u][j] + arr[d][j] + arr[i][l] + arr[i][r] != 4) break;
				cross.push_back({ {j,i},k });
			}
		}
	}
	for (int i = 0; i < cross.size(); i++) {
		int x = cross[i].first.first;
		int y = cross[i].first.second;
		for (int j = 0; j <= cross[i].second; j++) {
			int u = y - j;
			int d = y + j;
			int l = x - j;
			int r = x + j;
			temp[u][x] = 1;
			temp[d][x] = 1;
			temp[y][l] = 1;
			temp[y][r] = 1;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (temp[i][j] != arr[i][j]) {
				cout << -1;
				return 0;
			}
		}
	}
	cout << cross.size() << '\n';
	for (int i = 0; i < cross.size(); i++) cout << cross[i].first.second + 1 << " " << cross[i].first.first + 1 << " " << cross[i].second << '\n';
	return 0;
}