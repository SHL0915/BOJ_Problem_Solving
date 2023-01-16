#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, ans = 1;
vector <int> prime;
vector <pii> primeFact;

int pow(int a, int b);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;	
	for (int i = 2; i * i <= N; i++) {
		if (N % i == 0) {
			int cnt = 0;
			prime.push_back(i);
			primeFact.push_back({ i, 0 });
			while (1) {
				if (N % i) break;
				N /= i;
				cnt++;
			}
			primeFact.back().second = cnt;
		}
	}
	if (N != 1) {
		prime.push_back(N);
		primeFact.push_back({ N,1 });
	}
	for (int i = primeFact.size() - 1; i >= 0; i--) {
		pii now = primeFact[i];
		if (now.second == 0) continue;
		if (now.second < 0 || now.second % 2 == 0) {
			cout << -1;
			return 0;
		}
		int n = (now.second + 1) / 2;
		ans *= pow(now.first, n);
		int temp = now.first - 1;
		for (int j = 2; j * j <= temp; j++) {			
			if (temp % j == 0) {				
				int cnt = 0;
				while (1) {
					if (temp % j) break;
					temp /= j;
					cnt++;
				}
				if (binary_search(prime.begin(), prime.end(), j)) {
					int idx = lower_bound(prime.begin(), prime.end(), j) - prime.begin();
					primeFact[idx].second -= cnt;
				}
				else {
					cout << -1;
					return 0;
				}
			}		
		}
		if (temp != 1) {
			if (binary_search(prime.begin(), prime.end(), temp)) {
				int idx = lower_bound(prime.begin(), prime.end(), temp) - prime.begin();
				primeFact[idx].second --;
			}
			else {
				cout << -1;
				return 0;
			}
		}
	}
	cout << ans;
	return 0;
}

int pow(int a, int b) {
	int ret = 1;
	for (int i = 0; i < b; i++) ret *= a;
	return ret;
}