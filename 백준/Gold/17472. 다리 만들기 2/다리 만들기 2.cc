#include <bits/stdc++.h>
using namespace std;

int N, M, area, cnt, ans;
pair<int, int> cmp;
int Map[10][10];
int mark[10][10];
int parent[101];
vector <pair<int, pair<int, int>>> graph;

void DFS(int x, int y, int color);
int Find(int node);
void Union(int A, int B);
pair<int, int> findEdge(int x, int y, int dir, int color);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N * M; i++) parent[i] = i;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) cin >> Map[i][j];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (mark[i][j] == 0 && Map[i][j] != 0) {
				area++;
				DFS(j, i, area);
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (mark[i][j] == 0 && Map[i][j] != 0) {
				area++;
				DFS(j, i, area);
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (mark[i][j] != 0) {
				for (int k = 0; k < 4; k++) {
					pair<int, int> E = findEdge(j, i, k, mark[i][j]);
					if (E == cmp) continue;
					if (E.second < 2) continue;
					graph.push_back({ E.second, {mark[i][j],E.first} });
				}
			}
		}
	}
	sort(graph.begin(), graph.end());
	for (int i = 0; i < graph.size(); i++) {
		if (cnt == area - 1) break;
		int A = Find(graph[i].second.first);
		int B = Find(graph[i].second.second);
		if (A == B) continue;
		Union(A, B);
		ans += graph[i].first;
		cnt++;
	}
	if (cnt != area - 1) cout << -1;
	else cout << ans;
	return 0;
}

void DFS(int x, int y, int color) {
	if (x < 0 || x > M - 1 || y < 0 || y > N - 1) return;
	if (Map[y][x] == 0) return;
	if (mark[y][x] != 0) return;
	mark[y][x] = color;
	DFS(x - 1, y, color);
	DFS(x + 1, y, color);
	DFS(x, y - 1, color);
	DFS(x, y + 1, color);
	return;
}

int Find(int node) {
	if (parent[node] == node) return parent[node];
	else return parent[node] = Find(parent[node]);
}

void Union(int A, int B) {
	A = Find(A);
	B = Find(B);
	if (A == B) return;
	if (A > B) parent[A] = B;
	else parent[B] = A;
	return;
}

pair<int, int> findEdge(int x, int y, int dir, int color) {
	pair<int, int> ret = { 0,0 };
	if (dir == 0) {
		for (int i = x + 1; i < M; i++) {
			if (mark[y][i] == color) break;
			if (mark[y][i] != 0 && mark[y][i] != color) {
				ret = { mark[y][i], i - x - 1 };
				break;
			}
		}
	}
	else if (dir == 1) {
		for (int i = x - 1; i >= 0; i--) {
			if (mark[y][i] == color) break;
			if (mark[y][i] != 0 && mark[y][i] != color) {
				ret = { mark[y][i],x - i - 1 };
				break;
			}
		}
	}
	else if (dir == 2) {
		for (int i = y + 1; i < N; i++) {
			if (mark[i][x] == color) break;
			if (mark[i][x] != 0 && mark[i][x] != color) {
				ret = { mark[i][x],i - y - 1 };
				break;
			}
		}
	}
	else {
		for (int i = y - 1; i >= 0; i--) {
			if (mark[i][x] == color) break;
			if (mark[i][x] != 0 && mark[i][x] != color) {
				ret = { mark[i][x], y - i - 1 };
				break;
			}
		}
	}
	return ret;
}