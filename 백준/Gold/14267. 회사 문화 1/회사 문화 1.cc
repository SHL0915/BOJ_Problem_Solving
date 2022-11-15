#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector <int> tree[100001];
int table[100001];

void DFS(int node, int val);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		int A;
		cin >> A;
		if (i == 1) continue;
		else tree[A].push_back(i);
	}
	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;
		table[A] += B;
	}
	DFS(1, 0);
	for (int i = 1; i <= N; i++) cout << table[i] << ' ';
	return 0;
}

void DFS(int node, int val) {
	table[node] += val;
	for (int i = 0; i < tree[node].size(); i++) DFS(tree[node][i], table[node]);
	return;
}