#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

ll N, M, L;
vector <int> graph[200001];
int in_degree[200001];
int id[200001];
int mark[200001];
queue <int> q;

void solve() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		vector <int> recipe;
		int k; cin >> k;
		for (int j = 0; j < k; j++) {
			int a; cin >> a;
			recipe.push_back(a);
		}
		int r; cin >> r;
		id[i] = r;
		for (int j = 0; j < k; j++) {
			graph[recipe[j]].push_back(i);
			in_degree[i]++;
		}
	}
	cin >> L;
	for (int i = 0; i < L; i++) {
		int a; cin >> a;
		q.push(a);
	}
	vector <int> ans;
	while (q.size()) {
		int now = q.front();
		q.pop();
		if (mark[now]) continue;
		mark[now] = 1;
		ans.push_back(now);
		for (int i = 0; i < graph[now].size(); i++) {
			if (--in_degree[graph[now][i]] == 0) q.push(id[graph[now][i]]);
		}
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
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