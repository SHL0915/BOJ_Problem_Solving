#include <iostream>
#include <cmath>
using namespace std;

struct dot {
	double x, y, z;
};

dot A, B, C;
double ans;

void input();
double sqrdis(dot a, dot b) {
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) + (a.z - b.z) * (a.z - b.z);
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed;
	cout.precision(12);
	input();
	for (int i = 0; i < 1000000; i++) {
		dot left, right;
		left = { (A.x * 2 + B.x) / 3, (A.y * 2 + B.y) / 3 , (A.z * 2 + B.z) / 3 };
		right = { (B.x * 2 + A.x) / 3, (B.y * 2 + A.y) / 3 , (B.z * 2 + A.z) / 3 };
		double distLeft = sqrdis(left, C);
		double distRight = sqrdis(right, C);
		if (distLeft < distRight) B = right;
		else A = left;
		ans = min(distLeft, distRight);
	}
	cout << sqrt(ans);
	return 0;
}

void input() {
	double x, y, z;
	cin >> x >> y >> z;
	A = { x,y,z };
	cin >> x >> y >> z;
	B = { x,y,z };
	cin >> x >> y >> z;
	C = { x,y,z };
}