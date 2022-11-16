#include <iostream>
#include <cmath>
using namespace std;

double x, y, c, ans;

double func(double A, double B) {
	return A * A - B * B;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed;
	cout.precision(12);
	cin >> x >> y >> c;
	double left = 0;
	double right = min(x, y);
	for (int i = 0; i < 1000000; i++) {
		double mid = (left + right) / 2;
		double x1 = (mid * c) / sqrt(func(x, mid));
		double x2 = (mid * c) / sqrt(func(y, mid));
		if (x1 + x2 >= mid) right = mid;
		else left = mid;
		ans = mid;
	}
	cout << ans;
	return 0;
}