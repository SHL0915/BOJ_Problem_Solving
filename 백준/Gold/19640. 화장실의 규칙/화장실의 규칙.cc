#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M, K;
int D[100001];
int H[100001];
deque <int> arr[100001];

struct cmp {
	bool operator() (int a, int b) {
		if (D[a] == D[b]) {
			if (H[a] == H[b]) {
				return (a % M > b % M);
			}
			return H[a] < H[b];
		}
		return D[a] < D[b];
	}
};

void solve() {
	cin >> N >> M >> K;
	int cnt = 0;
	priority_queue <int, vector<int>, cmp> pq;
	for (int i = 0; i < N; i++) cin >> D[i] >> H[i];
	for (int i = 0; i < N; i++) arr[i % M].push_back(i);
	for (int i = 0; i < M; i++) {
		if (arr[i].size()) {
			pq.push(arr[i].front());
			arr[i].pop_front();
		}
	}
	while (pq.size()) {
		cnt++;
		int t = pq.top();
		pq.pop();
		if (t == K) {
			cout << cnt - 1;
			return;
		}
		if (arr[t % M].size()) {
			pq.push(arr[t % M].front());
			arr[t % M].pop_front();
		}
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