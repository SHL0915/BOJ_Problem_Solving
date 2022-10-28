#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int R, C, M, ans;
vector <pair<pair<int, int>, int>> map[101][101];

bool cmp(pair<pair<int, int>, int> A, pair<pair<int, int>, int> B) {
	return A.second > B.second;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> R >> C >> M;
	for (int i = 0; i < M; i++) {
		int r, c, s, d, z;
		cin >> r >> c >> s >> d >> z;
		map[r][c].push_back({ {s,d},z });
	}
	for (int i = 1; i <= C; i++) {		
		for (int j = 1; j <= R; j++) {
			if (map[j][i].size() == 1) {
				ans += map[j][i][0].second;
				map[j][i].clear();
				break;
			}
		}
		vector <pair<pair<int, int>, int>> temp[101][101];
		for (int j = 1; j <= R; j++) {
			for (int k = 1; k <= C; k++) {
				if (map[j][k].size() != 0) {
					int s = map[j][k][0].first.first;
					int d = map[j][k][0].first.second;
					int r = j, c = k;
					while (s != 0) {
						if (d == 1) {							
							if (r == 1) {
								r = 2;
								d = 2;
							}
							else r--;
						}
						else if (d == 2) {
							if (r == R) {
								r = R - 1;
								d = 1;
							}
							else r++;
						}
						else if (d == 3) {
							if (c == C) {
								c = C - 1;
								d = 4;
							}
							else c++;
						}
						else if (d == 4) {
							if (c == 1) {
								c = 2;
								d = 3;
							}
							else c--;
						}
						s--;
					}
					temp[r][c].push_back({ {map[j][k][0].first.first, d}, map[j][k][0].second });					
					map[j][k].clear();
				}
			}
		}
		for (int j = 1; j <= R; j++) {
			for (int k = 1; k <= C; k++) {
				if (temp[j][k].size() >= 1) {
					sort(temp[j][k].begin(), temp[j][k].end(), cmp);
					map[j][k].push_back(temp[j][k][0]);
				}
			}
		}		
	}
	cout << ans;
	return 0;
}