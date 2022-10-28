#include <iostream>
#include <vector>
using namespace std;

int N, cnt;
vector <int> tree[500000];
int mark[500000];

void DFS(int node, int parent, int depth);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		tree[a - 1].push_back(b - 1);
		tree[b - 1].push_back(a - 1);
	}
	DFS(0, 0, 0);
	if (cnt % 2 == 1) cout << "Yes";
	else cout << "No";
	return 0;
}

void DFS(int node, int parent, int depth) {
	if (mark[node] != 0) return;
	int temp = 0;
	mark[node] = 0;
	for (int i = 0; i < tree[node].size(); i++) {
		if (tree[node][i] != parent) {
			temp++;
			DFS(tree[node][i], node, depth + 1);
		}
	}
	if (temp == 0) cnt += depth;
	return;
}