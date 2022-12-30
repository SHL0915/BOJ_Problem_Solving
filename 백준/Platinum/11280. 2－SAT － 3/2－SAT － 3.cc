#include <bits/stdc++.h>
using namespace std;

int N, M, cnt;
vector <int> graph[20001];
int par[20001];
int mark[20001];
int ID[20001];
stack <int> s;
vector <vector<int>> SCC;

int convert(int node) {
	if (node < 0) return -node * 2;
	else return node * 2 - 1;
}
int DFS(int node);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;
		graph[convert(-A)].push_back(convert(B));
		graph[convert(-B)].push_back(convert(A));
	}
	for (int i = 1; i <= 2 * N; i++) if (par[i] == 0) DFS(i);
	for (int i = 1; i <= N; i++) {
		if (ID[i * 2] == ID[i * 2 - 1]) {
			cout << 0;
			return 0;
		}
	}
	cout << 1;
	return 0;
}

int DFS(int node) {
	par[node] = ++cnt;
	int ret = par[node];
	s.push(node);
	for (int i = 0; i < graph[node].size(); i++) {
		int next = graph[node][i];
		if (par[next] == 0) ret = min(ret, DFS(next));
		else if (mark[next] == 0) ret = min(ret, par[next]);
	}
	if (ret == par[node]) {
		vector <int> v;
		while (1) {
			int t = s.top();
			s.pop();
			mark[t] = 1;
			ID[t] = SCC.size();
			v.push_back(t);
			if (t == node) break;
		}
		SCC.push_back(v);
	}
	return ret;
}