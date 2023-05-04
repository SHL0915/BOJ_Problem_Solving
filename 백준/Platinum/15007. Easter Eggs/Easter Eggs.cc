#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

int N, BB, RR;
vector <int> graph[255];
pii posA[255], posB[255];
int A[255], B[255], mark[255];

double dist(pii a, pii b);
int DFS(int node);
void init();

void solve() {
	cin >> N >> BB >> RR;
	for (int i = 0; i < BB; i++) cin >> posA[i].first >> posA[i].second;
	for (int i = 0; i < RR; i++) cin >> posB[i].first >> posB[i].second;

	double l = 0, r = 100000000;
	
	while (r - l > 0.000000001) {
		double mid = (l + r) / 2;
		init();
		for (int i = 0; i < BB; i++) {
			for (int j = 0; j < RR; j++) if (dist(posA[i], posB[j]) <= mid) graph[i].push_back(j);
		}

		int cnt = 0;
		for (int i = 0; i < BB; i++) {
			if (A[i] == -1) {
				memset(mark, 0, sizeof(mark));
				cnt += DFS(i);
			}
		}

		if (RR + BB - cnt < N) r = mid;
		else l = mid;
	}

	cout << (l + r) / 2;
	return;
}

int main(void) {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed;
	cout.precision(9);
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}

double dist(pii a, pii b) {
	ll dx = a.first - b.first;
	ll dy = a.second - b.second;
	return sqrt(dx * dx + dy * dy);
}

int DFS(int node) {
	mark[node] = 1;
	for (int i = 0; i < graph[node].size(); i++) {
		int next = graph[node][i];
		if (B[next] == -1 || mark[B[next]] == 0 && DFS(B[next])) {
			A[node] = next;
			B[next] = node;
			return 1;
		}
	}
	return 0;
}

void init() {
	for (int i = 0; i < N; i++) graph[i].clear();
	memset(A, -1, sizeof(A));
	memset(B, -1, sizeof(B));
}