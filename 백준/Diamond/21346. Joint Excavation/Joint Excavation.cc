#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M;
vector <int> graph[200005];
set <int> A, B;
vector <int> path;
int mark[200005];

void DFS(int node);

void solve() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for (int i = 1; i <= N; i++) A.insert(i);

	DFS(1);

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

void DFS(int node) {
	mark[node] = 1;

	if (A.size() == B.size()) {
		cout << path.size() << " " << A.size() << '\n';
		for (int i = 0; i < path.size(); i++) cout << path[i] << " ";
		cout << '\n';
		for (auto i : A) cout << i << " ";
		cout << '\n';
		for (auto i : B) cout << i << " ";
		exit(0);
	}

	path.push_back(node);
	A.erase(node);

	if (A.size() == B.size()) {
		cout << path.size() << " " << A.size() << '\n';
		for (int i = 0; i < path.size(); i++) cout << path[i] << " ";
		cout << '\n';
		for (auto i : A) cout << i << " ";
		cout << '\n';
		for (auto i : B) cout << i << " ";
		exit(0);
	}

	for (int i = 0; i < graph[node].size(); i++) {
		int next = graph[node][i];
		if (mark[next]) continue;
		DFS(next);
	}

	if (A.size() == B.size()) {
		cout << path.size() << " " << A.size() << '\n';
		for (int i = 0; i < path.size(); i++) cout << path[i] << " ";
		cout << '\n';
		for (auto i : A) cout << i << " ";
		cout << '\n';
		for (auto i : B) cout << i << " ";
		exit(0);
	}

	B.insert(path.back());
	path.pop_back();

	if (A.size() == B.size()) {
		cout << path.size() << " " << A.size() << '\n';
		for (int i = 0; i < path.size(); i++) cout << path[i] << " ";
		cout << '\n';
		for (auto i : A) cout << i << " ";
		cout << '\n';
		for (auto i : B) cout << i << " ";
		exit(0);
	}

	return;
}