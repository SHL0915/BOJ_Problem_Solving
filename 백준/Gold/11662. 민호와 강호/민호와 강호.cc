#include <iostream>
#include <cmath>
using namespace std;

int Ax, Ay, Bx, By, Cx, Cy, Dx, Dy;
double ans;

double sqrdist(double x1, double y1, double x2, double y2) {
	return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed;
	cout.precision(12);
	cin >> Ax >> Ay >> Bx >> By >> Cx >> Cy >> Dx >> Dy;
	double lptr = 0, rptr = 1;
	for (int i = 0; i < 1000000; i++) {
		double lpoint = (lptr * 2 + rptr) / 3;
		double rpoint = (lptr + rptr * 2) / 3;
		pair<double, double> lposA, lposB, rposA, rposB;
		lposA = { (Ax + (Bx - Ax) * lpoint), (Ay + (By - Ay) * lpoint) };
		lposB = { (Cx + (Dx - Cx) * lpoint), (Cy + (Dy - Cy) * lpoint) };
		rposA = { (Ax + (Bx - Ax) * rpoint), (Ay + (By - Ay) * rpoint) };
		rposB = { (Cx + (Dx - Cx) * rpoint), (Cy + (Dy - Cy) * rpoint) };
		double lresult = sqrdist(lposA.first, lposA.second, lposB.first, lposB.second);
		double rresult = sqrdist(rposA.first, rposA.second, rposB.first, rposB.second);
		ans = min(lresult, rresult);
		if (lresult <= rresult) rptr = rpoint;
		else lptr = lpoint;
	}
	cout << sqrt(ans);
	return 0;
}