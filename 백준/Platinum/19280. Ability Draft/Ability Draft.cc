#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;

int N, S, Ps, Pu, SZ;
int arr[45], cnt[45];
int mark[10];
ll skill[35];
ll ult[15];
ll table[45][(1 << 10)];

ll DP(int now, int state);

void solve() {
	cin >> N >> S;
	SZ = 2 * N * (S + 1);

	for (int i = 0; i < SZ; i++) {
		cin >> arr[i];
		arr[i]--;
		mark[arr[i]]++;
		cnt[i] = mark[arr[i]];
	}

	cin >> Ps;
	for (int i = 0; i < Ps; i++) cin >> skill[i];
	sort(skill, skill + Ps, greater<>());
	cin >> Pu;
	for (int i = 0; i < Pu; i++) cin >> ult[i];
	sort(ult, ult + Pu, greater<>());

	memset(table, INF, sizeof(table));
	cout << DP(0, 0);
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

ll DP(int now, int state) {
	if (now == SZ) return 0;

	ll& ret = table[now][state];
	if (ret != INF) return ret;

	int type;
	if (arr[now] < N) type = 0;
	else type = 1;

	int now_s = 0, now_u = 0;

	for (int i = 0; i < 2 * N; i++) {
		if (state & (1 << i)) now_u++;
	}

	now_s = now - now_u;

	if (type == 0) {
		ret = -INF;

		if (state & (1 << arr[now])) ret = max(ret, skill[now_s] + DP(now + 1, state));
		else {
			if (cnt[now] != S + 1) ret = max(ret, skill[now_s] + DP(now + 1, state));
			ret = max(ret, ult[now_u] + DP(now + 1, state | (1 << arr[now])));
		}
	}
	else {
		ret = INF;
		
		if (state & (1 << arr[now])) ret = min(ret, -skill[now_s] + DP(now + 1, state));
		else {
			if (cnt[now] != S + 1) ret = min(ret, -skill[now_s] + DP(now + 1, state));
			ret = min(ret, -ult[now_u] + DP(now + 1, state | (1 << arr[now])));
		}
	}
	
	return ret;
}