#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

ll N, SZ;
int A[200005], B[200005], C[200005];
int arr[200005];
vector <int> bucket[505];

void solve() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int a; cin >> a;
		A[a] = i;
	}

	for (int i = 1; i <= N; i++) {
		int a; cin >> a;
		B[A[a]] = i;
	}

	for (int i = 0; i <= N; i++) arr[i] = N;
	while (SZ * SZ <= N) SZ++;

	ll ans = 0;

	for (int i = 1; i <= N; i++) {
		ll a; cin >> a;
		// 구간 쿼리 l = 1, r = A[a];
		ll val = B[A[a]];
		// 세그 쿼리 l = 1, r = val;

		ll idx = 0, bidx = 0;
		while (1) {
			if (idx + SZ >= A[a]) break;

			int qidx = lower_bound(bucket[bidx].begin(), bucket[bidx].end(), val) - bucket[bidx].begin();

			if(qidx) ans += qidx;

			idx += SZ;
			bidx++;
		}
		
		for (int j = idx; j <= A[a]; j++) if (arr[j] < val) ans++;
		
		arr[A[a]] = val;
		bucket[A[a] / SZ].push_back(val);
		sort(bucket[A[a] / SZ].begin(), bucket[A[a] / SZ].end());
	}

	cout << ans;
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