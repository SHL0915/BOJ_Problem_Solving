#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, cnt, id;
vector <int> graph[55];
int in_degree[55];
int ans[55];
priority_queue <int> pq;

void Topology();

void solve() {
	cin >> N;
	cnt = N;
	for (int i = 1; i <= N; i++) {
		string S; cin >> S;
		for (int j = 0; j < S.length(); j++) {
			if (S[j] == '1') {
				graph[j + 1].push_back(i);
				in_degree[i] ++;
			}
		}
	}

	Topology();	

	for (int i = 1; i <= N; i++) cout << ans[i] << " ";

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

void Topology() {
	for (int i = 1; i <= N; i++) if (in_degree[i] == 0) pq.push(i);

	for (int i = 0; i < N; i++) {
		if (pq.size() == 0) {
			cout << -1;
			exit(0);
		}
		int now = pq.top(); pq.pop();

		ans[now] = cnt;
		cnt--;

		for (int next : graph[now]) if (--in_degree[next] == 0) pq.push(next);
	}

	return;
}