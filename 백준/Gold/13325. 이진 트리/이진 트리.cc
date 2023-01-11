#include <bits/stdc++.h>
using namespace std;

int k;
long long ans;
long long pow_2[22];
long long tree[10000000];
long long sum[10000000];
long long path[10000000];

long long DFS(int node);
void add(int node);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	pow_2[0] = 1;
	for (int i = 1; i <= 21; i++) pow_2[i] = pow_2[i - 1] * 2;
	cin >> k;
	for (int i = 2; i <= pow_2[k + 1] - 1; i++) cin >> tree[i];
	DFS(1);
	add(1);
	for (int i = 2; i <= pow_2[k + 1] - 1; i++) ans += tree[i];
	cout << ans;
	return 0;
}

long long DFS(int node) {
	if (node >= pow_2[k + 1]) return 0;	
	path[node] = max(DFS(node * 2) + tree[node * 2], DFS(node * 2 + 1) + tree[node * 2 + 1]);
	return path[node];
}

void add(int node) {
	if (node * 2 >= pow_2[k + 1]) return;
	tree[node * 2] = path[node] - path[node * 2];
	tree[node * 2 + 1] = path[node] - path[node * 2 + 1];
	add(node * 2);
	add(node * 2 + 1);
	return;
}