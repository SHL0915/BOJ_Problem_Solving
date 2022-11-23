#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;

int N, cnt, ans;
vector <int> tree[10001];
vector <int> depth[10001];
int width[10001];
int parent[10001];

void Traverse(int node, int d);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int A, B, C;
		cin >> A >> B >> C;
		tree[A].push_back(B);
		tree[A].push_back(C);
		if (B != -1) parent[B] = A;
		if (C != -1) parent[C] = A;
	}
	int root;
	for (int i = 1; i <= N; i++) if (parent[i] == 0) root = i;
	Traverse(root, 1);
	for (int i = 1; i <= N; i++) {
		int max_w = 0;
		int min_w = INF;
		for (int j = 0; j < depth[i].size(); j++) {
			max_w = max(max_w, width[depth[i][j]]);
			min_w = min(min_w, width[depth[i][j]]);
		}
		ans = max(ans, max_w - min_w + 1);
	}
	for (int i = 1; i <= N; i++) {
		int max_w = 0;
		int min_w = INF;
		for (int j = 0; j < depth[i].size(); j++) {
			max_w = max(max_w, width[depth[i][j]]);
			min_w = min(min_w, width[depth[i][j]]);
		}
		if (max_w - min_w + 1 == ans) {
			cout << i << " " << ans;
			return 0;
		}
	}
	return 0;
}

void Traverse(int node, int d) {
	depth[d].push_back(node);
	if (tree[node][0] == -1 && tree[node][1] == -1) {
		cnt++;
		width[node] = cnt;
	}
	else if (tree[node][0] == -1) {
		cnt++;
		width[node] = cnt;
		Traverse(tree[node][1], d + 1);
	}
	else if (tree[node][1] == -1) {
		Traverse(tree[node][0], d + 1);
		cnt++;
		width[node] = cnt;
	}
	else {
		Traverse(tree[node][0], d + 1);
		cnt++;
		width[node] = cnt;
		Traverse(tree[node][1], d + 1);
	}
}