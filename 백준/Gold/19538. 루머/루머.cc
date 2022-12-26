#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int N, M, t;
vector <int> graph[200001];
set <int> people[200001];
int sz[200001];
int ans[200001];
queue <int> q;
queue <pii> cand;

void BFS();

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		while (1) {
			int A;
			cin >> A;
			if (A == 0) break;
			graph[i].push_back(A);
			graph[A].push_back(i);
			people[i].insert(A);
			people[A].insert(i);
		}
	}
	for (int i = 1; i <= N; i++) sz[i] = people[i].size();
	memset(ans, -1, sizeof(ans));
	cin >> M;
	for (int i = 0; i < M; i++) {
		int A;
		cin >> A;
		q.push(A);
		ans[A] = 0;
	}
	while (q.size()) {
		t++;
		while (q.size()) {
			int now = q.front();
			q.pop();
			for (int i = 0; i < graph[now].size(); i++) cand.push({ graph[now][i], now });
		}
		while (cand.size()) BFS();	
	}
	for (int i = 1; i <= N; i++) cout << ans[i] << ' ';
	return 0;
}

void BFS() {
	pii f = cand.front();
	cand.pop();
	int now = f.first;
	int par = f.second;
	if (people[now].count(par)) people[now].erase(par);
	if (ans[now] == -1 && (sz[now] != 0 && people[now].size() <= sz[now] / 2)) {
		ans[now] = t;
		q.push(now);
	}
	return;
}