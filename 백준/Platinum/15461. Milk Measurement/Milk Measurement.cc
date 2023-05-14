#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, G;
map <int, int> cow;
map <int, int> num;

void solve() {
	cin >> N >> G;
	vector <pair<int, pii>> Q;

	for (int i = 0; i < N; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		Q.push_back({ a,{b,c} });
	}

	sort(Q.begin(), Q.end());
	num[G] = 1000000000;

	int m = G, ans = 0;

	priority_queue <int> pq;
	pq.push(G);

	for (int i = 0; i < N; i++) {
		int id = Q[i].second.first;
		int delt = Q[i].second.second;
		int flag = 0;

		if (cow.count(id) == 0) cow[id] = G;
		int val = cow[id];

		if (val == m) {
			if (num[val] >= 2) {
				flag = 1;
				num[val]--;
				int nval = val + delt;
				num[nval]++;
				cow[id] = nval;
				m = max(m, nval);
				pq.push(nval);
			}
			else {
				num[val]--;
				int nval = val + delt;
				cow[id] = nval;

				int vs;
				while (pq.size()) {
					int t = pq.top(); pq.pop();
					if (num[t] == 0) continue;
					else {
						vs = t;
						pq.push(t);
						break;
					}
				}

				if (nval <= vs) flag++;
				num[nval]++;
				m = max(nval, vs);
				pq.push(nval);
			}

		}
		else {
			num[val]--;
			int nval = val + delt;
			if (nval >= m) flag = 1;
			num[nval] ++;
			cow[id] = nval;
			m = max(m, nval);
			pq.push(nval);
		}		
		ans += flag;
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