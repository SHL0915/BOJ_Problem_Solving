#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

double tot, cnt;

void solve() {
	for (int i = 0; i < 20; i++) {
		string s; double d; string score;
		cin >> s >> d >> score;
		if (score == "P") continue;
		cnt += d;
		double convert;
		if (score == "A+") convert = 4.5;
		else if (score == "A0") convert = 4.0;
		else if (score == "B+") convert = 3.5;
		else if (score == "B0") convert = 3.0;
		else if (score == "C+") convert = 2.5;
		else if (score == "C0") convert = 2.0;
		else if (score == "D+") convert = 1.5;
		else if (score == "D0") convert = 1.0;
		else if (score == "F") convert = 0;
		tot += (d * convert);
	}
	cout << tot / cnt;
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