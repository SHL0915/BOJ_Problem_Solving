#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N, T, ans;
pair<ll, ll> arr[1000];

ll BinarySearch(ll left, ll right);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> T;
	ll msum = 0, Msum = 0;
	for (int i = 0; i < N; i++) {
		cin >> arr[i].first >> arr[i].second;
		msum += arr[i].first;
		Msum += arr[i].second;
	}
	if (msum > T || Msum < T) {
		cout << -1;
		return 0;
	}
	ans = BinarySearch(0, 100000000000);
	ll flag = 0, sum = 0;
	for (int i = 0; i < N; i++) {
		if (arr[i].first > ans) {
			cout << -1;
			return 0;
		}
		sum += arr[i].first;
	}
	if (sum > T) cout << -1;
	else cout << ans;
	return 0;
}

ll BinarySearch(ll left, ll right) {
	if (left < right) {
		ll mid = (left + right) / 2;
		ll flag = 0, sum = 0;
		for (int i = 0; i < N; i++) {
			if (arr[i].first > mid) {
				flag = 1;
				break;
			}
			sum += min(mid, arr[i].second);
		}
		if (flag == 1) return BinarySearch(mid + 1, right);
		else {
			if (sum >= T) return BinarySearch(left, mid);
			else return BinarySearch(mid + 1, right);
		}
	}
	else return left;
}