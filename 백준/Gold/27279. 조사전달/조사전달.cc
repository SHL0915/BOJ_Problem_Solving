#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M;
int arr[100001];
int psum[100001];

void solve() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int a; cin >> a;
		psum[M - a] ++;
	}
	for (int i = 0; i < M; i++) if (i) psum[i] += psum[i - 1];	
	for (int i = 0; i < M; i++) cin >> arr[i];	
	sort(arr, arr + M, greater<>());
	for (int i = 0; i < M; i++) if (i) arr[i] += arr[i - 1];
	for (int i = 0; i < M; i++) {
		if (arr[i] > psum[i]) {
			cout << "NO";
			return;
		}
	}
	cout << "YES";
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}