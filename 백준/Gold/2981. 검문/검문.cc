#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
int arr[101];

tuple<ll, ll, ll> EEu(ll a, ll b);

void solve() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	sort(arr, arr + N);
	for (int i = 1; i < N; i++) arr[i] -= arr[0];
	ll ans = arr[1];
	for (int i = 1; i < N; i++) ans = get<0>(EEu(ans, arr[i]));	
	vector <ll> v;
	for (ll i = 1; i * i <= ans; i++) {
		if (ans % i == 0) {
			v.push_back(i);
			v.push_back(ans / i);
		}
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for (int i = 1; i < v.size(); i++) cout << v[i] << " ";
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

tuple<ll, ll, ll> EEu(ll a, ll b) {
	if (b == 0) return { a, 1, 0 };
	ll g, x, y;
	tie(g, x, y) = EEu(b, a % b);
	return { g,y,x - a / b * y };
}