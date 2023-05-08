#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M, cnt, id_cnt;
int arr[100005];
vector <int> room[100005];
vector <int> graph[200005];
int par[200005], id[200005];
stack <int> st;

int convert(int a);
int DFS(int node);

void solve() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) cin >> arr[i];
	for (int i = 1; i <= M; i++) {
		int K; cin >> K;
		for (int j = 0; j < K; j++) {
			int a; cin >> a;
			room[a].push_back(i);
		}
	}

	for (int i = 1; i <= N; i++) {
		int a = room[i][0], b = room[i][1];
		if (arr[i] == 0) {
			graph[convert(a)].push_back(convert(-b));
			graph[convert(b)].push_back(convert(-a));

			graph[convert(-a)].push_back(convert(b));
			graph[convert(-b)].push_back(convert(a));
		}
		else {
			graph[convert(a)].push_back(convert(b));
			graph[convert(b)].push_back(convert(a));

			graph[convert(-a)].push_back(convert(-b));
			graph[convert(-b)].push_back(convert(-a));
		}
	}

	for (int i = 1; i <= 2 * M; i++) {
		if (par[i] == 0) DFS(i);
	}

	for (int i = 1; i <= M; i++) {
		if (id[convert(i)] == id[convert(-i)]) {
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

int convert(int a) {
	if (a > 0) return a * 2 - 1;
	else return -a * 2;
}

int DFS(int node) {
	par[node] = ++cnt;
	int ret = cnt;
	st.push(node);

	for (int i = 0; i < graph[node].size(); i++) {
		int next = graph[node][i];
		if (par[next] == 0) ret = min(ret, DFS(next));
		else if (id[next] == 0) ret = min(ret, par[next]);
	}

	if (ret == par[node]) {
		id_cnt++;
		while (1) {
			int t = st.top(); st.pop();
			id[t] = id_cnt;
			if (t == node) break;
		}
	}

	return ret;
}