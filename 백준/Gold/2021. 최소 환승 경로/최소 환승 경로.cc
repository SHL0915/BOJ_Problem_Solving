#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, L, S, E;
vector <int> graph[200005];
vector <int> arr[100005];
int mark[200005];
int chk[200005];
queue <int> q;

void BFS();

void solve() {
	cin >> N >> L;
	for (int i = 1; i <= L; i++) {
		while (1) {
			int a; cin >> a;
			if (a == -1) break;
			arr[i].push_back(a);
			graph[a].push_back(N + i);
			graph[N + i].push_back(a);
		}
	}

	cin >> S >> E;

	memset(mark, -1, sizeof(mark));

	for (int i = 1; i <= L; i++) {
		for (int j = 0; j < arr[i].size(); j++) {
			if (arr[i][j] == S) {
				mark[N + i] = 0;
				q.push(N + i);
			}
		}
	}
	
	while (q.size()) BFS();

	cout << -1;
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
	int now = q.front(); q.pop();
	if (now == E) {
		cout << mark[now] << endl;
		exit(0);
	}

	for (int i = 0; i < graph[now].size(); i++) {
		int next = graph[now][i];
		if (mark[next] != -1) continue;
		q.push(next);
		if (next > N) mark[next] = mark[now] + 1;
		else mark[next] = mark[now];
	}

	return;
}