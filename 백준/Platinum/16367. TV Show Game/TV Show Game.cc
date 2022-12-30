#include <bits/stdc++.h>
using namespace std;
const int MAX = 10005;

int K, N, cnt, sz;
vector <int> graph[MAX];
int par[MAX];
int ID[MAX];
int mark[MAX];
stack <int> s;

int convert(int node);
int DFS(int node);
bool cmp(int A, int B);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> K >> N;
	for (int i = 0; i < N; i++) {
		int nodes[3];
		for (int j = 0; j < 3; j++) {
			cin >> nodes[j];
			string str;
			cin >> str;
			if (str == "B") nodes[j] *= -1;
		}		
		for (int j = 0; j < 3; j++) {
			for (int k = j + 1; k < 3; k++) {
				graph[convert(-nodes[j])].push_back(convert(nodes[k]));
				graph[convert(-nodes[k])].push_back(convert(nodes[j]));
			}
		}
	}
	for (int i = 1; i <= 2 * K; i++) if (par[i] == 0) DFS(i);
	for (int i = 1; i <= K; i++) {
		if (ID[i * 2] == ID[i * 2 - 1]) {
			cout << -1;
			return 0;
		}
	}
	vector <int> nodes;
	int ans[MAX];
	memset(ans, -1, sizeof(ans));
	for (int i = 1; i <= 2 * K; i++) nodes.push_back(i);
	sort(nodes.begin(), nodes.end(), cmp);
	for (int i = 0; i < nodes.size(); i++) {
		int now = (nodes[i] + 1) / 2;
		if (ans[now] != -1) continue;
		ans[now] = !(nodes[i] % 2);
	}
	for (int i = 1; i <= K; i++) {
		if (ans[i]) cout << "R";
		else cout << "B";
	}
	return 0;
}

int convert(int node) {
	if (node < 0) return -node * 2;
	else return node * 2 - 1;
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
		sz++;
		while (1) {
			int t = s.top();
			s.pop();
			mark[t] = 1;
			ID[t] = sz;
			if (t == node) break;
		}
	}
	return ret;
}

bool cmp(int A, int B) {
	return ID[A] > ID[B];
}