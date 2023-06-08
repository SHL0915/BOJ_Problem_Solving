#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
int A[305], B[305];

void solve() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];
	for (int i = 0; i < N; i++) cin >> B[i];

	int a = 0, b = 0, type = 0, ans = 0;
	
	for (int i = 0; i < N; i++) {
		if (A[i] == 1) {
			if (B[i] == 1) {
				if (type == 0) {
					a++; b = 0;
					type = 1;
				}
				else {
					b++; a = 0;
					type = 0;
				}
			}
			else if (B[i] == 2) {
				b++; a = 0;
				type = 0;
			}
			else {
				a++; b = 0;
				type = 1;
			}
		}
		else if (A[i] == 2) {
			if (B[i] == 2) {
				if (type == 0) {
					a++; b = 0;
					type = 1;
				}
				else {
					b++; a = 0;
					type = 0;
				}
			}
			else if (B[i] == 3) {
				b++; a = 0;
				type = 0;
			}
			else {
				a++; b = 0;
				type = 1;
			}
		}
		else {
			if (B[i] == 3) {
				if (type == 0) {
					a++; b = 0;
					type = 1;
				}
				else {
					b++; a = 0;
					type = 0;
				}
			}
			else if (B[i] == 1) {
				b++; a = 0;
				type = 0;
			}
			else {
				a++; b = 0;
				type = 1;
			}
		}
		ans = max({ ans, a, b });
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