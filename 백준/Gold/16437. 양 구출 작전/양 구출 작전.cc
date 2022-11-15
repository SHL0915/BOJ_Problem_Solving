#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
long long ans;
vector <int> tree[123457];
long long table[123457];
int mark[123457];

long long DFS(int node);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 2; i <= N; i++) {
		char t;
		long long a;
		int p;
		cin >> t >> a >> p;
		tree[i].push_back(p);
		tree[p].push_back(i);
		if (t == 'W') table[i] = -1 * a;
		else table[i] = a;
	}
	ans = DFS(1);
	cout << ans;
	return 0;
}

long long DFS(int node) {
	if (mark[node] != 0) return 0;
	mark[node] = 1;	
	for (int i = 0; i < tree[node].size(); i++) table[node] += DFS(tree[node][i]);	
	return max(0LL, table[node]);
}