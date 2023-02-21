#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int R, C, idx;
int pos[2];
int arr[2500005];
int mark[2500005];
int parent[2500005];
queue <int> q, temp;

int convert(int x, int y);
pii rev(int a);

int Find(int a);
void Union(int a, int b);

void DFS(int node, int start);
void BFS();


void solve() {
	cin >> R >> C;
	memset(arr, -1, sizeof(arr));
	for (int i = 0; i <= R * C; i++) parent[i] = i;
	for (int i = 0; i < R; i++) {
		string s; cin >> s;
		for (int j = 0; j < C; j++) {
			if (s[j] == 'X') arr[convert(j, i)] = 1;			
			else {
				arr[convert(j, i)] = 0;
				q.push(convert(j, i));
				if (s[j] == 'L') pos[idx++] = convert(j, i);
			}
		}
	}	

	for (int i = 0; i < R ; i++) {
		for (int j = 0; j < C; j++) {
			int now = convert(j, i);
			if (arr[now] == 0) DFS(now, now);
		}
	}

	memset(mark, 0, sizeof(mark));

	int ans = 0;
	while (q.size()) {
		if (Find(pos[0]) == Find(pos[1])) break;
		ans++;
		while (q.size()) BFS();
		while (temp.size()) {
			int f = temp.front();
			temp.pop();
			if (arr[f] == 0) continue;
			arr[f] = 0;
			q.push(f);
			pii pos = rev(f);
			for (int i = 0; i < 4; i++) {
				int nx = pos.first + dx[i];
				int ny = pos.second + dy[i];
				if (nx < 0 || nx >= C || ny < 0 || ny >= R) continue;
				int nf = convert(nx, ny);
				if (arr[nf] != 0) continue;
				Union(f, nf);
			}
		}
	}
	cout << ans;
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
	return y * C + x;
}

pii rev(int a) {
	return { a % C, a / C };
}

int Find(int a) {
	if (parent[a] == a) return parent[a];
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

void BFS() {
	int now = q.front(); q.pop();
	if (mark[now]) return;
	mark[now] = 1;
	pii pos = rev(now);
	for (int i = 0; i < 4; i++) {
		int nx = pos.first + dx[i];
		int ny = pos.second + dy[i];
		if (nx >= C || nx < 0 || ny >= R || ny < 0) continue;
		int next = convert(nx, ny);
		if(arr[next] == 1) temp.push(convert(nx, ny));
	}
	return;
}

void DFS(int node, int start) {
	if (mark[node]) return;
	if (arr[node]) return;
	mark[node] = 1;
	Union(node, start);
	pii pos = rev(node);
	for (int i = 0; i < 4; i++) {
		int nx = pos.first + dx[i];
		int ny = pos.second + dy[i];
		if (nx >= C || nx < 0 || ny >= R || ny < 0) continue;
		DFS(convert(nx, ny), start);
	}
	return;
}