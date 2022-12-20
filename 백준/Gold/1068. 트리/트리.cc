#include <bits/stdc++.h>
using namespace std;

int N, root, del, cnt;
vector <int> graph[50];

void DFS(int node);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int A;
		cin >> A;
		if (A == -1) root = i;
		else graph[A].push_back(i);		
	}
	cin >> del;
	if (root == del) {
		cout << 0;
		return 0;
	}
	DFS(root);
	cout << cnt;
	return 0;
}

void DFS(int node) {
	int temp = 0;
	for (int i = 0; i < graph[node].size(); i++) {
		if (graph[node][i] != del) {
			DFS(graph[node][i]);
			temp++;
		}
	}
	if (temp == 0) cnt++;
	return;
}