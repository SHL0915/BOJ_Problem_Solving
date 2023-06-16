#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M;
int adj[1005][1005];
int table[1005][1005];
set <int> cand;
vector <int> A, B, Acand, Bcand;
vector <pii> arr;

void solve() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		adj[a][b] = 1;
		adj[b][a] = 1;
	}

	for (int i = 1; i <= N; i++) cand.insert(i);

	while (cand.size()) {
		A.clear();
		B.clear();
		int a = *cand.begin();
		cand.erase(a);
		Acand.push_back(a);

		while (Acand.size()) {
			while (Acand.size()) {
				int b = Acand.back(); Acand.pop_back();
				for (int i = 0; i < A.size(); i++) {
					if (adj[A[i]][b] == 0) {
						cout << -1;
						return;
					}
				}
				A.push_back(b);

				vector <int> v;
				for (auto i : cand) if (adj[b][i] == 0) v.push_back(i);

				for (int i = 0; i < v.size(); i++) {
					cand.erase(v[i]);
					Bcand.push_back(v[i]);
				}
			}

			while (Bcand.size()) {
				int b = Bcand.back(); Bcand.pop_back();
				for (int i = 0; i < B.size(); i++) {
					if (adj[B[i]][b] == 0) {
						cout << -1;
						return;
					}
				}
				B.push_back(b);

				vector <int> v;
				for (auto i : cand) if (adj[b][i] == 0) v.push_back(i);

				for (int i = 0; i < v.size(); i++) {
					cand.erase(v[i]);
					Acand.push_back(v[i]);
				}
			}
		}

		arr.push_back({ A.size(), B.size() });
	}

	table[0][0] = 1;
	
	for (int i = 1; i <= arr.size(); i++) {
		for (int j = 0; j <= N; j++) {
			if (table[i - 1][j] == 0) continue;
			table[i][j + arr[i - 1].first] = 1;
			table[i][j + arr[i - 1].second] = 1;
		}
	}

	int ans = 0x3f3f3f3f;
	for (int i = 0; i <= N; i++) {
		if (table[arr.size()][i] == 1) ans = min(ans, abs(i - (N - i)));
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