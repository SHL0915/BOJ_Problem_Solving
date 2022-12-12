#include <bits/stdc++.h>
using namespace std;
typedef pair<int, pair<int, int>> piii;
const int INF = 0x3f3f3f3f;
int dx[8] = { 0,1,1,1,0,-1,-1,-1 };
int dy[8] = { 1,1,0,-1,-1,-1,0,1 };

int R, C;
int arr[500][500];
int ball[500][500];
vector <pair<int, int>> sorted;

piii check(int x, int y);
bool cmp(pair<int, int> A, pair<int, int> B) {
	return arr[A.second][A.first] > arr[B.second][B.first];
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> arr[i][j];
			ball[i][j] = 1;
			sorted.push_back({ j,i });
		}
	}
	sort(sorted.begin(), sorted.end(), cmp);
	for (int i = 0; i < sorted.size(); i++) {
		int x = sorted[i].first;
		int y = sorted[i].second;
		if (ball[y][x] == 0) continue;
		piii temp = { INF, {-1,-1} };
		for (int k = 0; k < 8; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			temp = min(temp, check(nx, ny));
		}
		if (temp.first > arr[y][x]) continue;
		else {
			ball[temp.second.second][temp.second.first] += ball[y][x];
			ball[y][x] = 0;
		}
	}	
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) cout << ball[i][j] << " ";
		cout << '\n';
	}
	return 0;
}

piii check(int x, int y) {
	piii temp = { INF, {-1,-1} };
	if (x < 0 || x > C - 1 || y < 0 || y > R - 1) return temp;
	temp = { arr[y][x], {x,y} };
	return temp;
}