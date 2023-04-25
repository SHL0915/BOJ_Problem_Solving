#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, id;
map <string, int> name;
vector <int> graph[200005];
int in_degree[200005];

void Topology();

void solve() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		string a, b, c;
		cin >> a >> b >> c;
		if (name[a] == 0) {
			id++;
			name[a] = id;
		}
		if (name[c] == 0) {
			id++;
			name[c] = id;
		}

		if (b == ">") {
			graph[name[a]].push_back(name[c]);
			in_degree[name[c]]++;
		}
		else {
			graph[name[c]].push_back(name[a]);
			in_degree[name[a]]++;
		}
	}

	Topology();
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


void Topology() {
	queue <int> q;

	for (int i = 1; i <= name.size(); i++) if (in_degree[i] == 0) q.push(i);

	for (int i = 1; i <= name.size(); i++) {
		if (q.size() == 0) {
			cout << "impossible";
			return;
		}
		int f = q.front(); q.pop();
		for (int j = 0; j < graph[f].size(); j++) {
			int next = graph[f][j];
			if (--in_degree[next] == 0) q.push(next);
		}
	}

	cout << "possible";
	return;
}