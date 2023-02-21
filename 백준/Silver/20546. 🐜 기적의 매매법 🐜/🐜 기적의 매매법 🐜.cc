#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
int arr[15];
int a_money, a_cnt, b_money, b_cnt;

void solve() {
	cin >> N;
	a_money = N; b_money = N;
	for (int i = 1; i <= 14; i++) {
		cin >> arr[i];
		a_cnt += a_money / arr[i];
		a_money %= arr[i];
		if (i >= 4) {
			if (arr[i - 3] < arr[i - 2] && arr[i - 2] < arr[i - 1] && arr[i - 1] < arr[i]) {
				b_money += b_cnt * arr[i];
				b_cnt = 0;
			}
			else if (arr[i - 3] > arr[i - 2] && arr[i - 2] > arr[i - 1] && arr[i - 1] > arr[i]) {
				b_cnt += b_money / arr[i];
				b_money %= arr[i];
			}
		}
	}
	int a_val, b_val;
	a_val = arr[14] * a_cnt + a_money;
	b_val = arr[14] * b_cnt + b_money;

	if (a_val > b_val) cout << "BNP";
	else if (a_val == b_val) cout << "SAMESAME";
	else cout << "TIMING";
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