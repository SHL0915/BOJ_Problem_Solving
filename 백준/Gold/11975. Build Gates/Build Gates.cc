#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int N, cnt;
string S;
int arr[5005][5005];
int parent[25000005];
int mark[25000005];

int convert(int x, int y);
int Find(int a);
void Union(int a, int b);

void solve() {
	cin >> N;
	cin >> S;
	pii pos = { 2500, 2500 };

	for (int i = 0; i < 25000005; i++) parent[i] = i;

	for (int i = 0; i < S.length(); i++) {
		if (S[i] == 'N') {
			arr[pos.second][pos.first] = 1;
			arr[pos.second + 1][pos.first] = 1;
			arr[pos.second + 2][pos.first] = 1;
			pos.second += 2;
		}
		else if (S[i] == 'S') {
			arr[pos.second][pos.first] = 1;
			arr[pos.second - 1][pos.first] = 1;
			arr[pos.second - 2][pos.first] = 1;
			pos.second -= 2;
		}
		else if (S[i] == 'E') {
			arr[pos.second][pos.first] = 1;
			arr[pos.second][pos.first + 1] = 1;
			arr[pos.second][pos.first + 2] = 1;
			pos.first += 2;
		}
		else {
			arr[pos.second][pos.first] = 1;
			arr[pos.second][pos.first - 1] = 1;
			arr[pos.second][pos.first - 2] = 1;
			pos.first -= 2;
		}
	}

	for (int i = 0; i < 5000; i++) {
		for (int j = 0; j < 5000; j++) {
			if (arr[i][j] == 1) continue;
			int now = convert(j, i);
			for (int k = 0; k < 4; k++) {
				int x = j + dx[k];
				int y = i + dy[k];
				if (x < 0 || x >= 5000 || y < 0 || y >= 5000) continue;
				if (arr[y][x] == 1) continue;
				int nnow = convert(x, y);
				Union(now, nnow);
			}
		}
	}

	for (int i = 0; i < 5000; i++) {
		for (int j = 0; j < 5000; j++) {
			if (arr[i][j] == 1) continue;
			int now = convert(j, i);
			now = Find(now);
			if (mark[now] == 0) {
				cnt++;
				mark[now] = 1;
			}
		}
	}

	cout << cnt - 1;
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
	return y * 4999 + x;
}

int Find(int a) {
	if (a == parent[a]) return parent[a];
	else return parent[a] = Find(parent[a]);
}

void Union(int a, int b) {
	a = Find(a);
	b = Find(b);
	if (a == b) return;
	if (a > b) parent[a] = b;
	else parent[b] = a;
	return;
}