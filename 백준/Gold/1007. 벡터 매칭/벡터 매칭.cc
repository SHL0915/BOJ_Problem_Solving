#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int T, N;
long long ansSqr;
pair <int, int> dot[20];
int mark[20];

void BackTracking(int k, int n);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed;
	cout.precision(12);
	cin >> T;
	while (T--) {
		cin >> N;
		ansSqr = -1;
		for (int i = 0; i < N; i++) {
			int x, y;
			cin >> x >> y;
			dot[i] = { x,y };
			mark[i] = 0;
		}
		BackTracking(0, 0);
		cout << sqrt((double)ansSqr) << '\n';
	}
	return 0;
}

void BackTracking(int k, int n) {
	if (n == N / 2) {
		long long sX = 0, sY = 0, eX = 0, eY = 0;
		for (int i = 0; i < N; i++) {
			if (mark[i] == 0) {
				sX += dot[i].first;
				sY += dot[i].second;
			}
			else {
				eX += dot[i].first;
				eY += dot[i].second;
			}
		}
		long long disSqr = (eX - sX) * (eX - sX) + (eY - sY) * (eY - sY);
		if (ansSqr == -1) ansSqr = disSqr;
		else ansSqr = min(ansSqr, disSqr);
		return;
	}
	if (k == N) return;
	else {
		BackTracking(k + 1, n);
		mark[k] = 1;
		BackTracking(k + 1, n + 1);
		mark[k] = 0;
	}
}