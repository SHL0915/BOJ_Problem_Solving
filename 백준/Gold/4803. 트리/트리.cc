#include <iostream>
#include <vector>
using namespace std;

int T, N, M, flag;
vector <int> tree[500];
int mark[500];

void DFS(int node, int parent);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);	
	int caseNum = 1;
	while (1) {
		cin >> N >> M;
		if (N == 0 && M == 0) break;
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			tree[i].clear();
			mark[i] = 0;
		}
		for (int i = 0; i < M; i++) {
			int u, v;
			cin >> u >> v;
			tree[u - 1].push_back(v - 1);
			tree[v - 1].push_back(u - 1);
		}
		for (int i = 0; i < N; i++) {
			if (mark[i] == 0) {
				flag = 0;
				DFS(i, -1);
				if (flag == 0) cnt++;
			}
		}
		if (cnt == 0) cout << "Case " << caseNum << ": No trees.\n";
		else if (cnt == 1) cout << "Case " << caseNum << ": There is one tree.\n";
		else cout << "Case " << caseNum << ": A forest of " << cnt << " trees.\n";
		caseNum++;
	}
	return 0;
}

void DFS(int node, int parent) {
	if (mark[node] != 0) {
		flag = 1;
		return;
	}
	mark[node] = 1;
	for (int i = 0; i < tree[node].size(); i++) {
		if (tree[node][i] != parent) DFS(tree[node][i], node);
	}
	return;
}