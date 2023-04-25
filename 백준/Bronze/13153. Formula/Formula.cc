#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<double, double>;

pii A, B, C;
double R;

double sqr(double a);
double dist(pii a, pii b);

void solve() {
	cin >> A.first >> A.second;
	cin >> B.first >> B.second;
	cin >> C.first >> C.second;
	cin >> R;

	double a = dist(A, B);
	double b = dist(B, C);
	double c = dist(A, C);

	double r = 2 / (4 * (a + b + c)) * sqrt(4 * sqr(a) * sqr(b) - sqr(sqr(a) + sqr(b) - sqr(c)));

	cout << (r - R) / R * 100;
	return;
}

int main(void) {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed;
	cout.precision(8);
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}

double sqr(double a) {
	return a * a;
}

double dist(pii a, pii b) {
	double dx = a.first - b.first;
	double dy = a.second - b.second;
	return sqrt(sqr(dx) + sqr(dy));
}