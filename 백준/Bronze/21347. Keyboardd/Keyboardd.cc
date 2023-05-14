#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

string A, B;

void solve() {
	getline(cin, A);
	getline(cin, B);
	A += ' ';
	B += ' ';

	vector <char> ans;

	for (int i = 1, j = 1; j < B.length(); i++, j++) {
		if (B[j] == B[j - 1]) {
			if (B[j] != A[i]) {
				ans.push_back(B[j]);
				i--;
			}	
		}
	}

	sort(ans.begin(), ans.end());
	ans.erase(unique(ans.begin(), ans.end()), ans.end());

	for (int i = 0; i < ans.size(); i++) cout << ans[i];
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