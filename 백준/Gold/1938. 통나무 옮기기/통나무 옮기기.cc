#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int N;
int arr[55][55];
pii S, E;
queue <pair<pii, int>> q;
map <pii, int> mark;

int convert(int x, int y);
pii rev(int a);
void BFS();

void solve() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		string s; cin >> s;
		for (int j = 1; j <= N; j++) {
			if (s[j - 1] == 'B') arr[i][j] = 2;
			else if (s[j - 1] == 'E') arr[i][j] = 3;
			else arr[i][j] = s[j - 1] - '0';
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (arr[i][j] == 2) {
				if (arr[i - 1][j] == 2 && arr[i + 1][j] == 2) S = { convert(j,i), 0 };				
				if (arr[i][j - 1] == 2 && arr[i][j + 1] == 2) S = { convert(j,i), 1 };
			}
			if (arr[i][j] == 3) {
				if (arr[i - 1][j] == 3 && arr[i + 1][j] == 3) E = { convert(j,i), 0 };
				if (arr[i][j - 1] == 3 && arr[i][j + 1] == 3) E = { convert(j,i), 1 };
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) if (arr[i][j] == 2 || arr[i][j] == 3) arr[i][j] = 0;
	}

	q.push({ S, 1 });
	while (q.size()) BFS();

	cout << 0;
	return;
}

int main(void) {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}

int convert(int x, int y) {
	return (y - 1) * N + x;
}

pii rev(int a) {
	return { (a % N) == 0 ? N : a % N, ((a - 1) / N) + 1 };
}

void BFS() {
	pair<pii, int> f = q.front(); q.pop();
	int center = f.first.first;
	int type = f.first.second;
	int d = f.second;
	int x = rev(center).first, y = rev(center).second;

	if (type) {
		if (x - 1 < 1 || x + 1 > N || arr[y][x - 1] == 1 || arr[y][x + 1] == 1) return;
	}
	else {
		if (y - 1 < 1 || y + 1 > N || arr[y - 1][x] == 1 || arr[y + 1][x] == 1) return;
	}

	if (mark[f.first] != 0) return;
	mark[f.first] = 1;


	if (f.first == E) {
		cout << d - 1;
		exit(0);
	}

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 1 || nx > N || ny < 1 || ny > N) continue;
		if (arr[ny][nx] == 1) continue;
		q.push({ {convert(nx,ny), type }, d + 1 });
	}

	int sum = 0;
	for (int i = y - 1; i <= y + 1; i++) {
		for (int j = x - 1; j <= x + 1; j++) sum += arr[i][j];
	}

	if (sum == 0) q.push({ {center, type ^ 1}, d + 1 });

	return;
}