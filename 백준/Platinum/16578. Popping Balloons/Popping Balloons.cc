#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

ll N, M;
ll A[100005], B[100005];
ll psumA[100005], psumB[100005];
ll cnt[100005];

void solve() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
		psumA[i] = psumA[i - 1] + A[i];
	}

	for (int i = 1; i <= N; i++) {
		cin >> B[i];
		psumB[i] = psumB[i - 1] + B[i];
	}

	ll idx = upper_bound(psumA, psumA + N + 1, M) - psumA - 1;

	if (idx == 0) {
		cout << -1;
		return;
	}

	set <pii> s;
	for (int i = 1; i <= idx; i++) s.insert({ B[i], i });

	ll now = 0, delay = 0, ptr = 1, k = 0;
	
	for (int i = 1; i <= idx; i++) {
		if (now < psumA[i]) now = psumA[i];
		k++;

		ll bidx = lower_bound(psumB, psumB + N + 1, now - delay) - psumB - 1;

		if (bidx >= idx) {
			cout << -1;
			return;
		}

		for (ptr; ptr <= bidx; ptr++) s.erase({ B[ptr], ptr });

		while (k > 0) {
			pii greedy = (*s.rbegin());
			now += greedy.first;
			delay += greedy.first;
			cnt[greedy.second]++;
			k--;
		}
	}

	now = 0;
	vector <ll> ans;
	for (int i = 1; i <= idx; i++) {
		if (now > M) break;
		now += B[i];
		while (cnt[i] > 0) {
			if (now > M) break;
			ans.push_back(now);
			now += B[i];
			cnt[i]--;
		}
	}

	if (now <= M) {
		cout << -1;
		return;
	}

	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";

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