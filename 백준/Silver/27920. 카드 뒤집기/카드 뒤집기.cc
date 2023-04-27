#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
int A[200001];
int B[200001];

void solve() {
	cin >> N;
	cout << "YES\n";
	for (int i = 0; i < N / 2; i++) A[i] = N - 1 - 2 * i;
	A[N / 2] = N;
	for (int i = 0; i < (N - 1) / 2; i++) A[N - 1 - i] = N - 2 - 2 * i;

	for (int i = 0; i < N; i++) cout << A[i] << " ";
	cout << '\n';

	for (int i = 0; i < N; i++) {
		if (i % 2 == 0) cout << i / 2 + 1 << " ";
		else cout << N - i / 2 << " ";
	}

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