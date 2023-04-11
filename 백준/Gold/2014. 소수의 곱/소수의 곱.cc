#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, K;
ll arr[101];
set <ll> ans;

void solve() {
	cin >> K >> N;
	for (int i = 0; i < K; i++) cin >> arr[i];

	ans.insert(1);

	for (int i = 0; i < N; i++) {
		ll now = *(ans.begin());
		ans.erase(now);
		for (int j = 0; j < K; j++) {
			ll next = now * arr[j];
			if (next > (1LL << 31)) break;
			if (ans.size() < N) ans.insert(next);
			else {
				if (next >= *(ans.rbegin())) break;
				else {
					ans.insert(next);
					ans.erase(*(ans.rbegin()));
				}
			}
		}
	}
		
	cout << *(ans.begin());
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