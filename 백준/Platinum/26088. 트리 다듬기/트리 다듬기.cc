#include <bits/stdc++.h>
using namespace std;

int N, K;
vector <int> tree[100001];
priority_queue <int> pq;

pair<int, int> DFS(int node, int par);

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
	int root = DFS(1, 0).second;
	while (pq.size()) pq.pop();
	int len = DFS(root, -1).first - 1;
	for (int i = 0; i < K; i++) {
		if (pq.size() == 0) break;
		len += pq.top();
		pq.pop();
	}
	cout << len;	
	return 0;
}

pair<int, int> DFS(int node, int par) {
	vector <pair<int, int>> sub;
	for (int i = 0; i < tree[node].size(); i++) {
		int next = tree[node][i];
		if (next == par) continue;
		sub.push_back(DFS(next, node));
	}
	if (sub.size() == 0) return { 1,node };
	sort(sub.begin(), sub.end());
	for (int i = 0; i < sub.size() - 1; i++) pq.push(sub[i].first);
	sub.back().first++;
	return sub.back();
}