#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M;
int degree[505];
int arr[505];
set <int> org[505];
queue <pii> cand;

void solve() {
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j) continue;
			org[i].insert(j);
		}
	}

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		degree[a]++;
		degree[b]++;
		org[min(a, b)].erase(max(a, b));
		org[max(a, b)].erase(min(a, b));
	}

	int l = 0, r = N * N;
	int ans = 0;
	while (l <= r) {
		int mid = (l + r) / 2;
		
		set <int> s[505];	

		for (int i = 1; i <= N; i++) {
			arr[i] = degree[i];
			for (auto j : org[i]) s[i].insert(j);
		}		

		set <pii> cand;
		for (int i = 1; i <= N; i++) {
			vector <int> v;
			for (auto j : s[i]) {
				if (arr[i] + arr[j] >= mid) {
					cand.insert({ i,j });
					v.push_back(j);
				}
			}
			for (int j : v) {
				s[i].erase(j);
				s[j].erase(i);
			}
		}

		while (cand.size() > 0) {
			pii now = *cand.begin();
			cand.erase(now);
			int a = now.first, b = now.second;
			arr[a]++; arr[b]++;

			vector <int> v, w;
			for (auto i : s[a]) {
				if (arr[a] + arr[i] >= mid) {					
					cand.insert({ a,i });
					v.push_back(i);
				}
			}

			for (int j : v) {
				s[a].erase(j);
				s[j].erase(a);
			}

			for (auto i : s[b]) {
				if (arr[b] + arr[i] >= mid) {					
					cand.insert({ b,i });
					w.push_back(i);
				}
			}

			for (int j : w) {
				s[b].erase(j);
				s[j].erase(b);
			}
		}

		int flag = 0;
		for (int i = 1; i <= N; i++) if (arr[i] != N - 1) flag = 1;

		if (flag == 0) {
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
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