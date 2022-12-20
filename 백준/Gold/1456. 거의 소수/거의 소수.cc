#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll A, B, ans;
ll table[10000006];
vector <ll> primeNum;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (ll i = 2; i <= 10000005; i++) {
		if (table[i] == 0) {
			primeNum.push_back(i);
			for (ll j = i * i; j <= 10000005; j += i) table[j] = 1;
		}
	}
	cin >> A >> B;
	for (int i = 0; i < primeNum.size(); i++) {
		ll now = primeNum[i];
		if (now * now > B) break;
		ll temp = now * now;
		while (temp <= B) {
			if (temp >= A) ans++;
			if (temp <= B / now) temp *= now;
			else break;
		}		
	}
	cout << ans;
	return 0;
}