#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

int N, in;
int mark[105];
pii arr[105];

void solve() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i].first >> arr[i].second;
	int cnt = 0;
	if (N % 2) {
		cout << "Beatrice" << endl;
		cin >> in;
		mark[in - 1] = 1;
		cnt++;
	}
	else cout << "Alberto" << endl;

	while (cnt < N - 2) {
		vector <pii> v;
		for (int i = 0; i < N; i++) {
			if (mark[i]) continue;
			int now = i;
			int nxt, prv;
			for (int j = i + 1; ; j = (j + 1) % N) {
				if (mark[j]) continue;
				else {
					nxt = j;
					break;
				}
			}

			for (int j = (i - 1 + N) % N; ; j = (j - 1 + N) % N) {
				if (mark[j]) continue;
				else {
					prv = j;
					break;
				}
			}

			vector <pii> d;
			d.push_back(arr[prv]);
			d.push_back(arr[now]);
			d.push_back(arr[nxt]);

			ll val = 0;
			for (int j = 0; j < 3; j++) {
				pii n = d[j], nx = d[(j + 1) % 3];
				val += (n.first * nx.second - n.second * nx.first);
			}

			val = abs(val);
			v.push_back({ val, now });
		}

		sort(v.begin(), v.end());
		cout << v[0].second + 1 << endl;
		mark[v[0].second] = 1;
		cnt++;

		cin >> in;
		mark[in - 1] = 1;
		cnt++;
	}

	return;
};

int main() {
#ifndef ONLINE_JUDGE
	//freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}
