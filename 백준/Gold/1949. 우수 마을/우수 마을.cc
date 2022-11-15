#include <iostream>
#include <vector>
using namespace std;

int N;
vector <int> tree[10001];
int people[10001];
int table[10001][2];

void DFS(int node, int parent);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> people[i];
	for (int i = 0; i < N - 1; i++) {
		int A, B;
		cin >> A >> B;
		tree[A].push_back(B);
		tree[B].push_back(A);
	}	
	DFS(1, 1);
	cout << max(table[1][0], table[1][1]);
	return 0;
}

void DFS(int node, int parent) {
	table[node][0] = 0;
	table[node][1] = people[node];
	for (int i = 0; i < tree[node].size(); i++) {
		if (tree[node][i] != parent) {
			DFS(tree[node][i], node);
			table[node][1] += table[tree[node][i]][0];
			table[node][0] += max(table[tree[node][i]][0], table[tree[node][i]][1]);
		}
	}
}