#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

struct coor {
	double x, y, z;
};

int N;
double D;
coor pvec;
coor plane[2];
coor arr[10005][2];

double dist(coor a, coor b);
coor product(coor a, coor b);
double sz(coor a);

void solve() {
	cin >> N >> D;
	for (int i = 0; i < 2; i++) cin >> plane[i].x >> plane[i].y >> plane[i].z;

	pvec = product(plane[0], plane[1]);
	 
	int cnt = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 2; j++) cin >> arr[i][j].x >> arr[i][j].y >> arr[i][j].z;

		coor star = { arr[i][0].x - D * arr[i][1].x, arr[i][0].y - D * arr[i][1].y, arr[i][0].z - D * arr[i][1].z };
		coor chk = product(plane[0], star);

		if (sz(product(pvec, chk)) > 0.1) continue;
		if (abs(sz(star) - D) > 0.1) continue;

		cnt++;
	}

	cout << cnt;
	return;
}

int main(void) {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}

double dist(coor a, coor b) {
	double dx = a.x - b.x;
	double dy = a.y - b.y;
	double dz = a.z - b.z;
	return sqrt(dx * dx + dy * dy + dz * dz);
}

coor product(coor a, coor b) {
	coor ret;
	ret.x = a.y * b.z - a.z * b.y;
	ret.y = a.z * b.x - a.x * b.z;
	ret.z = a.x * b.y - a.y * b.x;
	return ret;
}

double sz(coor a) {
	return sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
}