#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, cnt;
int A[100001], B[100001], mark[100001];
set <int> s;

void solve() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];
	for (int i = 0; i < N; i++) {
		cin >> B[i];
		mark[B[i]] = i;
	}
	for (int i = 0; i < N; i++) {
		if (s.size() == 0) s.insert(mark[A[i]]);
		else {
			if ((*s.rbegin()) > mark[A[i]]) cnt++;
			s.insert(mark[A[i]]);
		}
	}
	cout << cnt;
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