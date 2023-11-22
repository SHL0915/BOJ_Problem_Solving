#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, K;
vector <int> val;
pii v[2005];
vector <int> arr[2005], graph[4005], org[2005];
set <int> material[2005], cycle;
int parent[2005], person[2005];
int isCycle[2005], isCycle2[2005], A[2005], B[2005], mark[2005], mmark[2005];

void DDFS(int node) {
	if (mmark[node] == 1) {
		int now = node;
		cycle.insert(now);
		while (1) {
			now = org[now].front();
			if (now == node) break;
			cycle.insert(now);
		}		
		return;
	}
	mmark[node] = 1;
	for (int next : org[node]) {
		DDFS(next);
	}
	return;	
}

int DFS(int node) {
	mark[node] = 1;
	for (int next : graph[node]) {
		if (B[next] == -1) {
			A[node] = next;
			B[next] = node;
			return 1;
		}
	}

	for (int next : graph[node]) {
		if (mark[B[next]] == 0 && DFS(B[next])) {
			A[node] = next;
			B[next] = node;
			return 1;
		}
	}

	return 0;
}

int Bipartite_Matching() {
	int ret = 0;
	memset(A, -1, sizeof(A));
	memset(B, -1, sizeof(B));
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		if (isCycle2[i] == 0) {
			cnt++;
			if (A[i] == -1) {
				memset(mark, 0, sizeof(mark));
				ret += DFS(i);
			}
		}
	}
	if (ret != cnt) {
		cout << -1;
		exit(0);
	}
	for (int i = 1; i <= N; i++) {
		if (isCycle2[i] == 1) {
			if (A[i] == -1) {
				memset(mark, 0, sizeof(mark));
				ret += DFS(i);
			}
		}
	}

	if (ret < N - 1) {
		cout << -1;
		exit(0);
	}
	return ret;
}

int find(int a) {
	if (a == parent[a]) return parent[a];
	else return parent[a] = find(parent[a]);
}

void merge(int a, int b) {
	parent[find(a)] = find(b);
	return;
}

void solve() {
	cin >> N >> K;
	for (int i = 1; i <= N; i++) parent[i] = i;
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		int a; cin >> a;
		v[i] = { i, a };
		org[i].push_back(a);
		if (find(i) == find(a)) {
			cnt++;
		}
		merge(i, a);
		int k; cin >> k;
		for (int j = 0; j < k; j++) {
			int b; cin >> b;
			arr[i].push_back(b);
			val.push_back(b);
		}
	}

	if (cnt > 1) {
		cout << -1;
		return;
	}
	
	DDFS(1);	
	
	for (int i = 1; i <= N; i++) {
		if (cycle.count(i)) isCycle[i] = 1;
	}

	for (int i = 1; i <= K; i++) {
		cin >> person[i];
		val.push_back(person[i]);
	}

	sort(val.begin(), val.end());
	val.erase(unique(val.begin(), val.end()), val.end());

	for (int i = 1; i <= N; i++) {
		int a = v[i].first, b = v[i].second;
		for (int j : arr[i]) {
			int now = lower_bound(val.begin(), val.end(), j) - val.begin();
			material[i].insert(now);
		}
		if (isCycle[a] && isCycle[b]) isCycle2[i] = 1;
	}

	for (int i = 1; i <= K; i++) {
		int now = lower_bound(val.begin(), val.end(), person[i]) - val.begin();
		for (int j = 1; j <= N; j++) {
			if (material[j].count(now)) {
				graph[j].push_back(i);
			}
		}
	}

	Bipartite_Matching();

	for (int i = 1; i <= K; i++) {
		if (B[i] == -1) cout << 0 << " " << 0 << '\n';
		else cout << v[B[i]].first << " " << v[B[i]].second << " " << '\n';
	}

	return;
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}