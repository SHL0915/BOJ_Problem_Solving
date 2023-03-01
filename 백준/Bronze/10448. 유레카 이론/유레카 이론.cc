#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
vector <int> cand;

void solve() {
	cin >> N;
	for (int i = 0; i < cand.size(); i++) {
		for (int j = i; j < cand.size(); j++) {
			for (int k = j; k < cand.size(); k++) {
				if (cand[i] + cand[j] + cand[k] == N) {
					cout << 1 << '\n';
					return;
				}
			}
		}
	}
	cout << 0 << '\n';
	return;
}

int main(void) {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int sum = 0;
	for (int i = 1; ; i++) {
		sum += i;
		if (sum > 1000) break;
		cand.push_back(sum);
	}
	
	int t = 1;
	cin >> t;
	while (t--) solve();
	return 0;
}