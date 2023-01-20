#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

int N;
int table[10001];
vector <int> primeNum;

int absol(int a);

void solve() {
	cin >> N;
	int ans = INF;
	for (int i = 0; i < primeNum.size(); i++) {
		if (primeNum[i] > N) break;
		if (table[N - primeNum[i]]) continue;
		else ans = min(ans, absol(primeNum[i] - (N - primeNum[i])));		
	}
	cout << (N - ans) / 2 << " " << (N - ans) / 2 + ans << '\n';
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 2; i <= 10000; i++) {
		if (table[i] == 0) {
			primeNum.push_back(i);
			for (int j = i * i; j <= 10000; j += i) table[j] = 1;
		}
	}
	int t = 1;
	cin >> t;
	while (t--) solve();
	return 0;
}

int absol(int a) {
	if (a < 0) return -a;
	else return a;
}