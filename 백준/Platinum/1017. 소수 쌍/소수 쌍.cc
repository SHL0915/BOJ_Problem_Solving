#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, a_cnt, b_cnt;
int table[5001], arr[55], aa[55], bb[55];
vector <int> graph[55], cand, ans;
int A[55], B[55], mark[55];

int DFS(int node);

void solve() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		if (arr[i] % 2) aa[a_cnt++] = arr[i];
		else bb[b_cnt++] = arr[i];
	}
	if (arr[0] % 2) {
		swap(aa, bb);
		swap(a_cnt, b_cnt);
	}
	if (a_cnt != b_cnt) {
		cout << -1;
		return;
	}
	for (int i = 0; i < a_cnt; i++) {
		if (table[arr[0] + aa[i]] == 0) cand.push_back(i);
	}

	for (int i = 1; i < b_cnt; i++) {
		for (int j = 0; j < a_cnt; j++) {
			if (table[bb[i] + aa[j]] == 0) graph[i].push_back(j);
		}
	}	

	for (int i = 0; i < cand.size(); i++) {
		int cnt = 1;
		memset(A, -1, sizeof(A));
		memset(B, -1, sizeof(B));	
		A[0] = cand[i];
		B[cand[i]] = 0;
		for (int j = 1; j < b_cnt; j++) {
			if (A[j] == -1) {
				memset(mark, 0, sizeof(mark));
				cnt += DFS(j);
			}
		}
		if (cnt == N / 2) ans.push_back(aa[cand[i]]);
	}
	sort(ans.begin(), ans.end());
	if (ans.size() == 0) cout << -1;
	else {
		for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
	}
	return;
}

int main(void) {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 2; i <= 5000; i++) {
		if (table[i] == 0) {
			for (int j = i * i; j <= 5000; j += i) table[j] = 1;
		}
	}
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}

int DFS(int node) {
	mark[node] = 1;
	for (int i = 0; i < graph[node].size(); i++) {
		int now = graph[node][i];
		if (B[now] == -1 || mark[B[now]] == 0 && DFS(B[now])) {
			B[now] = node;
			A[node] = now;
			return 1;
		}
	}
	return 0;
}