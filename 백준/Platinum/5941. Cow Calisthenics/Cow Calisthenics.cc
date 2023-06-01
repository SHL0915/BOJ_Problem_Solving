#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, S, cnt;
vector <int> tree[100005];

bool check(int len);
int DFS(int node, int par, int len);

void solve() {
	cin >> N >> S;
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	int l = 0, r = N;
	int ans = 0;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (check(mid)) {
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}

	cout << ans;
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

bool check(int len) {
	cnt = 0;
	DFS(1, 0, len);
	if (cnt <= S) return true;
	else return false;

}

int DFS(int node, int par, int len) {
	priority_queue <int> pq;
	pq.push(0);

	for (int next : tree[node]) {
		if (next == par) continue;
		pq.push(DFS(next, node, len) + 1);
	}

	while (pq.size() >= 2) {
		int a = pq.top(); pq.pop();
		int b = pq.top();
		if (a + b > len) cnt++;
		else {
			pq.push(a);
			break;
		}
	}

	return pq.top();
}