#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, now;
int arr[300005], mark[300005], ptr[300005], ans[300005];
vector <int> val[300005];
pii seg[600005];
priority_queue <pii, vector<pii>, greater<>> pq;

void update(int pos, pii val);
pii query(int l, int r);

void solve() {
	cin >> N;
	int M = 0;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		val[arr[i]].push_back(i);
	}

	for (int i = 1; i <= N; i++) {
		if (val[i].size() == ptr[i]) continue;
		pq.push({ val[i][ptr[i]], i});
		update(i, { val[i].size() , i });
	}

	for (int i = 0; i < N; i++) {
		pii M = query(1, N + 1);
		if (M.first > (N - i + 1) / 2) {
			cout << -1;
			return;
		}

		if ((N - i) % 2 && M.first == (N - i + 1) / 2) {
			ans[i] = val[M.second][ptr[M.second]];
			ptr[M.second]++;
			if (ptr[M.second] != val[M.second].size()) pq.push({ val[M.second][ptr[M.second]], M.second });
			update(M.second, { val[M.second].size() - ptr[M.second] , M.second });			
		}
		else {
			pii t;
			while (pq.size()) {
				t = pq.top(); pq.pop();
				if (mark[t.first] == 0) break;
			}

			if (t.second != now) {
				ans[i] = t.first;
				ptr[t.second]++;
				if (ptr[t.second] != val[t.second].size()) pq.push({ val[t.second][ptr[t.second]], t.second });
				update(t.second, { val[t.second].size() - ptr[t.second] , t.second });
			}
			else {
				pii next;
				while (pq.size()) {
					next = pq.top(); pq.pop();
					if (mark[next.first] == 0) break;
				}
				ans[i] = next.first;
				ptr[next.second]++;
				if (ptr[next.second] != val[next.second].size()) pq.push({ val[next.second][ptr[next.second]], next.second });
				update(next.second, { val[next.second].size() - ptr[next.second] , next.second });
				pq.push(t);
			}
		}

		mark[ans[i]] = 1;
		now = arr[ans[i]];
	}

	for (int i = 0; i < N; i++) cout << ans[i] << " ";
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

void update(int pos, pii val) {
	for (seg[pos += N] = val; pos > 0; pos >>= 1) seg[pos >> 1] = max(seg[pos], seg[pos ^ 1]);
	return;
}

pii query(int l, int r) {
	pii ret = { -1, -1 };
	for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
		if (l & 1) ret = max(ret, seg[l++]);
		if (r & 1) ret = max(ret, seg[--r]);
	}

	return ret;
}