#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int M, N, K, cnt;
int mark[100][100];
vector <int> area;

void DrawRec(pair<int, int> ld, pair <int, int> ru);
void DFS(int x, int y);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> M >> N >> K;
	for (int i = 0; i < K; i++) {
		int xd, yd, xu, yu;
		cin >> xd >> yd >> xu >> yu;
		DrawRec({ xd,yd }, { xu,yu });
	}
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (mark[i][j] == 0) {
				cnt = 0;
				DFS(j, i);
				area.push_back(cnt);
			}
		}
	}
	sort(area.begin(), area.end());
	cout << area.size() << " ";
	for (int i = 0; i < area.size(); i++) cout << area[i] << " ";
	return 0;
}

void DrawRec(pair<int, int> ld, pair <int, int> ru) {
	for (int i = ld.second; i < ru.second; i++) {
		for (int j = ld.first; j < ru.first; j++) mark[i][j] = 1;
	}
	return;
}

void DFS(int x, int y) {
	if (mark[y][x] == 1) return;
	mark[y][x] = 1;
	cnt++;
	if (x > 0) DFS(x - 1, y);
	if (x < N - 1) DFS(x + 1, y);
	if (y > 0) DFS(x, y - 1);
	if (y < M - 1)DFS(x, y + 1);
	return;
}