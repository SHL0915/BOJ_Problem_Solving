#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int A, B;
ll tot;

ll cal(ll a);
ll findTot(ll left, ll right);
ll BinarySearch(ll left, ll right);

void solve() {
	while (1) {
		cin >> A >> B;
		if (A == 0 && B == 0) break;
		tot = findTot(0, A);
		cout << cal(BinarySearch(0, tot)) << '\n';
	}
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

ll cal(ll a) {
	ll ret = 0;
	ret += 2 * min(100LL, max(0LL, a));
	a -= 100;
	ret += 3 * min(9900LL, max(0LL, a));
	a -= 9900;
	ret += 5 * min(990000LL, max(0LL, a));
	a -= 990000;
	ret += 7 * max(0LL, a);
	return ret;
}

ll findTot(ll left, ll right) {
	if (left < right) {
		ll mid = (left + right) / 2;
		if (cal(mid) > A) return findTot(left, mid - 1);
		else if (cal(mid) == A) return mid;
		else return findTot(mid + 1, right);
	}
	else return left;
}

ll BinarySearch(ll left, ll right) {
	if (left < right) {
		ll mid = (left + right) / 2;
		ll a = cal(mid);
		ll b = cal(tot - mid);
		if (b - a > B) return BinarySearch(mid + 1, right);
		else if (b - a == B) return mid;
		else return BinarySearch(left, mid - 1);
	}
	else return left;
}