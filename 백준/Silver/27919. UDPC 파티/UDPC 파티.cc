#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

string V;

void solve() {
	cin >> V;
	int a = 0, b = 0;
	for (int i = 0; i < V.length(); i++) {
		if (V[i] == 'U' || V[i] == 'C') a++;
		else b++;
	}

	int flag = 0;
	if (a > b - (a - 1)) {
		cout << "U";
		flag = 1;
	}

	if (b) {
		cout << "DP";
		flag = 1;
	}

	if (flag == 0) cout << "C";
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