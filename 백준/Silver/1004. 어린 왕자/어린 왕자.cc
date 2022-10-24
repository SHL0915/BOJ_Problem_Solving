#include <iostream>
using namespace std;

int T;
int planet[50][3];

long long disSqr(int x1, int y1, int x2, int y2) {
	return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int check(int x1, int y1, int x2, int y2, int r) {
	if (disSqr(x1, y1, x2, y2) < r * r) return 1;
	else return 0;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--) {
		int x1, y1, x2, y2, N;
		cin >> x1 >> y1 >> x2 >> y2;
		cin >> N;
		int ans = 0;
		for (int i = 0; i < N; i++) {
			int A, B;
			cin >> planet[i][0] >> planet[i][1] >> planet[i][2];
			A = check(x1, y1, planet[i][0], planet[i][1], planet[i][2]);
			B = check(x2, y2, planet[i][0], planet[i][1], planet[i][2]);
			if (A + B == 1) ans++;
		}
		cout << ans << '\n';
	}
	return 0;
}