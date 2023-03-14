#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M;
int arr[200001];

int mark[1000001];
map <int, int> m;

void solve() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> arr[i];

	double a = (double)M * 9 / 10;
	int b;
	for (b = a; b < (double)a + 1; b++);
	b--;

	for (int i = 0; i < M; i++) m[arr[i]]++;

	for (auto i = m.begin(); i != m.end(); i++) {
		if ((*i).second >= b) {
			cout << "YES";
			return;
		}
	}
	
	for (int i = 1; i <= N - M; i++) {
		m[arr[i - 1]]--;
		m[arr[i + M - 1]]++;
		if (m[arr[i + M - 1]] >= b) {
			cout << "YES";
			return;
		}
	}

	cout << "NO";
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