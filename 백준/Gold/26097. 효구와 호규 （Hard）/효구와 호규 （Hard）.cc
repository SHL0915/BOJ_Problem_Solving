#include <bits/stdc++.h>
using namespace std;

int N, M, zero_cnt, one_cnt, sum, flag, cnt;
int arr[1000][1000];
int mask[1000][1000];
int dx[4] = { 1, -1 , 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
set <pair<int, int>> zero_candidate, one_candidate;

void makeCandidate(int x, int y);
bool isValid(int x, int y);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 0) zero_cnt++;
			else one_cnt++;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (i % 2 == 0 && j % 2 == 0) mask[i][j] = 1;
			else if (i % 2 == 1 && j % 2 == 1) mask[i][j] = 1;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) if (arr[i][j] == mask[i][j]) sum++;
	}
	if (zero_cnt % 2 == 1 || one_cnt % 2 == 1 || sum == 0 || sum == N * M) {
		cout << -1;
		return 0;
	}
	else cout << 1 << '\n';
	for (int i = 0; i < N; i++) {
		if (flag == 1) break;
		for (int j = 0; j < M; j++) {
			if (flag == 1) break;
			for (int k = 0; k < 4; k++) {
				int nx = j + dx[k];
				int ny = i + dy[k];
				if (isValid(nx, ny) == false) continue;
				if (arr[ny][nx] == arr[i][j]) {
					cout << i + 1 << " " << j + 1 << " " << ny + 1 << " " << nx + 1 << '\n';
					cnt++;
					arr[i][j] = -1;
					arr[ny][nx] = -1;
					makeCandidate(j, i);
					makeCandidate(nx, ny);
					flag = 1;
					break;
				}
			}
		}
	}
	while (cnt < N * M / 2) {
		while (zero_candidate.size() >= 2) {
			int pos = 0;
			pair<int, int> temp[2];
			for (auto i = zero_candidate.begin(); i != zero_candidate.end(); i++) {
				if (pos == 2) break;
				temp[pos++] = *i;
			}
			zero_candidate.erase(zero_candidate.begin());
			zero_candidate.erase(zero_candidate.begin());
			cout << temp[0].second + 1 << " " << temp[0].first + 1 << " " << temp[1].second + 1 << " " << temp[1].first + 1 << '\n';
			cnt++;
			arr[temp[0].second][temp[0].first] = -1;
			arr[temp[1].second][temp[1].first] = -1;
			makeCandidate(temp[0].first, temp[0].second);
			makeCandidate(temp[1].first, temp[1].second);
		}
		while (one_candidate.size() >= 2) {
			int pos = 0;
			pair<int, int> temp[2];
			for (auto i = one_candidate.begin(); i != one_candidate.end(); i++) {
				if (pos == 2) break;
				temp[pos++] = *i;
			}
			one_candidate.erase(one_candidate.begin());
			one_candidate.erase(one_candidate.begin());
			cout << temp[0].second + 1 << " " << temp[0].first + 1 << " " << temp[1].second + 1 << " " << temp[1].first + 1 << '\n';
			cnt++;
			arr[temp[0].second][temp[0].first] = -1;
			arr[temp[1].second][temp[1].first] = -1;
			makeCandidate(temp[0].first, temp[0].second);
			makeCandidate(temp[1].first, temp[1].second);
		}
	}
	return 0;
}

bool isValid(int x, int y) {
	if (x < 0 || x > M - 1 || y < 0 || y > N - 1) return false;
	if (arr[y][x] == -1) return false;
	return true;
}

void makeCandidate(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (isValid(nx, ny) == false) continue;
		if (arr[ny][nx] == 0) zero_candidate.insert({ nx,ny });
		else one_candidate.insert({ nx,ny });
	}
}