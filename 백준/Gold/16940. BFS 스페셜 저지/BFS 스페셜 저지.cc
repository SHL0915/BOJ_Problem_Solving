#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, cnt = 1;
vector <int> tree[100001];
int mark[100001];
int key[100001];
int arr[100001];
int ans[100001];
queue <int> q;

bool cmp(int a, int b);
void BFS();

void solve() {
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		key[arr[i]] = i;
	}
	for (int i = 1; i <= N; i++) sort(tree[i].begin(), tree[i].end(), cmp);
	q.push(1);
	while (q.size()) BFS();
	for (int i = 1; i <= N; i++) {
		if (arr[i] != ans[i]) {
			cout << 0;
			return;
		}
	}
	cout << 1;
	return;
}

int main(void) {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}

bool cmp(int a, int b) {
	return key[a] < key[b];
}

void BFS() {
	int node = q.front();
	q.pop();	
	if (mark[node]) return;
	mark[node] = 1;
	ans[cnt++] = node;
	for (int i = 0; i < tree[node].size(); i++) q.push(tree[node][i]);
	return;
}