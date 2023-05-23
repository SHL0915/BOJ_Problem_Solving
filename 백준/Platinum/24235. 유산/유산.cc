#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
using pdd = pair<double, double>;

int N;
ll org;
pii arr[500005];
vector <pii> ch;

ll ccw(pii a, pii b, pii c);
pii sub(pii a, pii b);
double f(double a);
pdd cross(pii a, pii b, double x);

void solve() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i].first >> arr[i].second;
	sort(arr, arr + N);
	sort(arr + 1, arr + N, [&](pii a, pii b) {
		ll res = ccw(arr[0], a, b);
		if (res) return res > 0;
		else return a < b;
		});

	ch.push_back(arr[0]);
	ch.push_back(arr[1]);

	for (int i = 2; i < N; i++) {
		pii c = arr[i];
		while (ch.size() >= 2) {
			pii b = ch.back(); ch.pop_back();
			pii a = ch.back();
			if (ccw(a, b, c) > 0) {
				ch.push_back(b);
				break;
			}
		}
		ch.push_back(c);
	}

	double l = 1000000000, r = -1000000000;

	for (int i = 0; i < ch.size(); i++) {
		org += ch[i].first * ch[(i + 1) % ch.size()].second;
		org -= ch[i].second * ch[(i + 1) % ch.size()].first;
		l = min(l, (double)ch[i].first);
		r = max(r, (double)ch[i].first);
	}

	while (r - l > 0.0001) {
		double mid = (l + r) / 2;
		double res = f(mid);

		if (res * 2 >= org) r = mid;
		else l = mid;
	}

	cout << (l + r) / 2;
	return;
}

int main(void) {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed;
	cout.precision(9);
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}

ll ccw(pii a, pii b, pii c) {
	pii u = sub(b, a);
	pii v = sub(c, b);
	ll ret = u.first * v.second - u.second * v.first;
	if (ret) ret /= abs(ret);
	return ret;
}

pii sub(pii a, pii b) {
	return { a.first - b.first, a.second - b.second };
}

double f(double a) {
	vector <pdd> nch;
	nch.push_back(ch[0]);

	for (int i = 1; i < ch.size(); i++) {
		if (ch[i].first <= a) nch.push_back(ch[i]);
		else {
			if (ch[i - 1].first < a) nch.push_back(cross(ch[i], ch[i - 1], a));
			if (ch[(i + 1) % ch.size()].first < a) nch.push_back(cross(ch[i], ch[(i + 1) % ch.size()], a));
		}
	}

	double ret = 0;
	for (int i = 0; i < nch.size(); i++) {
		ret += nch[i].first * nch[(i + 1) % nch.size()].second;
		ret -= nch[i].second * nch[(i + 1) % nch.size()].first;
	}

	return ret;
}

pdd cross(pii a, pii b, double x) {
	double A = (double)(a.second - b.second) / ((double)(a.first - b.first));
	double B = (double)(a.second) - A * (double)(a.first);
	pdd ret = { x, A * x + B };
	return ret;
}