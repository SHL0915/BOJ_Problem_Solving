#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

ll N, V;
ll T[200001];
ll A[200001];
vector <pii> arr;

void solve() {
	cin >> N >> V;
	for (int i = 0; i < N; i++) cin >> T[i];
	for (int i = 0; i < N; i++) cin >> A[i];
	for (int i = 0; i < N; i++) {
		if (abs(A[i]) > T[i] * V) continue;
		arr.push_back({ V * T[i] - A[i],V * T[i] + A[i] });
	}
	sort(arr.begin(), arr.end());

	vector <ll> v;
	for (int i = 0; i < arr.size(); i++) {
		if (v.size() == 0 || arr[i].second >= v.back()) v.push_back(arr[i].second);
		else {
			int idx = upper_bound(v.begin(), v.end(), arr[i].second) - v.begin();
			v[idx] = arr[i].second;
		}
	}

	cout << v.size();
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