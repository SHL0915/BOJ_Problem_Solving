#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;

void solve() {
	int sum = 0;
	vector <int> arr;
	for (int i = 1; i <= N - 1; i++) {
		if (N % i == 0) {
			sum += i;
			arr.push_back(i);
		}
	}
	if (sum == N) {
		cout << N << " = ";
		for (int i = 0; i < arr.size() - 1; i++) cout << arr[i] << " + ";
		cout << arr.back() << '\n';
	}
	else cout << N << " is NOT perfect.\n";
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
	while (1) {
		cin >> N;
		if (N == -1) break;
		solve();
	}
	return 0;
}