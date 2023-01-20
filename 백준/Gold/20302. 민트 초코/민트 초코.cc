#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
int table[100001];
vector <int> primeNum;
int cnt[100001];

void primeFact(int num, int mode);

void solve() {
	cin >> N;
	int num;
	char c;
	cin >> num;
	if (num < 0) num *= -1;
	primeFact(num, 1);
	for (int i = 0; i < N - 1; i++) {
		cin >> c >> num;
		if (num < 0) num *= -1;
		if (c == '*') primeFact(num, 1);
		else primeFact(num, -1);
	}
	int flag = 0;
	for (int i = 0; i <= 100000; i++) {
		if (cnt[i] < 0) flag = 1;
	}
	if (cnt[0] > 0) cout << "mint chocolate";
	else if (flag) cout << "toothpaste";
	else cout << "mint chocolate";
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (ll i = 2; i <= 100000; i++) {
		if (table[i] == 0) {
			primeNum.push_back(i);
			for (ll j = i * i; j <= 100000; j += i) table[j] = 1;
		}
	}
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}

void primeFact(int num, int mode) {
	for (int i = 0; i < primeNum.size(); i++) {
		ll now = primeNum[i];
		if (now * now > num) break;
		if (num % now == 0) {
			while (1) {
				if (num % now) break;
				num /= now;
				cnt[now] += mode;
			}
		}
	}
	if (num != 1) cnt[num] += mode;
	return;
}