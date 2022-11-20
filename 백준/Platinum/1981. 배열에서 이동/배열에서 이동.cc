#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int INF = 1234567890;

int N, ans = INF;
int map[101][101];
int mark[101][101];
vector <int> num;

void DFS(int x, int y, int min_num, int max_num);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <=N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
			num.push_back(map[i][j]);
		}
	}
	sort(num.begin(), num.end());
	num.erase(unique(num.begin(), num.end()), num.end());
	int pos = 0;
	for (int i = 0; i < num.size(); i++) {
		if (map[1][1] > num[i]) continue;
		for (int j = pos; j <= i; j++) {
			if (map[1][1] < num[j]) break;
			for (int k = 1; k <= N; k++) {
				for (int l = 1; l <= N; l++) mark[k][l] = 0;
			}			
			DFS(1, 1, num[j], num[i]);			
			if (mark[N][N] == 1) {
				pos++;
				ans = min(ans, num[i] - num[j]);
			}
			else break;
		}
	}
	cout << ans;
	return 0;
}

void DFS(int x, int y, int min_num, int max_num) {
	if (x < 1 || x > N || y < 1 || y > N) return;
	if (map[y][x] < min_num || map[y][x] > max_num) return;	
	if (mark[y][x] != 0) return;
	mark[y][x] = 1;
	DFS(x - 1, y, min_num, max_num);
	DFS(x + 1, y, min_num, max_num);
	DFS(x, y - 1, min_num, max_num);
	DFS(x , y + 1, min_num, max_num);
}