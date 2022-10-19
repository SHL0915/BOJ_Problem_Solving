#include <iostream>
using namespace std;

int T, H, W, ans;
char grid[100][100];
int mark[100][100];

void DFS(int x, int y);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> H >> W;
		ans = 0;
		for (int j = 0; j < H; j++) {
			for (int k = 0; k < W; k++) mark[j][k] = 0;
		}
		for (int j = 0; j < H; j++) {
			string s;
			cin >> s;
			for (int k = 0; k < W; k++) {
				grid[j][k] = s[k];
				if (s[k] == '.') mark[j][k] = 1;
			}
		}
		for (int j = 0; j < H; j++) {
			for (int k = 0; k < W; k++) {
				if (mark[j][k] == 0) {
					ans++;
					DFS(k, j);
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;	
}

void DFS(int x, int y) {
	if (mark[y][x] == 1) return;
	mark[y][x] = 1;
	if (x > 0) DFS(x - 1, y);
	if (x < W - 1) DFS(x + 1, y);
	if (y > 0) DFS(x, y - 1);
	if (y < H - 1) DFS(x, y + 1);
	return;
}