#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, K, cnt;
map <string, int> convert;
map <int, string> rev;
map <pii, int> edge;
vector <int> graph[500005], ans;
int in_degree[500005], out_degree[500005], BT[10], mark[10];

void BackTracking(int k);
void DFS(int node);

void solve() {
	cin >> N >> K;
	K--;
	BackTracking(0);

	for (int i = 1; i <= cnt; i++) {
		string now = rev[i];
		string next = "";
		memset(mark, 0, sizeof(mark));
		mark[now[0] - 'A'] = 1;
		for (int j = 1; j < now.size(); j++) {
			next += now[j];
			mark[now[j] - 'A'] = 1;
		}
		for (int j = 0; j < N; j++) {
			if (mark[j] == 0) {
				next += ('A' + j);
				graph[i].push_back(convert[next]);
				out_degree[i]++;
				in_degree[convert[next]]++;
				next.pop_back();
			}
		}
	}

	for (int i = 1; i <= cnt; i++) {
		if (in_degree[i] != out_degree[i]) {
			cout << "NO";
			return;
		}
	}
	DFS(1);

	int fact = 1;
	for (int i = N - K; i <= N; i++) fact *= i;

	if (ans.size() != fact + 1) {
		cout << "NO";
		return;
	}

	cout << "YES\n";

	for (int i = ans.size() - 1; i >= 1; i--) {
		string now = rev[ans[i]];
		string next = rev[ans[i - 1]];
		string res = now;
		for (int j = K - 1; j < next.length(); j++) res += next[j];
		cout << res << " ";
	}

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

void BackTracking(int k) {
	if (k == K) {
		string now = "";
		for (int i = 0; i < k; i++) now += ('A' + BT[i]);
		if (convert[now] == 0) {
			convert[now] = ++cnt;
			rev[cnt] = now;
		}
		return;
	}
	else {
		for (int i = 0; i < N; i++) {
			if (mark[i]) continue;
			mark[i] = 1;
			BT[k] = i;
			BackTracking(k + 1);
			mark[i] = 0;
		}
	}
}

void DFS(int node) {
	while (graph[node].size()) {
		int next = graph[node].back();
		graph[node].pop_back();
		DFS(next);
	}

	ans.push_back(node);
	return;
}