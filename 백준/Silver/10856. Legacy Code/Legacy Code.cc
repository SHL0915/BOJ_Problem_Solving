#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, id;
vector <int> graph[405];
map <string, int> convert;
int mark[405];
vector <int> start;

void DFS(int node);

void solve() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		string s; cin >> s;
		if (convert[s] == 0) {
			id++;
			convert[s] = id;
		}
		string check = "";
		int flag = 0;

		for (int j = 0; j < s.length(); j++) {
			if (flag == 2) check += s[j];
			if (s[j] == ':') flag++;
		}
		if (check == "PROGRAM") start.push_back(convert[s]);

		int k; cin >> k;
		for (int j = 0; j < k; j++) {
			string a; cin >> a;
			if (convert[a] == 0) {
				id++;
				convert[a] = id;
			}
			graph[convert[a]].push_back(convert[s]);
		}
	}

	for (int i = 0; i < start.size(); i++) DFS(start[i]);

	int cnt = 0;
	for (int i = 1; i <= N; i++) if (mark[i] == 0) cnt++;

	cout << cnt;
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
	if (mark[node]) return;
	mark[node] = 1;
	for (int i = 0; i < graph[node].size(); i++) DFS(graph[node][i]);
	return;
}