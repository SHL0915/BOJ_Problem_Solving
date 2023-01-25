#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, a, b;

void solve() {
	cin >> N;
	cout << "? 1" << endl;
	cin >> a;
	cout << "? " << N << endl;
	cin >> b;
	if (a == 1 && b == 0)
		cout << "! -1" << endl;
	else if (a == 0 && b == 1)
		cout << "! 1" << endl;
	else
		cout << "! 0" << endl;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}