#include <bits/stdc++.h>
#include <random>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
pii S, E;
pii arr[100005];
int small[5][5];
queue <pii> q;

void BFS();
map <pii, int> mark_A;
map <pii, int> mark_B;

void solve() {
	cin >> N;
	cin >> S.first >> S.second;
	cin >> E.first >> E.second;

	for (int i = 0; i < N; i++) cin >> arr[i].first >> arr[i].second;

	mark_A[S] = 1;

	for (int i = 0; i < N; i++) {
		int nx = S.first + arr[i].first;
		int ny = S.second + arr[i].second;
		if (nx < 1 || nx > N || ny < 1 || ny > N) continue;
		mark_A[{nx, ny}] = 1;
	}

	if (mark_A.count(E)) {
		cout << "Alice wins";
		return;
	}

	for (int i = 0; i < N; i++) {
		int nx = E.first - arr[i].first;
		int ny = E.second - arr[i].second;
		if (nx < 1 || nx > N || ny < 1 || ny > N) continue;
		if (mark_A.count({ nx,ny })) {
			cout << "Alice wins";
			return;
		}
	}

	if (N <= 3) {
		int flag = 0;
		memset(small, -1, sizeof(small));
		q.push({ E });
		small[E.second][E.first] = 0;
		while (q.size()) BFS();

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (small[i][j] == -1) {
					cout << "tie " << j << " " << i;
					return;
				}
			}
		}
		
		cout << "Bob wins";
		return;
	}

	cout << "tie ";

	mark_B[{E}] = 1;
	
	for (int i = 0; i < N; i++) {
		int nx = E.first + arr[i].first;
		int ny = E.second + arr[i].second;
		if (nx < 1 || nx > N || ny < 1 || ny > N) continue;
		mark_B[{nx, ny}] = 1;
	}

	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(1, N);

	while (1) {
		int x = dis(gen), y = dis(gen);

		if (mark_B.count({ x,y })) continue;

		int flag = 0;

		for (int i = 0; i < N; i++) {
			int nx = x - arr[i].first;
			int ny = y - arr[i].second;
			if (nx < 1 || nx > N || ny < 1 || ny > N) continue;
			if (mark_B.count({ nx,ny })) {
				flag = 1;
				break;
			}
		}

		if (flag == 1) continue;
		else {
			cout << x << " " << y;
			break;
		}
	}

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

void BFS() {
	pii f = q.front(); q.pop();
	int x = f.first;
	int y = f.second;
	if (small[y][x] == 2) return;

	for (int i = 0; i < N; i++) {
		int nx = x + arr[i].first;
		int ny = y + arr[i].second;
		if (nx < 1 || nx > N || ny < 1 || ny > N) continue;
		if (small[ny][nx] != -1) continue;
		small[ny][nx] = small[y][x] + 1;
		q.push({ nx, ny });
	}
}