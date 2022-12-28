#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;

int N, M;
pair<ll, ll> arr[1001];
ll psum[1001];
ll table[1001][1001][2];

ll DP(int start, int end, int pos);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i].first >> arr[i].second;
		psum[i] = psum[i - 1] + arr[i].second;
	}
	memset(table, -1, sizeof(table));
	cout << DP(M, M, 0);
	return 0;
}

ll DP(int start, int end, int pos) {
	if (start == 1 && end == N) return 0;
	ll& ret = table[start][end][pos];
	if (ret != -1) return ret;
	ret = INF;
	ll cost = psum[start - 1] + psum[N] - psum[end];
	ll now;
	if (pos) now = arr[end].first;
	else now = arr[start].first;
	if (start > 1) ret = min(ret, DP(start - 1, end, 0) + cost * (now - arr[start - 1].first));
	if (end < N) ret = min(ret, DP(start, end + 1, 1) + cost * (arr[end + 1].first - now));
	return ret;
}