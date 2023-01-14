#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, K;
int table[5000001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (ll i = 2; i <= 5000000; i++) {
		if (table[i] == 0) {
			for (ll j = i; j <= 5000000; j += i) if (table[j] == 0) table[j] = i;
		}
	}
	cin >> N;
	while (N--) {
		cin >> K;		
		while (1) {
			if (table[K] == K) {
				cout << K << '\n';
				break;
			}
			cout << table[K] << " ";
			K /= table[K];
		}
	}
	return 0;
}