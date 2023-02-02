#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
const double pi = 3.141592653589793238462643383;

ll N, R;
pii arr[1001];

bool cmp(pii a, pii b);
ll CCW(pii a, pii b, pii c);
pii sub(pii a, pii b);
double dist(pii a, pii b);

void solve() {
	cin >> N >> R;
	for (int i = 0; i < N; i++) cin >> arr[i].first >> arr[i].second;
	sort(arr, arr + N);
	sort(arr + 1, arr + N, cmp);
	vector <pii> v;
	v.push_back(arr[0]);
	v.push_back(arr[1]);
	for (int i = 2; i < N; i++) {
		pii c = arr[i];
		while (v.size() >= 2) {
			pii b = v.back();
			v.pop_back();
			pii a = v.back();
			if (CCW(a, b, c) >= 0) {
				v.push_back(b);
				break;
			}
		}
		v.push_back(c);
	}
	double ans = 0;
	for (int i = 1; i < v.size(); i++) ans += dist(v[i], v[i - 1]);
	ans += dist(v[0], v[v.size() - 1]);
	ans += 2 * R * pi;
	cout << ans;
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed;
	cout.precision(12);
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}

bool cmp(pii a, pii b) {
	ll ccw = CCW(arr[0], a, b);
	if (ccw) return ccw > 0;
	else return a < b;
}

ll CCW(pii a, pii b, pii c) {
	pii u = sub(b, a), v = sub(c, b);
	ll ret = u.first * v.second - u.second * v.first;
	if (ret) ret /= abs(ret);
	return ret;
}

pii sub(pii a, pii b) {
	return { a.first - b.first , a.second - b.second };
}

double dist(pii a, pii b) {
	ll dx = a.first - b.first;
	ll dy = a.second - b.second;
	return sqrt(dx * dx + dy * dy);
}