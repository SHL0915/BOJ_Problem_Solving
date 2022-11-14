#include <iostream>
using namespace std;

pair<int, int> P[3];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 0; i < 3; i++) {
		int x, y;
		cin >> x >> y;
		P[i] = { x,y };
	}
	int A = (P[1].second - P[0].second) * (P[2].first - P[1].first);
	int B = (P[2].second - P[1].second) * (P[1].first - P[0].first);
	if (A < B) cout << 1;
	else if (A == B) cout << 0;
	else cout << -1;
	return 0;
}