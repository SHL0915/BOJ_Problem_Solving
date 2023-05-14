#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<char, char>;

int N, M;
string A[505], B[505];

void solve() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> A[i];
	for (int i = 0; i < N; i++) cin >> B[i];

	int ans = 0;

	for (int i = 0; i < M; i++) {
		for (int j = i + 1; j < M; j++) {
			for (int k = j + 1; k < M; k++) {
				set <pair <pii, char>> s;
				int flag = 0;
				for (int l = 0; l < N; l++) s.insert({ {A[l][i], A[l][j]},A[l][k] });
				for (int l = 0; l < N; l++) {
					if (s.count({ {B[l][i],B[l][j]}, B[l][k] })) flag = 1;
				}

				if (flag == 0) ans++;
			}
		}
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