#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, K, max_lev;
vector <int> tree[10001];
int table[10001];
int par[10001];
vector <int> level[10001];

void DFS(int node, int parent, int lev);

bool cmp(int A, int B) {
	return table[A] > table[B];
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> K;
	for (int i = 0; i < N - 1; i++) {
		int A, B;
		cin >> A >> B;
		tree[A].push_back(B);
		tree[B].push_back(A);
	}
	DFS(1, -1, 0);
	for (int i = max_lev; i > 0; i--) {
		if (level[i].size() > K) {
			sort(level[i].begin(), level[i].end(), cmp);
			while (level[i].size() > K) {
				int temp = level[i].back();
				while (1) {
					if (temp == -1) break;
					table[par[temp]] -= table[level[i].back()];
					temp = par[temp];
				}
				level[i].pop_back();
			}
		}
	}
	cout << table[1];
	return 0;
}

void DFS(int node, int parent, int lev) {
	if (table[node] != 0) return;
	table[node] = 1;
	max_lev = max(max_lev, lev);
	par[node] = parent;
	level[lev].push_back(node);
	for (int i = 0; i < tree[node].size(); i++) {
		if (tree[node][i] != parent) {
			DFS(tree[node][i], node, lev + 1);
			table[node] += table[tree[node][i]];
		}
	}
	return;
}