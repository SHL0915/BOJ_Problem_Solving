#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
string target;
string S;
int pi[1000001];
vector <int> ans;

void makePi(string s);
void kmp(string a, string b);
int GCD(int a, int b);

void solve() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		char c; cin >> c;
		target += c;
	}

	for (int i = 0; i < N; i++) {
		char c; cin >> c;
		S += c;
	}
	S = S + S;

	makePi(target);
	kmp(S, target);

	int cnt = 0;
	for (int i = 0; i < ans.size(); i++) if (ans[i] < N) cnt++;

	cout << cnt / GCD(N, cnt) << '/' << N / GCD(N, cnt);
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

void makePi(string s) {
	int n = s.length(), pos = 1, k = 0;
	while (pos + k < n) {
		if (s[pos + k] == s[k]) {
			k++;
			pi[pos + k - 1] = k;
		}
		else {
			if (k == 0) pos++;
			else {
				pos += k - pi[k - 1];
				k = pi[k - 1];
			}
		}
	}
	return;
}

void kmp(string a, string b) {
	int n = a.length(), m = b.length(), pos = 0, k = 0;
	while (pos + m <= n) {
		if (a[pos + k] == b[k]) {
			k++;
			if (k == m) ans.push_back(pos);
		}
		else {
			if (k == 0) pos++;
			else {
				pos += k - pi[k - 1];
				k = pi[k - 1];
			}
		}
	}
	return;
}

int GCD(int a, int b) {
	if (a > b) {
		if (a % b) return GCD(a % b, b);
		else return b;
	}
	else {
		if (b % a) return GCD(b % a, a);
		else return a;
	}
}