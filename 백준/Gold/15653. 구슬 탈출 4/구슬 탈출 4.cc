#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int N, M;
int arr[11][11];
int mark[11][11][11][11];
pii R, B, H;
queue <pair<pair<pii, pii>, int>> q;

void BFS();

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < M; j++) {
			if (s[j] == '#') arr[i][j] = 1;
			else if (s[j] == 'R') R = { j,i };
			else if (s[j] == 'B') B = { j,i };
			else if (s[j] == 'O') H = { j,i };
		}
	}
	q.push({ {R,B},0 });
	while (q.size()) BFS();
	cout << -1;
	return 0;
}

void BFS() {
	pair<pair<pii, pii>, int> f = q.front();
	q.pop();
	pii R = f.first.first;
	pii B = f.first.second;
	int d = f.second;
	if (mark[R.first][R.second][B.first][B.second] != 0) return;
	mark[R.first][R.second][B.first][B.second] = 1;
	if (R == H) {
		cout << d;
		exit(0);
	}
	for (int i = 0; i < 4; i++) {
		int nrx = R.first, nry = R.second, nbx = B.first, nby = B.second, flag = 0;
		while (1) {
			if (nrx + dx[i] < 0 || nrx + dx[i] > M - 1 || nry + dy[i] < 0 || nry + dy[i] > N - 1) break;
			if (arr[nry + dy[i]][nrx + dx[i]] == 1) break;
			nrx += dx[i];
			nry += dy[i];
			if (make_pair(nrx, nry) == H) break;
		}
		while (1) {
			if (nbx + dx[i] < 0 || nbx + dx[i] > M - 1 || nby + dy[i] < 0 || nby + dy[i] > N - 1) break;
			if (arr[nby + dy[i]][nbx + dx[i]] == 1) break;
			nbx += dx[i];
			nby += dy[i];
			if (make_pair(nbx, nby) == H) {
				flag = 1;
				break;
			}
		}
		if (flag == 1) continue;
		if (make_pair(nrx, nry) != make_pair(nbx, nby)) q.push({ {{nrx,nry},{nbx,nby}}, d + 1 });
		else {
			if (i == 0) {
				if (R.first > B.first) nbx--;
				else nrx--;
			}
			else if (i == 1) {
				if (R.second > B.second) nby--;
				else nry--;
			}
			else if (i == 2) {
				if (R.first < B.first) nbx++;
				else nrx++;
			}
			else {
				if (R.second < B.second) nby++;
				else nry++;
			}
			q.push({ {{nrx,nry},{nbx,nby}}, d + 1 });
		}
	}	
	return;
}