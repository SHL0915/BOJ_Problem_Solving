#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N, M, ans;
vector <pair<ll, ll>> arr;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		ll a, b;
		cin >> a >> b;
		if (a > b) arr.push_back({ b,a });
	}
	sort(arr.begin(), arr.end());
	if (arr.size() == 0) {
		cout << M;
		return 0;
	}
	ans = M;	
	pair<ll, ll> now = arr[0];
	for (int i = 1; i < arr.size(); i++) {
		if (arr[i].first <= now.second) {
			now.first = min(now.first, arr[i].first);
			now.second = max(now.second, arr[i].second);
		}
		else {
			ans += (now.second - now.first) * 2;
			now = arr[i];
		}
	}
	ans += (now.second - now.first) * 2;
	cout << ans;
	return 0;
}