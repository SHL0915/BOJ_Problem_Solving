#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

ll K, org;
string S;
string N, nS;
ll pow_2[61];

void solve() {
	cin >> K;
	cin >> S;

	org = K;

	while (K) {
		if (K % 2) N += '1';
		else N += '0';
		K /= 2;
	}

	if (S.length() < N.length()) {
		cout << 0;
		return;
	}

	int cnt = S.length() - N.length();
	int temp = cnt;

	nS = "1";
	for (int i = 1; i < S.length(); i++) {
		if (S[i] == '1') {
			if (temp) temp--;
			else nS += S[i];
		}
		else nS += S[i];
	}

	while (nS.size()) {
		if (temp == 0) break;
		nS.pop_back();
		temp--;
	}

	ll now = 0;
	for (int i = 0; i < nS.size(); i++) {
		now *= 2;
		now += nS[i] - '0';
	}


	if (now > org) cnt++;

	cout << cnt;	
	return;
}

int main(void) {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	pow_2[0] = 1;
	for (int i = 1; i <= 60; i++) pow_2[i] = pow_2[i - 1] * 2;
	//cin >> t;
	while (t--) solve();
	return 0;
}